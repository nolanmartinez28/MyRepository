#include <Adafruit_CircuitPlayground.h>

float soundVal;
int soundParam;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
}

void loop() {
  soundParam = map(soundVal, 50, 150, 0, 9);
  soundVal = CircuitPlayground.mic.soundPressureLevel(10);
  CircuitPlayground.clearPixels();

  Serial.print("Sound value: ");
  Serial.println(soundVal);

  for(int i = 0; i < (soundParam + 1); i++) {
    CircuitPlayground.setPixelColor(i, 0xFFFFFF);
  }
  delay(50);
}