    #include <Wire.h>
    #include <Adafruit_AMG88xx.h>

    Adafruit_AMG88xx amg;
    float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

    void setup() {
      Serial.begin(115200); // Use a higher baud rate for better performance
      Wire.begin();
      if (!amg.begin()) {
        Serial.println("Could not find AMG88xx sensor!");
        while (1);
      }
      Serial.println("AMG88xx found!");
    }

    void loop() {
      amg.readPixels(pixels);
      for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        Serial.print(pixels[i]);
        if (i < AMG88xx_PIXEL_ARRAY_SIZE - 1) {
          Serial.print(","); // Separate pixel values with a comma
        }
      }
      Serial.println(); // Newline after each frame
      delay(100); // Adjust delay as needed
    }