//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Definition of the functions surrounding the pump object
#include <Arduino.h>
#include "flowrate.hpp"
#include "pump.hpp"

pump p = pump(1.2f, minute, 2, false);
;

void setup()
{
  //p = pump(1.2f, minute, 2, false);
  Serial.begin(9600);
  p.printConfig();
}

void loop()
{
  //p.timedToggle(5000);

  // put your main code here, to run repeatedly:
}