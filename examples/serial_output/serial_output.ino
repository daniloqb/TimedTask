
/*
 * serial_output.ino
 * 
 * Created by Danilo Queiroz Barbosa, June 18, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * TimedTask Library 
 * A Simple way to use concurrent tasks.
 * 
 * 
 * This examples show how to use TimedTask to Send Messages to Serial.
 * 
 */

#include <TimedTask.h>


/* 
 *  void functions that send messages to Serial
 */

void valar_morgulis(){
  Serial.println("Valar Morgulis");
}

void valar_dohaeris(){
  Serial.println("Valar Dohaeris");
}


void hello_world(){
  Serial.println("Hello World!");
}



/* 
 * This functions make a blink led without delay  
 */
 
boolean ledstate;

void blink(){
  ledstate = !ledstate;
  digitalWrite(LED_BUILTIN,ledstate);
}

/*
 * Creation of the tasks 
 */

TimedTask m = TimedTask(valar_morgulis,2000); // function valar_morgulis() running every 02 seconds 
TimedTask d = TimedTask(valar_dohaeris,3000); // function valar_dohaeris() running every 03 seconds 
TimedTask h = TimedTask(hello_world,1000);    // function hello_world() running every 01 seconds 
TimedTask b = TimedTask(blink,500);           // Blink a led every half a second  

void setup() {
  
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);

}

void loop() {

  /*
   * Call run on every task to execute the function
   */
  m.run();
  d.run();
  h.run();
  b.run();

}
