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

/* setup a mode variables */
uint8_t exampleMode = 0;
uint8_t exampleModeMax = 13;
uint32_t lastTimeChanged = 0; 

/* time to show an example */
uint16_t timeToDisplayExampleInMs = 5000; // five seconds in milliseconds
uint16_t flashTimeInMs = 500;


void setup() {
  /* call begin on the rgbLed */
  rgbLed.begin();
}

void loop() {
  /* code to flip through the different modes */
  if (millis() - lastTimeChanged >= timeToDisplayExampleInMs) {
    exampleMode++;

    if (exampleMode > exampleModeMax) {
      exampleMode = 0;
    }

    switch(exampleMode) {
      case 0:
        rgbLed.red();
        break;

      case 1:
        rgbLed.green();
        break;

      case 2:
        rgbLed.blue();
        break;

      case 3:
        rgbLed.purple();
        break;

      case 4:
        rgbLed.yellow();
        break;

      case 5:
        rgbLed.cyan();
        break;

      case 6:
        rgbLed.white();
        break;

      case 7:
        rgbLed.flashRed(flashTimeInMs);
        break;
      
      case 8:
        rgbLed.flashGreen(flashTimeInMs);
        break;

      case 9:
        rgbLed.flashBlue(flashTimeInMs);
        break;
      
      case 10:
        rgbLed.flashPurple(flashTimeInMs);
        break;

      case 11:
        rgbLed.flashYellow(flashTimeInMs);
        break;
      
      case 12:
        rgbLed.flashWhite(flashTimeInMs);
        break;

      case 13:
        rgbLed.off();
        break;

      default: 
        rgbLed.off();
        break;
    }

    lastTimeChanged = millis();
  }

  /* call the rgbLed's run on each loop */
  rgbLed.run();
}