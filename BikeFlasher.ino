#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// SENSORS pins
  #define Btn1 2
  #define Btn2 3
  #define Btn3 4
  #define Front A1
  #define BackLeft A2
  #define BackRight A3
  #define PhotoCell A4

// OLED pins
  #define OLED_MOSI   9    // Data pin on screen
  #define OLED_CLK   10
  #define OLED_DC    11
  #define OLED_CS    12
  #define OLED_RESET 13

// OLED init
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Functions
  void testfillrect(void) {
    uint8_t color = 0;
    for (int16_t i=0; i<display.height()/2; i+=3) {
      // alternate colors
      display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
      display.display();
      color++;
    }
  }

void setup() {
// Bootlogo
  testfillrect();
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {

  /*if (analogRead(A4)<=500) {
    analogWrite(A1,0.5);
    analogWrite(A2,0.5);
    analogWrite(A3,0.5);                 //verify the value of the photo cell for night mode and day mode */
  }
  
  if (digitalRead(2)==HIGH){
    while(digitalRead(2)==HIGH) do {
      analogWrite(A2,1);
      delay(1000);
      analogWrite(A2,0);
      delay(1000);
    }
 
  } else if (digitalRead(3)==HIGH) {
      while (digitalRead(3)==HIGH) do {
        analogWrite(A3,1);
        delay(1000);
        analogWrite(A3,0);
        delay(1000);
      }
    
  } else if (digitalRead(4)==HIGH) {
      while (digitalRead(4)==HIGH) do {
        analogWrite(A2,1);
        analogWrite(A3,1);
      }
  }

}
