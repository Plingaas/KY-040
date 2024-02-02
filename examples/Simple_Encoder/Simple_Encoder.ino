//
// Written by Peter Lingås 02/02/2024
//
#include "KY040.hpp"

// Attach pins (CLK, DT, SW), aka (A, B, BTN)
KYEncoder encoder(5, 6, 7);

void setup()
{
  Serial.begin(115200);

  // Sets up the correct pinmodes.
  encoder.setup();
}

// Only used to reduce serial printing, not needed.
long last = micros();
long now = micros();
long min_time = 1e5;

void loop()
{
  // The more frequent update is ran, the more reliable the encoder will be.
  encoder.update();

  // Print 10 times per second
  now = micros();
  if (now - last > min_time)
  {
    Serial.print("Encoder Value: ");
    Serial.print(encoder.getValue());
    Serial.print("     Pressed: ");
    Serial.println(encoder.isPressed());
    last += min_time;
  }
}
