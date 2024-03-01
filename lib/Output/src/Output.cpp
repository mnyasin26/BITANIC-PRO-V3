#include "Output.h"

Output::Output(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

Output::Output()
{
}

bool Output::stateOn()
{
    return isOn;
}

void Output::on()
{
    digitalWrite(pin, HIGH);
    isOn = true;
}

void Output::off()
{
    digitalWrite(pin, LOW);
    isOn = false;
}

void Output::toggle()
{
    if (isOn)
    {
        off();
    }
    else
    {
        on();
    }
}