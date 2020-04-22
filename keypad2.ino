/*
  Keyboard logout

  This sketch demonstrates the Keyboard library.

  When you connect pin 2 to ground, it performs a logout.
  It uses keyboard combinations to do this, as follows:

*/

#include "HID-Project.h"

  bool state = 0;


void setup() {
  // make pin 2 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP); //power
  pinMode(3, INPUT_PULLUP); //volume down
  pinMode(4, INPUT_PULLUP); //home
  pinMode(5, INPUT_PULLUP); //volume up
  pinMode(6, INPUT_PULLUP); //assistant

  //pin 7 is a jumper to enable or disable brightness based switching
  pinMode(7, INPUT_PULLUP);
  //pin 9 is an output to control the LCD
  pinMode(9, OUTPUT);
 

  Keyboard.begin();
  Consumer.begin();
  NKROKeyboard.begin();



}

void loop() {
  


if(digitalRead(7) == LOW){
  int brightness = analogRead(A0);
  //ajust the value at which the screen will turn on
  if(brightness > 310 && state == 0){
     digitalWrite(9, HIGH);
      delay(100);
    digitalWrite(9, LOW);
    state = 1;
      delay(100);
  }
//adjust the value at which the screen will turn off
  if(brightness < 290 && state == 1){
     digitalWrite(9, HIGH);
      delay(100);
    digitalWrite(9, LOW);
    state = 0; 
      delay(100);
  }
}

  //button reading 
  if (digitalRead(4) == LOW) {
     Keyboard.press('Q');
      delay(100);
      // Keyboard.releaseAll(); 
      delay(100);
  }

 else if (digitalRead(3) == LOW) {
    Consumer.write(MEDIA_VOL_DOWN);
      delay(100);
      // Keyboard.releaseAll(); 
      delay(100);

  }

    else if (digitalRead(2) == LOW) {
    digitalWrite(9, HIGH);
      delay(100);
    digitalWrite(9, LOW);
    state = !state;
      delay(100);

  }

   else if (digitalRead(5) == LOW) {
    Consumer.write(MEDIA_VOL_UP);
      delay(100);
      delay(100);

  }

   else if (digitalRead(6) == LOW) {
     Keyboard.press('T');
      delay(100);
      // Keyboard.releaseAll(); 
      delay(100);

  }
else    { Keyboard.releaseAll(); }

 
  }
