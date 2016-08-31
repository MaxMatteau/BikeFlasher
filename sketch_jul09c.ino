// SENSORS pin
#define Btn1 2
#define Btn2 3
#define Btn3 4
#define Front 5
#define BackLeft 6
#define BackRight 7
#define PhotoCell A1

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED pin
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void testfillrect(void) {
  uint8_t color = 0;
  for (int16_t i=0; i<display.height()/2; i+=3) {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    color++;
  };
};

void setup() {
// draw multiple rectangles
  testfillrect();
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {
  digitalRead(2);
  digitalRead(3);
  digitalRead(4);
  analogRead(A1);

 if (digitalRead(2)==HIGH){
  while(digitalRead(2)==HIGH){
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  } 
  digitalWrite(6,LOW);
 }
 else (digitalRead(3)==HIGH){
  while(digitalRead(3)==HIGH){
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
    delay(1000);
  }
  digitalWrite(7,LOW);
 }
else (digitalRead(4)==HIGH){
  while(digitalRead(4)==HIGH){
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

}
