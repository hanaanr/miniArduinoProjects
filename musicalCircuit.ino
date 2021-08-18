/* Hanaan Shafi
Assignment Due June 21st
Make A Musical Instrument

This is the code for an instrument which changes sound (in order of the notes), with rotation of the potentiometer knob. As the potentiometer reading increases, so does the sound change. 
At any point, if the button is pressed, the sound is stopped. 
 */
#include "pitches.h"

const int potentiometer = A0;
const int pushButton = 4;
const int buzzer = 8;

void setup() {
  Serial.begin(9600); // so we can read the potentiometer location later
  pinMode(4, INPUT);
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  int pushValue = digitalRead(4); //this is the button
  
  int analogValue = analogRead(A0); // read the input on analog pin
  Serial.println(analogValue); //print it so we can read its value

  if (pushValue == LOW) { //if the button is not pressed, then increase the tone with every 200 increment in potentiometer reading
    if (analogValue > 0 && analogValue < 200) {
      tone(8, NOTE_B4, 1000);
    }
    if (analogValue > 200 && analogValue < 400) {
      tone(8, NOTE_C4, 1000);
    }
    if (analogValue > 400 && analogValue < 600) {
      tone(8, NOTE_D4, 1000);
    }
    if (analogValue > 600 && analogValue < 800) {
      tone(8, NOTE_E4, 1000);
    }
    if (analogValue > 800 && analogValue < 1023) {
      tone(8, NOTE_F4, 1000);
    }
  }

  if (pushValue == HIGH){ //but if the button is pressed at any time, stop the sound
    noTone(8);
  }
}
