#include <Wire.h>
#include <KeyboardController.h>
USBHost usb;
KeyboardController keyboard(usb);

/* ---------------------------------------------------------------------------------------------------- */
int kpr_nole = 0, krl_nole = 0;

void keyPressed() {
  Serial.println("Pressed"); 
  kpr_nole = keyboard.getOemKey();
  Wire.beginTransmission(1);
  Wire.write(kpr_nole);
  Wire.write(krl_nole);
  Wire.endTransmission();
}
void keyReleased() {
 Serial.println("Release"); 
  krl_nole = keyboard.getOemKey();
  kpr_nole = 0;
  Wire.beginTransmission(1);
  Wire.write(kpr_nole);
  Wire.write(krl_nole);
  Wire.endTransmission();
  krl_nole = 0;
}
/* ---------------------------------------------------------------------------------------------------- */

void setup() {
  Serial.begin(9600);
  Wire.begin();
}
  
void loop() {
  usb.Task();
}
