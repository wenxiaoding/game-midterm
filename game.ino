#include "Keyboard.h"

// set pin numbers for the five buttons:
const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int startButton = 6;
const int jumpButton = 7;
bool isStart = false;
int buttonState = false;
int lastButtonState = false;


void setup() { // initialize the buttons' inputs:
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLDOWN);
  pinMode(jumpButton, INPUT_PULLDOWN);

  Serial.begin(9600);
  // initialize mouse control
  Keyboard.begin();
}

void loop() {
  // use serial input to control the mouse:
  buttonState = digitalRead(startButton);
  if (buttonState == LOW && lastButtonState == HIGH) {
    isStart = !isStart;
  }
  lastButtonState = buttonState;
  //Serial.print("buttonstate ");
  //Serial.println(buttonState);
  //Serial.print("last ");
  //Serial.println(lastButtonState);
  delay(100);
  
  if (isStart) {
    // use the pushbuttons to control the keyboard:
    if (digitalRead(upButton) == LOW) {     
      Keyboard.press('w');
    }
    else if (digitalRead(downButton) == LOW) {
      Keyboard.press('s');
    }
    else if (digitalRead(leftButton) == LOW) {
      Keyboard.press('a');
    }
    else if (digitalRead(rightButton) == LOW) {
      Keyboard.press('d');
    }
    else if (digitalRead(jumpButton) == HIGH){
      Keyboard.press(' ');
    }
    else {
      Keyboard.releaseAll();
    }
  }


}
