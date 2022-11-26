#ifndef CLUB_ROBOT_H
#define CLUB_ROBOT_H
#include <Arduino.h>

void robotInit();
void attachRC(int interruptPin, int *resArr);
void readRC();
void forward(int val);
void backward(int val);
void leftForward(int val);
void rightForward(int val);
void leftBackward(int val);
void rightBackward(int val);
void motorStop();
void rightStop();
void leftStop();

#endif
