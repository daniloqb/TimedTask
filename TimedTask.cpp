/*
 * TimedTask.cpp
 * 
 * Created by Danilo Queiroz Barbosa, June 18, 2017.
 * Member of electronicdrops.com
 * 
 * 
 * Implementation of the class TimedTask 
 * A Simple way to use concurrent tasks.
 * 
 */




#include "Arduino.h"
#include "TimedTask.h"



TimedTask::TimedTask(void (*func)(), unsigned long interval_) {

  _interval = interval_;
  _function = func;
  _previous_run = 0;
  _active = 1;
  _iterations = -1;
  _check_iterations = false;

}

void TimedTask::run() {
  unsigned long current_run = millis();


  if (_active) {
    if (current_run - _previous_run > _interval) {
      check_iterations();
      _function();
      _previous_run = current_run;
    } else {
      if (current_run < _previous_run) {
        _previous_run = 0xFFFFFFFF - _previous_run;
      }
    }
  }
}

boolean TimedTask::active() {
  return _active;
}

boolean TimedTask::active(boolean act) {
  _active = act;
}

unsigned long TimedTask::interval() {
  return _interval;
}

unsigned long TimedTask::interval(unsigned long interval_) {
  _interval = interval_;
  return _interval;
}

long TimedTask::iterations() {
  return _iterations;
}

long TimedTask::iterations(long iter) {

  _iterations = iter;
  _check_iterations = true;
}

void TimedTask::check_iterations() {

  if (_check_iterations) {
    if (_iterations > 0) {
      _iterations--;

    }
    if (_iterations == 0) {
      active(false);
      }
  }
}

void TimedTask::disable_iterations() {
  _check_iterations = false;
  _iterations = -1;
}
