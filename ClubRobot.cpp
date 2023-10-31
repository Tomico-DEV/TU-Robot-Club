#include "ClubRobot.h"

#define L1 3 //left
#define L2 5
#define R1 6 //right
#define R2 9
#define ARR_LENGTH 15

unsigned long int peak1, peak2, delta;
int tempStore[ARR_LENGTH], deltaStore[ARR_LENGTH], pinNo;
int* chRes;

// original rc code taken from here - https://projecthub.arduino.cc/abhilashpatel121/reading-rc-receiver-ppm-signal-using-arduino-63de0c
void robotInit() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void take_delta()  {
  peak1 = micros();
  delta = peak1 - peak2;
  peak2 = peak1;
  tempStore[pinNo] = delta;
  ++pinNo;
  if (pinNo == ARR_LENGTH)
  {
    for (int j = 0; j < ARR_LENGTH; ++j)
    {
      deltaStore[j] = tempStore[j] + 12;
    }
    pinNo = 0;
  }
}

void attachRC(int interruptPin, int* resArr) {
  chRes = resArr;
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), take_delta, RISING);
}

void readRC() {
  int i, j, k = 0;
  for(k = 14 ; k > -1; --k)
  {
    if (deltaStore[k] > 10000)
    {
      j = k;
    }
  }  //detecting separation space 10000us in that another array
  for(i = 0; i < 6; ++i)
  {
    chRes[i] = (deltaStore[1 + i + j] - 1000);
  }
}

void leftForward(int val) {
  analogWrite(L1, val);
  analogWrite(L2, 0);
}

void leftBackward(int val) {
  analogWrite(L1, 0);
  analogWrite(L2, val);
}

void rightForward(int val) {
  analogWrite(R1, val);
  analogWrite(R2, 0);
}

void rightBackward(int val) {
  analogWrite(R1, 0);
  analogWrite(R2, val);
}


void forward(int val) {
  leftForward(val);
  rightForward(val);
}

void motorStop() {
  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}

void rightStop() {
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}

void leftStop() {
  analogWrite(L1, 0);
  analogWrite(L2, 0);
}

void backward(int val) {
  leftBackward(val);
  rightBackward(val);
}
