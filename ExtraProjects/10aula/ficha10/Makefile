
## flag de optimizacao do compilador: -O2
CFLAGS = -Wall -std=c99 

.PHONY: mountain

PROGS = cpuid transposta

all:	$(PROGS) mountain

mountain:	
	cd mountain && make

clean:
	rm -f $(PROGS)  *.o *~
	cd mountain && make clean


