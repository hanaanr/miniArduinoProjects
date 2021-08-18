/*
Hanaan Shafi
Assignment Due June 14
*/

const int sw1 = A4;
const int sw2 = A5;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //setting up the output as the four LEDS:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //the input is the two switches:
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  int state1 = digitalRead(sw1);
  int state2 = digitalRead(sw2);

  if (state1 == HIGH && state2 == LOW) { //this part of the code says that if sw1 is turned on (while sw2 is not), then:
    digitalWrite(8, HIGH); //turn on the led connected to 8 which is yellow
    delay(300); //then after a short delay, 
    digitalWrite(8, LOW); //turn it off
    delay(300);
    digitalWrite(9, HIGH); //turn on blue
    delay(300);
    digitalWrite(9, LOW); //then turn it off
    delay(300);
    digitalWrite(10, HIGH); //turn on red
    delay(300);
    digitalWrite(10, LOW); //turn red off 
    delay(300);
    digitalWrite(11, HIGH); //turn on green
    delay(300);
    digitalWrite(11, LOW); //turn it off
    delay(300);
  }

  if (state1 == LOW && state2 == HIGH) { //when the other switch is pressed, turn on a total of 4 LEDs at random (sometimes the same LEDs are turned on)
    digitalWrite(random(8, 11), HIGH); 
    delay(300);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(random(8, 11), HIGH);
    delay(300);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(random(8, 11), HIGH);
    delay(300);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(random(8, 11), HIGH);
    delay(300);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

  }


}
