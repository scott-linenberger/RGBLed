#include <RgbLed.h>

/* set these pin variables to match your RGB LEDs pins */
#define PIN_LED_BLUE 10
#define PIN_LED_GREEN 11
#define PIN_LED_RED 12

/* set this to HIGH or LOW based on how your RGB LED works */
/* Set LOW if connecting your LED's color pin to ground
 * activates the color. Set HIGH if connecting your LED's
 * color pin to power activates the color. */
boolean ledOnState = LOW;

/* set up the RGB LED */
RgbLed rgbLed = RgbLed(
  PIN_LED_RED,
  PIN_LED_GREEN,
  PIN_LED_BLUE,
  ledOnState
);

void setup() {
  /* call begin on the rgbLed */
  rgbLed.begin();

  /* set the rgbLed to flashing red */
  rgbLed.flashRed(750);
}

void loop() {
  /* call the rgbLed's run on each loop */
  rgbLed.run();
}