#include "RgbLed.h"

RgbLed::RgbLed(
  uint8_t _pinRed,
  uint8_t _pinGreen,
  uint8_t _pinBlue,
  boolean _onState
) {
  /* assign vars */
  pinRed = _pinRed;
  pinGreen = _pinGreen;
  pinBlue = _pinBlue;
  onState = _onState;

  /* init off state */
  offState = !onState;
}

void RgbLed::begin() {
  /* setup the pins */
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  /* init the status LED to off */
  off();
}

void RgbLed::run() {
  /* excecute code for the current mode */
  switch(mode) {
    /* off */
    case 0:
      off();
      break;

    /* set to solid color */
    case 1:
      /* nothing to do */
      break;

    /* set to flashing color(s) */
    case 2:
      updateFlashingState();
      break;

    /* default to off if mode unknown */
    default:
      off();
      break;
  }
}

void RgbLed::setModeSolidColor() {
  mode = 1;
}

void RgbLed::updateFlashingState() {
  /* check if it's time to swtich between on/off */
  if (millis() - timeLastFlashed < timeoutFlash) {
    /* timeout hasn't expired yet */
    return;
  }

  /* timeout has expired */
  /* toggle the flashing state */
  stateFlashing = !stateFlashing;

  /* toggle the values on the color pins */
  if (stateRed == true) {
    digitalWrite(pinRed, stateFlashing);
  }

  if (stateGreen == true) {
    digitalWrite(pinGreen, stateFlashing);
  }

  if (stateBlue == true) {
    digitalWrite(pinBlue, stateFlashing);
  }

  /* update the last flashed time */
  timeLastFlashed = millis();
}

void RgbLed::setModeFlashing(
  boolean _stateRed,
  boolean _stateGreen,
  boolean _stateBlue,
  uint16_t _timeout
) {
  /* assign vars */
  stateRed = _stateRed;
  stateGreen = _stateGreen;
  stateBlue = _stateBlue;
  timeoutFlash = _timeout;

  /* update the mode flag */
  mode = 2;
}

void RgbLed::off() {
  digitalWrite(pinRed, offState);
  digitalWrite(pinGreen, offState);
  digitalWrite(pinBlue, offState);
}

void RgbLed::red() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinRed, onState);
}

void RgbLed::green() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinGreen, onState);
}

void RgbLed::blue() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinBlue, onState);
}

void RgbLed::purple() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinBlue, onState);
  digitalWrite(pinRed, onState);
}

void RgbLed::yellow() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinGreen, onState);
  digitalWrite(pinRed, onState);
}

void RgbLed::cyan() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinBlue, onState);
  digitalWrite(pinGreen, onState);
}

void RgbLed::white() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinBlue, onState);
  digitalWrite(pinGreen, onState);
  digitalWrite(pinBlue, onState);
}

void RgbLed::flashRed(uint16_t _timeoutFlash) {
/* clear the led */
  off();

  /* set LED state for red flashing */
  setModeFlashing(
    true, // red
    false, // green
    false, // blue
    _timeoutFlash
  );
}

void RgbLed::flashGreen(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

  /* set LED state for green flashing */
  setModeFlashing(
    false, // red
    true, // green
    false, // blue
    _timeoutFlash
  );
}

void RgbLed::flashBlue(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

   /* set LED state for red flashing */
  setModeFlashing(
    false, // red
    false, // green
    true, // blue
    _timeoutFlash
  );
}

void RgbLed::flashPurple(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

   /* set LED state for purple flashing */
  setModeFlashing(
    true, // red
    false, // green
    true, // blue
    _timeoutFlash
  );
}

void RgbLed::flashYellow(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

   /* set LED state for yellow flashing */
  setModeFlashing(
    true, // red
    true, // green
    false, // blue
    _timeoutFlash
  );
}

void RgbLed::flashCyan(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

   /* set LED state for cyan flashing */
  setModeFlashing(
    false, // red
    true, // green
    true, // blue
    _timeoutFlash
  );
}

void RgbLed::flashWhite(uint16_t _timeoutFlash) {
  /* clear the led */
  off();

   /* set LED state for cyan flashing */
  setModeFlashing(
    true, // red
    true, // green
    true, // blue
    _timeoutFlash
  );
}