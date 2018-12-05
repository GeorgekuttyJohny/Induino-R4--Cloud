/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const int analogInPin = 12;  // Analog input pin that the potentiometer is attached to
const int LDRPin = 13;

int sensorValue = 0;
int LDRvalue=0;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
   
}

void loop() {

  display.clearDisplay();
  delay(2000);
  
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  sensorValue = analogRead(analogInPin);
  LDRvalue = analogRead(LDRPin);
  display.print(F("Temp:"));
  int displayValue=sensorValue/6.62;
  display.print(displayValue);
  display.setCursor(0, 25);
  display.setTextSize(1);
  if(LDRvalue<=1000)
  {
    display.print(F("Are you in a dark    spot?"));
  }
  else if(LDRvalue<=2000)
  {
    display.print(F("Are you in a dimly   lit room?"));
  }
  else if(LDRvalue<=3000)
  {
    display.print(F("You seem to be in a  well lit room !"));
    //display.print(LDRvalue);
  }
  else 
  {
    display.print(F("You seem to in the   brightest spot !"));
   
  }
  display.display();      // Show initial text
  delay(1000);

}
