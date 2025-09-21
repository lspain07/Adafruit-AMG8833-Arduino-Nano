    import processing.serial.*;

    Serial myPort;
    float[] thermalPixels = new float[64]; // 8x8 sensor

    void setup() {
      size(400, 400);
      printArray(Serial.list()); // List available serial ports
      String portName = Serial.list()[0]; // Change this to your Arduino's port
      myPort = new Serial(this, portName, 115200);
      myPort.bufferUntil('\n'); // Buffer data until a newline character
    }

    void draw() {
      background(0);
      // Visualization logic will go here once data is received
      if (thermalPixels[0] != 0) { // Check if data has been received
        int pixelSize = width / 8;
        for (int y = 0; y < 8; y++) {
          for (int x = 0; x < 8; x++) {
            int index = y * 8 + x;
            float temp = thermalPixels[index];

            // Map temperature to color (example: blue for cold, red for hot)
            float hue = map(temp, 20, 35, 240, 0); // Example range 20-35°C
            colorMode(HSB, 255);
            fill(hue, 255, 255);
            rect(x * pixelSize, y * pixelSize, pixelSize, pixelSize);
          }
        }
      }
    }

    void serialEvent(Serial p) {
      String inString = p.readStringUntil('\n');
      if (inString != null) {
        inString = trim(inString); // Remove leading/trailing whitespace
        String[] pixelStrings = split(inString, ',');
        if (pixelStrings.length == 64) {
          for (int i = 0; i < pixelStrings.length; i++) {
            thermalPixels[i] = float(pixelStrings[i]);
          }
        }
      }
    }
