//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Declaration of the pump object
#pragma once
#include <Arduino.h>
#include <string>
#include "flowrate.hpp"

class pump
{
private:
    flowrate m_flowrate{0.0, second};
    int m_pin{0};
    //pumps might be supposed to be on by default
    bool m_is_active{false};

    float normalizedFlowrate();

public:
    pump(flowrate throughput, int pin, bool is_active);
    pump(float throughput, time_unit unit, int pin, bool is_active);
    ~pump();
    void togglePump();
    void timedToggle(unsigned long milliseconds);
    void amountToggle(float liters);
    bool isActive();
    void setPumpActivity(bool active);
    void setFlowrate(flowrate f);
    void setPin(int pin);
    std::string toString();
};
