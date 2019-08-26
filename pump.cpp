//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//Definition of the functions surrounding the pump object

#include "pump.hpp"

//Constructors

pump::pump(flowrate throughput, int pin, bool is_active) : m_flowrate(throughput), m_pin(pin), m_is_active(is_active)
{
    pinMode(pin, OUTPUT);
}

pump::pump(float throughput, time_unit unit, int pin, bool is_active) : m_flowrate({throughput, unit}), m_pin(pin), m_is_active(is_active)
{
    pinMode(pin, OUTPUT);
}

pump::~pump()
{
}

//Functions

//Toggles the pump on or off
void pump::togglePump()
{
    m_is_active = !m_is_active;
    digitalWrite(m_pin, m_is_active ? HIGH : LOW);
}

//Toggles the pump for a given amount of time
void pump::timedToggle(unsigned long milliseconds)
{
    togglePump();
    delay(milliseconds);
    togglePump();
}

//Toggles the pump for a given amount of liquid
void pump::amountToggle(float liters)
{
    float secondsToToggle = liters / normalizedFlowrate();
    timedToggle(secondsToToggle * 1000);
}

//returns the flowrate in  liters per second
float pump::normalizedFlowrate()
{
    float multiplicator = 0;

    switch (m_flowrate.m_unit)
    {
    case millisecond:
        multiplicator = 1000;
        break;
    case second:
        multiplicator = 1;
        break;
    case minute:
        multiplicator = 1 / 60;
        break;
    case hour:
        multiplicator = 1 / 3600;
        break;
    default:
        break;
    }

    return m_flowrate.m_amount_in_liters * multiplicator;
}

//returns if the pump is active or not
bool pump::isActive()
{
    return m_is_active;
}

//sets a new flowrate for the pump
void pump::setFlowrate(flowrate f)
{
    m_flowrate = f;
}

//sets the pump activation pin
void pump::setPin(int pin)
{
    m_pin = pin;
}

//sets if the pump is supposed to be active
void pump::setPumpActivity(bool active)
{
    m_is_active = active;
}

std::string pump::toString()
{
    std::string result;
    result = "Flowrate: " + std::to_string(m_flowrate.m_amount_in_liters) + "/" + std::to_string(m_flowrate.m_unit) + "Pin: " + std::to_string(m_pin) + " Status: " + std::to_string(m_is_active);
    return result;
}