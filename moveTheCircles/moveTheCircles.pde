/*
Hanaan Shafi
Assigment Due June 28
Handshaking between Arduino and Processing:
Prompt: Make a simple game that involves some kind of communication between Arduino and Processing, 
 always using handshaking
*/

//setting up to receive data from Arduino
import processing.serial.*;
Serial myPort;

int xPos=0;
boolean arduinoReceives = true; //this is the variable we will use to send data back to Arduino

Circles c1; // this uses a class that I made for a previous assignment that makes concentric Circles

void setup() {
  size(960, 300);
  String portname=Serial.list()[2];
  myPort = new Serial(this, portname, 9600);
  myPort.clear();
  myPort.bufferUntil('\n');
}

void draw() {
  //every time draw runs, make a new instance of Circles class at location specified by xPos
  //y-coordinate remains constant
  c1 = new Circles(xPos, 150, 150);
  c1.concentricCircles();   
}

void serialEvent(Serial myPort) {
  String s = myPort.readStringUntil('\n');
  s = trim(s);
  if (s!=null) {
    // if the data in the string s is not empty, then map it to the xPos as the x-coordinate of the circle
    xPos=(int)map(int(s), 0, 1023, 0, width);
  }
  //sending data back to Arduino 
  myPort.write(int(arduinoReceives)+"\n");
}

//circle class that I made for a previous assignment
class Circles {

  int xPos;
  int yPos;
  int R;

  Circles (int temp1, int temp2, int temp3) { 

    xPos = temp1;
    yPos = temp2;
    R = temp3;
  }

  void concentricCircles() { 
    while (R > 0) {
      R = R - 10; //as the radius decreases, newer circles of random colors are drawn
      fill(random(255), random(255), random(255));
      circle(xPos, yPos, R);
    }
  }
}
