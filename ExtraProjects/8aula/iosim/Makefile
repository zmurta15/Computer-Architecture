
CFLAGS += -g -std=c11 -Wall
CC = cc

SRC = main.c driver.c hw.c
TARGET = main


$(TARGET):	$(SRC:%.c=%.o)
	$(CC) -o $@  $^ -pthread

teste:	teste.c driver.c hw.c
	$(CC) -o $@  $^ -pthread

clean:
	rm -f $(TARGET) teste $(SRC:%.c=%.o) $(SRC:%.c=%.d) *~ *.bak Makefile.deps


#deps:
#	makedepend -Y -f Makefile.deps -- $(CFLAGS) -- $(SRC)

driver.o: hw.h driver.h
hw.o: hw.h
main.o: hw.h

