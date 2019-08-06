/**
  Author: Divyansh Bhowmick
  Description: Programming ATTINY85 using Arduino as ISP.
  Language Used: Embedded C

  Steps for programming the micro-controller ATTINY85.
  1) Upload the Arduino ISP program onto Arduino UNO board
  2) Connect Arduino with ATTINY 85
    ATTINY85 PINS         ARDUINO PINS
        1      -----------    10
        5      -----------    11
        6      -----------    12
        7      -----------    13
        8      -----------    5V
        4      -----------    GND
  3) Write the code for the ATTINY 85 and select the board ATTINY85 and Programmer to Arduino as ISP.
  4) Just upload the code and enjoy!

  Steps for viewing the output on Serial monitor.
  1) Use the SoftwareSerial Library and define the RX and TX pins.
  2) Select the board to Arduino UNO and dump a blank code onto it.
  3) Connect the RX and TX pins to 0 and 1 pin of Arduino.
  4) Open the Serial monitor and observe the ouput.

  Ready, to rock!

**/

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define LED1 PB0  //Defining the LED pin
#define BTN PB1  //Defining the Button pin

#define LED_ON   PORTB |= (1 << LED1);  //Defining a macro for turning on the LED
#define LED_OFF  PORTB &= ~(1<<LED1);   //Defining a macro for turining off the LED
#define SWITCH_PRESSED !(PINB & (1 << PINB1))

//Defining the interrupt service routine
ISR(PCINT0_vect) {
  if (SWITCH_PRESSED) //Reading the status of PINB1
  {
    LED_OFF;
  }
  else {
    LED_ON;
  }
}


void setup() {

  DDRB |= (1 << LED1); //Setting LED1 as output
  DDRB &= ~(1 << BTN); //Setting BTN as input
  PORTB |= (1 << BTN); //Setiing BTN as input pullup

  PCMSK |= (1 << PCINT3); //Enabling the Pin Change Mask Register
  GIMSK |= (1 << PCIE); // Setting the Pin Change Interrupt Enable  bit of General Interrupt Mask Register.
  sei(); //Setting the I bit of AVR Status Register
}


void loop() {

}
