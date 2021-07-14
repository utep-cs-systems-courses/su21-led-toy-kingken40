#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
   if (blink_count == interruptTime) {
     state_advance();
     blink_count = 0;
   }
  else if(blink_count <= interruptTime){
    red_toggle_off();
    green_toggle_off();
    blink_count++; 
  }
}
