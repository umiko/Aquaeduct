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
