#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}
 
char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

char interruptTime;

void state_advance(){
  if(switch_state_down_1){
    interruptTime = 0;
    red_toggle_on();
  }
  else if(switch_state_down_2){
    interruptTime = 2;
    red_toggle_on();
  }
  else if(switch_state_down_3){
    interruptTime = 0;
    red_toggle_on();
    red_toggle_off();
  }
  else if(switch_state_down_4){
    green_toggle_off();
  }
}

void red_toggle_on(){
  green_on = 1;
  led_changed = 1;
  led_update();
}

void red_toggle_off(){
  green_on = 0;
  led_changed = 1;
  led_update();
}

void green_toggle_on(){
  red_on = 1;
  led_changed = 1;
  led_update();
}

void green_toggle_off(){
  red_on = 0;
  led_changed = 1;
  led_update();
}

