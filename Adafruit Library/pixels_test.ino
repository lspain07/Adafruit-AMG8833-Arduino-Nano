  #include <Wire.h>
  #include <Adafruit_AMG88xx.h>

    Adafruit_AMG88xx amg;

    void setup() {
      Serial.begin(9600);
      if (!amg.begin()) {
        Serial.println("AMG8833 not found!");
        while (1);
      }
    }

    void loop() {
      float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
      amg.readPixels(pixels);

      for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        Serial.print(pixels[i]);
        Serial.print(","); // Use comma as delimiter
      }
      Serial.println(); // Newline at the end of each frame
      delay(100); // Adjust delay as needed
    }
