//
// Written by Peter Lingås 02/02/2024
//
#ifndef KY040_HPP
#define KY040_HPP
#include "Arduino.h"

class KYEncoder
{
public:
    KYEncoder(uint8_t a, uint8_t b, uint8_t btn);
    void setup();
    void update();
    int getValue();
    bool isPressed();

private:
    uint8_t pin_a;
    uint8_t pin_b;
    uint8_t pin_btn;

    bool last_a;
    bool last_b;
    int8_t counter;

    int value;
};
#endif