#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LEDPIN D1
#define NUMPIXELS 60

Adafruit_NeoPixel pixels(NUMPIXELS, LEDPIN, NEO_RGB + NEO_KHZ800);

void setup() {  
  //Set all Pixels to 0
  pixels.begin();
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i,pixels.Color(0,0,0));
  }
  pixels.show();
}

// the loop function runs over and over again forever
void loop() {

}
