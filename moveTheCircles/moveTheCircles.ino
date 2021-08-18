/*
Hanaan Shafi
Assigment Due June 28
Handshaking between Arduino and Processing:
Prompt: Make a simple game that involves some kind of communication between Arduino and Processing, 
 always using handshaking 
 */

int receivingIndicator = 1; //this is a variable to receive communication from processing

void setup() {
  Serial.begin(9600); //initialize serial communication
  Serial.println("0"); 
}

void loop() {
  while (Serial.available()) { // as long as there is incoming data, then:
    receivingIndicator = Serial.parseInt(); //let the variable receivingIndicator take in the incoming data
    if (Serial.read() == '\n') { 
      // this is to record the input data from the Arduino, and print it to the Serial. 
      int sensor = analogRead(A0);
      delay(1);
      Serial.println(sensor);
    }
  }
}
