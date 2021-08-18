/*
  Hanaan Shafi
  Assignment Due June 17

*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //set up the input and output pinmodes
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A1, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0); //reads the LDR
  int pushButton = digitalRead(A1); //reads the button

  if (sensorValue < 670 && sensorValue > 600 && pushButton==LOW) { //if the light falls within this range:
    for (int i = 0; i < 15; i++) { //do this 14 times:
      //blink the LED connected to 9
      digitalWrite(9, HIGH);
      delay(100);
      digitalWrite(9, LOW);
      delay(100);
    }
    digitalWrite(9, LOW); //finally, turn it off
  }

  //repeat the same with a different light range and blink rate
  if (sensorValue < 630 && sensorValue > 600 && pushButton==LOW) {
    for (int i = 0; i < 15; i++) {
      digitalWrite(9, HIGH);
      delay(500);
      digitalWrite(9, LOW);
      delay(500);

      Serial.println(sensorValue);
      delay(1);
    }
    digitalWrite(9, LOW);
  }

  // now, if the button is turned on, then turn on the other LED 
  if (pushButton == HIGH) {
    digitalWrite(9, LOW);
    digitalWrite(11, HIGH);
  }


}
