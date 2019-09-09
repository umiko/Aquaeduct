//AUTHOR:
//umiko(https://github.com/umiko)
//Permission to copy and modify is granted under the MIT license
//
//DESCRIPTION:
//The flowrate struct and time unit enum, used in the pump to calculate
//the time needed to provide a given amount of fluid
#ifndef FLOWRATE_HPP
#define FLOWRATE_HPP

enum time_unit
{
    millisecond,
    second,
    minute,
    hour
};

struct flowrate
{
    float m_amount_in_liters;
    time_unit m_unit;
};
#endif