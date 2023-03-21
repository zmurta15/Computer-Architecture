#include <stdio.h>
#include <stdlib.h>

/*
Using:
 - CPU with 32 bits for virtual addresses and real addresses 
 - pages with 8KB (2^13) 
 - so maximum page table size is 2^32/2^13=2^19 (512K) entries
*/
#define PAGESIZE (8*1024)	 // 8KBytes
#define MAX_VIRTUAL_PAGES (512*1024)
#define OFFSET_BITS 13

/* Page table
 * inicialised with pagetable file content
 */
unsigned int pageTable[MAX_VIRTUAL_PAGES];  // not all entries need to be in use
unsigned int ptSize = 0;  // size of loaded page table

// statistics:
int count=0;     // memory access counter


/* reads page table entries from text file */
void initPT( FILE *f ) {
    unsigned frame;
    while (fscanf(f, "%x", &frame ) == 1) {
        pageTable[ptSize] = frame;
        ptSize++;
    }
    printf("Page table size: %d\n", ptSize);
}

/* translate virtual address to real address using pageTable */
unsigned int translateOneAddr(unsigned int addr) {
    int page;
    int frame;
    int realAddress=0;
    // TODO
	int offset;
	page=addr/PAGESIZE;
	frame = pageTable[page];
	offset = addr % PAGESIZE;
	realAddress = frame *PAGESIZE + offset;
    return realAddress;
}

/* simulate all memory acesses with translation from virtual address to real address */
void simulateAllTheSteps(FILE *tf) {
    unsigned Vaddr, Raddr;
    char rw;

    while (fscanf(tf, "%x %c", &Vaddr, &rw) == 2) {
        Raddr = translateOneAddr(Vaddr); // translate vitual addr
        printf("%x\n", Raddr);  // print real address
        count++;
    }
}


/************* MAIN **************/

int main(int argc, char *argv[]) {
    FILE *traceFile;
    FILE *tableFile;
    char *prog = argv[0];

    if (argc != 3) {
        // needs two arguments in command line (besides command name)
        printf("%s pagetable memtrace\n", prog);
        return 1;
    }
    if ((tableFile = fopen(argv[1], "r")) == NULL) {
        printf("pagetable-file '%s' error\n", argv[1]);
        exit(1);
    }
    if ((traceFile = fopen(argv[2], "r")) == NULL) {
        printf("Trace-file '%s' error\n", argv[2]);
        exit(1);
    }

    /* do it */
    initPT(tableFile);  // load page table
    simulateAllTheSteps(traceFile);
    
    printf("Memory accesses: %d\n", count );
    return 0;
}
