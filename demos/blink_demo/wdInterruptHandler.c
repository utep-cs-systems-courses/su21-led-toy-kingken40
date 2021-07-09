#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (blink_count == 250) {
    red_toggle_on(); /* turn both on to have both flash every second */
    green_toggle_on();
    blink_count = 0;
    red_toggle_off();
    green_toggle_off();
  }
  else if(blink_count <= 250){
    red_toggle_off();
    green_toggle_off();
    blink_count++;
  }
}
