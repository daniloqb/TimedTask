
/*
 * limited_iterations.ino
 * 
 * Created by Danilo Queiroz Barbosa, June 18, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * TimedTask Library 
 * A Simple way to use concurrent tasks.
 * 
 * 
 * This examples show how to use TimedTask to execute a function with limited iterations
 */

#include <TimedTask.h>

boolean ledstate;

/* 
 * This functions make a blink led without delay  
 */


void blink(){
  ledstate = !ledstate;
  digitalWrite(LED_BUILTIN,ledstate);
}

/*
 * Creation of the tasks 
 */


TimedTask led   = TimedTask(blink,500);           // Blink a led every half a second  

void setup() {

  Serial.begin(9600);
  
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

  led.iterations(30);
}

void loop() {

  /*
   * Call run on every task to execute the function
   */
  led.run();

  /*
   * Show the number of iterations remaining using iterations() function.
   */
  if (led.iterations() > 0){
    Serial.print( "Iterations: ");
    Serial.println(led.iterations());
  }

  /*
   * If iterations is 10, change the blink rate using interval() function. 
   */
  if (led.iterations() == 10){
    led.interval(100);
  }

}
