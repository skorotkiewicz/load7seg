#include <Wire.h>
#include "LedControl.h"
#define SLAVE_ADDRESS 0x08
LedControl lc=LedControl(12,11,10,1);

int i = 8;
char data_recieved_from_pi = "";

void setup() {
  Wire.begin(SLAVE_ADDRESS);

  Wire.onReceive(receiveData);
//  Wire.onRequest(sendData);

  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
}

void loop() {}

void receiveData(int byteCount) {
  i = 8;
  lc.clearDisplay(0);

  while( Wire.available()) {
//    data_recieved_from_pi += (char)Wire.read();
    data_recieved_from_pi = (char)Wire.read();
    lc.setChar(0,i,(char)data_recieved_from_pi,false);
    i--;
  }
}