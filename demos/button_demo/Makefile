# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o wdInterruptHandler.o buttonMain.o stateMachines.o  ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

wdInterruptHandler.o: stateMachines.h
switches.o: switches.h
stateMachines.o: led.h stateMachines.h
led.o: led.c led.h



load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf

