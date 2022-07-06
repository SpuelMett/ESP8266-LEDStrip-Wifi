void handleStaticColor() {  
    //Set selected color
    String hexString = server.arg("color");
    //remove # and convert to integer
    hexString.remove(0,1);
    int colorInt = HexStrToInt(hexString);
    setStaticColor(colorInt);
}

//Convert a hex String to an integer
int HexStrToInt(String hexString){
  int l = hexString.length();
  char str[l];
  hexString.toCharArray(str,l+1); 
  return StrToHex(str);
}

int StrToHex(char str[]){
  return (int) strtol(str,0,16);
}

void setStaticColor(int colorInt){
  //Set pixel color
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i,colorInt);
  }
  pixels.show();
}
