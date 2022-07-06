void handleStaticPrefab(){

    String prefabName = server.arg("static-prefab");

    //rainbow pattern
    if(prefabName.equals("rainbow")){
      int zoneSize = NUMPIXELS / 6;
      
      uint32_t vivid_red = pixels.Color(255*brightness, 0*brightness, 24*brightness);
      uint32_t deep_saffron = pixels.Color(255*brightness, 165*brightness, 44*brightness);
      uint32_t maximum_yellow = pixels.Color(255*brightness, 255*brightness, 65*brightness);
      uint32_t ao = pixels.Color(0*brightness, 128*brightness, 24*brightness);
      uint32_t blue = pixels.Color(0*brightness, 0*brightness, 249*brightness);
      uint32_t philippine_violet = pixels.Color(134*brightness, 0*brightness, 125*brightness);
      
      pixels.fill(vivid_red, 0, zoneSize);
      pixels.fill(deep_saffron, 1*zoneSize, zoneSize);
      pixels.fill(maximum_yellow, 2*zoneSize, zoneSize);
      pixels.fill(ao, 3*zoneSize, zoneSize);
      pixels.fill(blue, 4*zoneSize, zoneSize);
      pixels.fill(philippine_violet, 5*zoneSize, zoneSize);
    }
    
    //bi color pattern
    if(prefabName.equals("bi-color")){
      int zoneSize = NUMPIXELS / 10;
      uint32_t roxal_red = pixels.Color(208*brightness, 0*brightness, 112*brightness);
      uint32_t cadmium_violet = pixels.Color(140*brightness, 71*brightness, 153*brightness);
      uint32_t dark_powder_blue = pixels.Color(0*brightness, 50*brightness, 160*brightness);

      pixels.fill(roxal_red, 0, zoneSize*4);  
      pixels.fill(cadmium_violet, zoneSize*4, zoneSize*2);
      pixels.fill(dark_powder_blue, zoneSize*6, zoneSize*4); 
    }

    //show pixels
    pixels.show();
}
