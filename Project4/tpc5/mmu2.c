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

#define MAX_TLB   1024    // maximum TLB size that can be simulated
#define PAGE  0   // 1st line in TLBpage with virtual page numbers
#define FRAME 1   // 2nd line in TLBpage with real frame numbers

/* simulated TLB is like a fully associative cache */
int TLBvalid[MAX_TLB];            // is entry valid? 0 or 1
unsigned int TLBpage[2][MAX_TLB]; // virtual page number -> frame number

// TLB size to use in simulation
int TLBsize;

int nextToTLB=0;  // index were to add a new entry to TLB (to get FIFO policy)

// statistics:
int hitTLB=0;    // TLB hits
int count=0;     // memory access counter


/* sets TLB size to use in simulation */
void initTLB( int tlbsize ) {
    if ( tlbsize>MAX_TLB ) {
        fprintf(stderr,"TLB size to big!\n");
        exit(2);
    }
    TLBsize = tlbsize;
}

/* add page + frame pair to TLB at index position */
void addTLB( int index, int page, int frame ) {
    TLBpage[PAGE][index] = page;
    TLBpage[FRAME][index] = frame;
    TLBvalid[index] = 1;
}


/* reads page table entries from text file */
void initPT( FILE *f ) {
    unsigned frame;
    while (fscanf(f, "%x", &frame ) == 1) {
        pageTable[ptSize] = frame;
        ptSize++;
    }
    printf("Page table size: %d\n", ptSize);
}


/* find page in TLB and return its frame if found or -1 in not found */
int findInTLB( int page ) {
    // TODO
	while()
	

}


/* translate virtual address into real address using TLB or, 
 * in not in TLB, using page table (and updating TLB)
 */
unsigned int translateOneAddr(unsigned int addr) {
    int page;
    int frame;
    int realAddress=0;
    // TODO
	// increment hitTLB at each TLB hit
           
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
    initTLB(32); // simulate a TLB with just 32 entries
    initPT(tableFile);  // load page table
    simulateAllTheSteps(traceFile);
    
	printf("Memory accesses: %d\n", count );
    printf("TLB hits: %d (%g%%)\n", hitTLB, 100*hitTLB/(double)count);
    return 0;
}
