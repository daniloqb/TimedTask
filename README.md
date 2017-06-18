# TimedTask
A Simple way to use Concurrent Functions with Arduino-like microcontrollers.


*Concurrent Execution, Fake Thread, Timed Action, Timed Functions, this is some of what this code could be called.*

Arduino don't have threads, so we need some tricks to do some fake paralalel executions.

This library help us to not need use delay function in our code. See how it works.

## How to use TimedTask

1 - Download the zip file. On Arduino IDE, include the library through *Sketch>Include Library>Add .zip file.*


2 - Include the Library.

```c++
#include <TimedTask.h>
```

3 - Create a **void function** that will be executed.

```c++
void valar_morgulis(){
  Serial.println("Valar Morgulis");
}

void valar_dohaeris(){
  Serial.println("Valar Dohaeris");
}
```

3 - Now, create one **TimedTask object** for each void function that you want to control.

The parameters are:
 - void function that you want to control.
 - time period in miliseconds. This is the frequency of your function execution.

```c++
TimedTask m = TimedTask(valar_morgulis,2000); // function valar_morgulis() running every 02 seconds 
TimedTask d = TimedTask(valar_dohaeris,3000); // function valar_dohaeris() running every 03 seconds 

```

4 - In the loop() function, you need to call **run()** for your task to be executed.

```c++
  m.run();
  d.run();
```


### This is the basic functionality.

There are more examples how to use all the functionalities of the library. See the examples sketches.



# Other Functionalities


* Enable or disable a task

Use **active()** function. Without parameter this function returns the task state. To Enable or Disable the task, you need to pass, **true** or **false**.

```c++
task.active(); //returns the task state

task.active(false); // make the function execution stops.
task.active(true);  ;; function returns to it's normal execution.

```

* Change the frequency of execution

Use **interval()**. Without parameter this functions returns the actual interval of execution. Set the function interval, passing a **long** as parameter.

```c++
task.interval(); // returns the current interval of a function.

task.interval(2000); // set the frequency of execution to 2s.

```

* Limiting the number of execution of a task.

It is possible to limit  the number of execution of a task. Using the function **iterations()** its possible to see the number of remaining executions of that function, or to set the number of iterations. Its possible to disable the iterations, and go back to normal execution.

```c++
  task.iterations();  // return the number of remaining iterations of a function.
  
  task.iterations(10); // set to 10 the number of execution of a task

  task.disable_iterations(); // disable the limited number of iterations. Use iterations(), to active again.
```
