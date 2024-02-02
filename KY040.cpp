//
// Written by Peter Lingås 02/02/2024
//
#include "KY040.hpp"

KYEncoder::KYEncoder(uint8_t a, uint8_t b, uint8_t btn)
{

    pin_a = a;
    pin_b = b;
    pin_btn = btn;
}

void KYEncoder::setup()
{
    pinMode(pin_a, INPUT);
    pinMode(pin_b, INPUT);
    pinMode(pin_btn, INPUT_PULLUP);
    value = 0;
    counter = 0;
}

void KYEncoder::update()
{

    bool a = digitalRead(pin_a);
    bool b = digitalRead(pin_b);

    if (!a && last_a && (counter == 0 || counter == -1))
    {
        b ? counter++ : counter--;
    }

    if (!b && last_b && (counter == 0 || counter == 1))
    {
        a ? counter-- : counter++;
    }

    if (a && !last_a && (counter == 2 || counter == -3))
    {
        b ? counter-- : counter++;
    }

    if (b && !last_b && (counter == 3 || counter == -2))
    {
        a ? counter++ : counter--;
    }

    if (counter == 4)
    {
        value++;
    }

    if (counter == -4)
    {
        value--;
    }

    if (a && b)
    {
        counter = 0;
    }

    last_a = a;
    last_b = b;
}

int KYEncoder::getValue()
{
    return value;
}

bool KYEncoder::isPressed()
{
    return !digitalRead(pin_btn);
}