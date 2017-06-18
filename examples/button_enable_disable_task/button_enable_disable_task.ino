
/*
 * button_enable_disable_task.ino
 * 
 * Created by Danilo Queiroz Barbosa, June 18, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * TimedTask Library 
 * A Simple way to use concurrent tasks.
 * 
 * 
 * This examples show how to use TimedTask to read a button and enable or disable a Task
 */

#include <TimedTask.h>

boolean ledstate;
boolean toggle;
int btn_pin = 2;



/* 
 * This functions make a blink led without delay  
 */


/*
 * Function that read the btn_pin and change toggle value if button is LOW
 */
void btn_read(){
  if (digitalRead(btn_pin) == LOW){
    toggle = !toggle;
  }
}

/*
 * function that blink the led
 */

void blink(){
  ledstate = !ledstate;
  digitalWrite(LED_BUILTIN,ledstate);
}

/*
 * Creation of the tasks 
 */


TimedTask led   = TimedTask(blink,500);           // Blink a led every half a second  
TimedTask btn = TimedTask(btn_read,500);          // This task reads btn_pin every half a second

void setup() {
 
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

  pinMode(btn_pin, INPUT_PULLUP);

  toggle = led.active();

}

void loop() {

  /*
   * Call run on every task to execute the function
   */
  btn.run();
  led.run();

  if (led.active() != toggle){
    led.active(toggle);
  }

}
