#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webpage.h";
#include "wifidata.h";

//Port
ESP8266WebServer server(80);

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LEDPIN D1
#define NUMPIXELS 60 //Number of pixels of the LED strip

Adafruit_NeoPixel pixels(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

//global variables
float brightness = 0.7f;

//variables for animation handling
int animationStage = 0;
bool isAnimation = false;
String animation;

//variables for time measurement in loop
long currentTime; 
long newTime;
long timePast;

void setup() {  
  Serial.begin(9600);
  
  //Set all Pixels to 0
  pixels.begin();
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i,pixels.Color(0,0,0));
  }
  pixels.show();

  //Connect to wifi
  Serial.print("Connecting to Wifi");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  //Print locale IP and start server
  Serial.println("");
  Serial.println("Wifi connected");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());

  //start web server
  server.on("/", showWebPage);
  server.begin();

  //Set time
  currentTime = millis();
}

// the loop function runs over and over again forever
void loop() {
  //handle web page
  server.handleClient();

  //handle animation if one is running every 20 millisecond
  if(isAnimation){
    newTime = millis();
    timePast = newTime - currentTime; 
    if(timePast > 20){
      animate(animation);
      currentTime = newTime;
    }   
  } 
}

//show/send the webpage or handle incoming form submissions
void showWebPage(){
  //without data
  if (server.method() != HTTP_POST) {    
    server.send(200,"text/html", webpageCode);
  } 
  //with data
  else {    
    
    server.send(200,"text/html", webpageCode);
    
    isAnimation = false; //set to default

    //check which type was submitted
    String type = server.arg("submit-type");
    if(type.equals("static-color")){
      handleStaticColor();
    }
    else if(type.equals("static-prefab")){
      handleStaticPrefab();
    }
    else if(type.equals("animation")){
      handleAnimation();
    }
    else if(type.equals("brightness")){
      handleBrightness();
    }
  }
}

//handle a brighness submit
void handleBrightness(){
    //Set selected color
    Serial.println(server.arg("brightness"));
    int val = server.arg("brightness").toInt();
    Serial.println(val);
    brightness = val/100.0f;
    Serial.println(brightness);
}
