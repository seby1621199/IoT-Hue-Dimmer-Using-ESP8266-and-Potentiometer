# IoT-Hue-Dimmer-Using-ESP8266-and-Potentiometer

This project aims to facilitate the control of Philips Hue Smart bulbs using an ESP8266 board and a potentiometer. It uses the Bridge API to control.

![ESP8266 Pinout](https://raw.githubusercontent.com/seby1621199/IoT-Hue-Dimmer-Using-ESP8266-and-Potentiometer/refs/heads/main/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.webp)

### Step 1 - Blinking LED
The first step is to make the internal light on the board blink using the GPIO2 pin.

### Step 2 - Button-Controlled LED
The second step is to see how we can control a light bulb through a button. The button is connected to GND as well as to a pin of the board, in this case GPIO0 (D3) to see when it is pressed. 

### Step 3 - Brightness Control Using Potentiometer
In this step, we connect a potentiometer to the analog pin A0 of the ESP8266 to read varying voltage levels. The goal is to use this value to simulate light dimming. As the potentiometer is turned, the voltage at A0 changes between 0 and 3.3V, which is read as a value between 0 and 1023 by the analogRead() function. This value is then mapped to a PWM signal and used to control the brightness of an LED connected to GPIO2 (D4). This step serves as a foundation for dimming a smart bulb in later stages.

### Step 4 - Remote Philips Hue
In this step, the transition is made from local control (LED) to controlling a Philips Hue smart light. The ESP8266 reads the value from a potentiometer connected to the analog pin A0 and converts it into a brightness value compatible with the Hue system (0–254).

The ESP8266 then sends two HTTP PUT requests to the Hue Bridge, using the local IP address and the authentication token obtained from the Hue API. These requests adjust the brightness of two selected bulbs (lightId1 and lightId2).


