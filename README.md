# BLEcooler

Remote controlled cooler from an Arduino UNO to an iPhone over Bluetooth Low Energy (BLE)

The idea behind this project was to dig into an already existing arduino project that I found and alter it in order to get practice with embedded development:

https://www.hackster.io/hackershack/make-an-autonomous-follow-me-cooler-7ca8bc

While working through this project I found that all the parts were not listed or the links to purchace them were unavailable.
Also some key notes that were not mentioned I will try to make big and visible in this repo.

# Parts List

# Parts Info

# Circutry Setup
2 - RDY (must be here)(nRF8001)
3 - ENA (PWM)
4 - IN1
5 - IN2
6 - ENB (PWM)
7 - IN3
8 - IN4
9 - RST (nRF8001)
10 - REQ (nRF8001)
11 - MOSI (must be here) (nRF8001)
12 - MISO (must be here) (nRF8001)
13 - SCK (must be here) (nRF8001)


# Circutry Info
- The pin out above works just fine. The comments below is the reasoning for that setup that you should read if you want to change the pinout. 
- If you want to use the Arduino IDE's Serial monitor to do debugging with print statements, do not assign anything to pins 0 and 1. They are the TX and RX pins used for serial communication and unexpected behavior will happen. If you want to use them for another purpose, just remove the serial communication in the sketch.
- RDY must be on an interrupt pin which the UNO has two locations for interrupts at pin 1 and 2. I use 2 since I like to use the serial monitor mentioned above.
- ENA and ENB must be on pins that support pulse width modultaion (PWM). This is what enables us to change and adjust the speed of the motors.
- MOSI, MISO, and SCK must be in their locations on the UNO. These are required for the SPI protocol which is used for communication over Bluetooth.
- The rest of the assignments just need to be on pins with digital pin capability

# Setup Directions

# Vision for The Future

