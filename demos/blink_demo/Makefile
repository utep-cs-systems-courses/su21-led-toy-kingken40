# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: run.elf 


#Button
blink.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o switches.o blinkMain.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

run.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o buzzer.o blinkMain.o switches.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: blink.elf
	msp430loader.sh blink.elf

load2: run.elf
	msp430loader.sh run.elf
clean:
	rm -f *.o *.elf

switches.o: switches.h

led.o: led.c led.h

buzzer.o: buzzer.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
