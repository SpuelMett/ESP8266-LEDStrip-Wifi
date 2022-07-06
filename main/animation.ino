void handleAnimation(){
  String type = server.arg("animation");
  isAnimation = true;

  if(type.equals("color-fade")){
    animation = "color-fade";
  }
}


void animate(String type){
 
  if(type.equals("color-fade")){
    float percent = animationStage/10000.0f;
    int hueVal = percent*65536;
    Serial.println(hueVal);
    uint32_t rgbcolor = pixels.ColorHSV(hueVal, 255, 255*brightness);
    pixels.fill(rgbcolor, 0, NUMPIXELS);
  }
   
  pixels.show();

  animationStage += 10;
  if(animationStage >10000) animationStage=0;
}
