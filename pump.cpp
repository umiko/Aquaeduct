#include "pump.hpp"

pump::pump(flowrate throughput, int pin, bool is_active = false) : m_flowrate(throughput), m_pin(pin), m_is_active(is_active)
{
    pinMode(pin, OUTPUT);
}

pump::pump(float throughput, time_unit unit, int pin, bool is_active = false) : m_flowrate({throughput, unit}), m_pin(pin), m_is_active(is_active)
{
    pinMode(pin, OUTPUT);
}

pump::~pump()
{
}

void pump::togglePump()
{
    m_is_active = !m_is_active;
    digitalWrite(m_pin, m_is_active ? HIGH : LOW);
}

void pump::timedToggle(ulong milliseconds)
{
    togglePump();
    delay(milliseconds);
    togglePump();
}

void pump::amountToggle(float liters)
{
    float secondsToToggle = liters / normalizedFlowrate();
    timedToggle(secondsToToggle * 1000);
}

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

bool pump::isActive()
{
    return m_is_active;
}

void pump::setFlowrate(flowrate f)
{
    m_flowrate = f;
}

void pump::setPin(int pin)
{
    m_pin = pin;
}

void pump::setPumpActivity(bool active)
{
    m_is_active = active;
}