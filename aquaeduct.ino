#include <Arduino.h>
#include "pump.hpp"

pump p = pump(1.2f, minute, 2, false);
;

void setup()
{
  //p = pump(1.2f, minute, 2, false);
  Serial.begin(9600);
  Serial.println(p.toString());
}

void loop()
{
  //p.timedToggle(5000);

  // put your main code here, to run repeatedly:
}