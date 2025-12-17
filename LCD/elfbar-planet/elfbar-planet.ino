#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS   4
#define TFT_RST  5 
#define TFT_DC   6

// Hardware SPI pins on Uno R4: 11 MOSI, 13 SCK
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
uint32_t counter = 0;
char textBuffer[100];

void setup(void) {
  tft.init(76, 286);
  tft.setSPISpeed(5000000); // 7.3 FPS
  tft.invertDisplay(false); // inverts colors by default...

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextWrap(true);
  tft.print("Hello,\nWorld!");

  delay(1000);
}

void loop(){
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextWrap(true);
  tft.print("black");
  delay(500);

  tft.fillScreen(ST77XX_WHITE);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextWrap(true);
  tft.print("white");
  delay(500);

  tft.fillScreen(ST77XX_RED);
  tft.setCursor(0, 0);
  tft.print("red");
  delay(500);

  tft.fillScreen(ST77XX_GREEN);
  tft.setCursor(0, 0);
  tft.print("green");
  delay(500);

  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0, 0);
  tft.print("blue");
  delay(500);

  tft.fillScreen(ST77XX_YELLOW);
  tft.setCursor(0, 0);
  tft.print("yellow");
  delay(500);

  tft.fillScreen(ST77XX_MAGENTA);
  tft.setCursor(0, 0);
  tft.print("magenta");
  delay(500);
  
}

