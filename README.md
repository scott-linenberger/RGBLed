# RgbLed Arduino Library  
The RgbLed library is an easy-to-use library for controlling simple RGB LEDs without having to write a bunch of code. Change your RGB LED's color or flash your RGB LED without using while loops and delays that can block your code from reading inputs.  

```
#include <RgbLed.h>

RgbLed rgbLed = RgbLed(
  10, // red pin
  11, // green pin
  12, // blue pin
  HIGH // activates a color
);

void setup() {
  rgbLed.begin(); // start LED
  rgbLed.blue(); // set LED blue
}

void loop() {
  rgbLed.run(); // update the led every loop
}
```
For more information on RGB LEDs and a great tutorial, checkout Adafruit's "Arduino Lesson 3 -  RGB LEDs".

[Adafruit Arduino Lesson 3 - RGB LEDs](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview)

## How to Use the RgbLed Library  
First, you will need to set up the RGB LED in code. It is important that you put this code after the include for the RgbLed library and outside of your `setup` and `loop` methods (see the examples directory for complete sample code). 

There are different types of RGB LEDs. Some have a common lead that gets connected to GROUND. Others have a common lead that gets attached to VIN. You'll need to set your RgbLed code up to match your LED. You'll need to use one of the two configurations below. 

[Common Ground] - RGB LED that has a common GROUND lead with color leads that activate when connected to VIN. With the red, green and blue color leads connected to pins 10, 11 and 12  
```
  RgbLed rgbLed = RgbLed(
    10, // red pin
    11, // green pin
    12, // blue pin
    HIGH // activates a color pin
  );
```

[Common VIN] - RGB LED that has a VIN lead with color leads that activate when connected to GROUND. With the red, green and blue color leads connected to pins 10, 11 and 12  
```
  RgbLed rgbLed = RgbLed(
    10, // red pin
    11, // green pin
    12, // blue pin
    LOW // activates a color
  );
```

Next, you'll need to call `begin` to start the RgbLed code. This call must be made **inside** of your `setup` method and should **only be called once**. 

```
  void setup() {
    /* start the rgbLed */
    rgbLed.begin();
  }
```

Now you are free to call the rgbLed code in any of your methods, including the `loop` method. 

```
void loop() {
  ... // some code...
    rgbLed.green();
  ... // some other code...
  rgbLed.run();
}

```

Lastly, you'll want to call RgbLed's `run` method at least once per loop. If you are new to Arduino or not very familiar with code, calling the `run` method at the bottom of `loop` is a good idea.

```
void loop() }
  ... // code

  rgbLed.run()
}
```

If you are a little more comfortable with Arduino and code, you actully skip the run command if you aren't using any methods that need timing updated. See the API section below. 

## Complete Example  
Here is a complete example without comments to save space and make the code more condensed.
```
#include <RgbLed.h>

RgbLed rgbLed = RgbLed(
  10, // red pin
  11, // green pin
  12, // blue pin
  HIGH // activates a color
);

void setup() {
  rgbLed.begin();
  rgbLed.blue();
}

void loop() {
  rgbLed.run();
}
```

## Using `run`  
The RgbLed library uses `run` to update timer variables in code. It is a good idea to call to `run` on your RgbLed in the `loop` function of your Arduino Sketch. However, if you aren't using any methods that use timing updates, you don't need to call `run` at all 

If your coding abilities are a little more advanced, you can even decide to call `run` selectively. Just keep in mind, the more you delay between `run` calls, the more out of sync timing will be and you may notice odd or unpredictable behavior in your LED. Frequent calls to run are inexpensive and keep the timing sync'd up. In fact, you can call `run` multiple times per loop if you need to. 

**Important:**  
Keep in mind, running long blocking code that prevents the `run` method from being called can affect the RgbLed's timing. For example, if you are flashing an LED every 500 millisecons and calling `run` on each loop, but you use a delay of 5 seconds, that is five seconds that will pass before the LED's timing can be updated. Meaning, the LED will not flash or change while the long delay is happening. 

## NON-BLOCKING: 
The RgbLed library uses state based, non-blocking methods of timing instead of blocking while loops or delays. This makes the RgbLed library great for projects that need to be ready to accept input without being blocked by delays or while loops used for timing and animations.


## USING STATE METHODS:  
To use state methods, call the method **once** to activate the corresponding state. Do not call the state method again unless you intened to start the state over again.  

For example, if you want to set the LED to flash red, you would call `flashRed` one time and then call `run` in each loop to update the LED. If you were to call `flashRed` on each loop, the flashing timer would keep getting reset and you wouldn't see any flashing. That's because the state methods **START/RESTART** a state. 

## API  
### NON STATE METHODS
| method      | description                                                | timing       |
|------------:|------------------------------------------------------------|:------------:|
| `begin()`   | starts the RgbLed, must be called in `setup`. Call **ONCE**| NO           |


### STATE METHODS 
| method                                  | description                    | timing       |
|----------------------------------------:|--------------------------------|:------------:|
| `red()`                                 | sets LED red (not flashing)    | NO           |
| `green()`                               | sets LED green (not flashing)  | NO           |
| `blue()`                                | sets LED blue (not flashing)   | NO           |
| `purple()`                              | sets LED purple (not flashing) | NO           |
| `yellow()`                              | sets LED yellow (not flashing) | NO           |
| `cyan()`                                | sets LED cyan (not flashing)   | NO           |
| `white()`                               | sets LED white (not flashing)  | NO           |
| `flashRed(uint16_t timeToFlashInMs)`    | sets LED <> (not flashing)     | YES          |
| `flashGreen(uint16_t timeToFlashInMs)`  | sets LED <> (not flashing)     | YES          |
| `flashBlue(uint16_t timeToFlashInMs)`   | sets LED <> (not flashing)     | YES          |
| `flashPurple(uint16_t timeToFlashInMs)` | sets LED <> (not flashing)     | YES          |
| `flashYellow(uint16_t timeToFlashInMs)` | sets LED <> (not flashing)     | YES          |
| `flashCyan(uint16_t timeToFlashInMs)`   | sets LED <> (not flashing)     | YES          |
| `flashWhite(uint16_t timeToFlashInMs)`  | sets LED <> (not flashing)     | YES          |
| `off()`                                 | sets LED <> (not flashing)     | NO           |
| `run()`                                 | updates timers and LED         | NO           |

## Troubleshooting:  
1. Check your PINS, POWER and WIRING. Make sure everythig is hooked up properly. 
2. Check your COMPONENTS. Make sure your LED is good and not burned out. 
3. Check code

**My LED doesn't turn on:**  

**-Have right LED on-state setting?-**
Make sure you have used the correct led on-state parameter (HIGH or LOW) for your type of LED. If your LED's color leads need to be connected to VIN to activate, then use HIGH. If your LEDs color leads need to be connected to GROUND, then use LOW.

**-Are you calling the run method?-**
If you are calling any of the methods that use timing, and you aren't calling the `run` method, your LED won't work. Make sure you are calling `run` once per loop.  

**-Are ou blocking the run method?**
If you are using a really long blocking delay or while loop, you could be blocking your call to `run`.  

**-Are you 