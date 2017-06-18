/*
 * TimedTask,h
 * 
 * Created by Danilo Queiroz Barbosa, June 18, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * Header of the class TimedTask 
 * A Simple way to use concurrent tasks.
 * 
 */


#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include "Arduino.h"




class TimedTask {


  private:
    long _iterations;
    boolean _active;
    boolean _check_iterations;
    unsigned long _interval;
    unsigned long _previous_run;
    void (*_function)();    
    void check_iterations();

  public:
    TimedTask(void (*func)(), unsigned long interval_);
    void run();
    void disable_iterations();
    boolean active();
    boolean active(boolean act);
    unsigned long interval();
    unsigned long interval(unsigned long interval_);
    long iterations();
    long iterations(long iter);

};


#endif
