# Adafruit-AMG8833-Arduino-Nano
Using an arduino nano and an adafruit AMG8833 grideye thermal camera with Processing.  
Downloading the adafruit AMG88xx library in Arduino IDE is required, and the example files used are listed in the Adafruit Library folder.  
Downloading the Serial library in Processing is required as well.  
*I did not write any of the example scripts, those come with the libraries*  

Processing can be downloaded at https://processing.org/download  
Arduino IDE can be downloaded at https://www.arduino.cc/en/software

The AMG8833 should be wired to the Nano in the following way:
* VIN to 5V
* GND to GND
* SDA to A4
* SCL to A5

After wiring the camera to the Nano (correctly...), uploading the amg88xx_test file in the library folder to your arduino ensures that everything is working fine.  
In addition, you can do the same with the pixels_test file in order to look at the way the data changes when objects of differing temperature pass in front of the camera.  

Once you have confirmed that everything is wired correctly and transmitting the correct data, open Processing and Arduino IDE.  
1. Upload the pixel_data.ino file to your Arduino.  
1. In your Processing sketch, copy and paste the code from thermal_visualizer.pde, and run it.  
1. This should display a grid of squares of varying colors that change colors as objects of different temperatures pass in front of it.

We're done! This is a very simple project, but may seem complicated if you are not aware of how serial ports work in sending data.  

If the .ino files are not uploading to your arduino, try switching to "old bootloader" in your Tools > Processor section of the Arduino IDE.  
There will definitely be issues if you do not install the required libraries for both Arduino IDE and Processing.  
There may also be issues if the wrong port is selected.  

By default, the first available port is selected. Most likely this will be the correct port, but if not, you can look at the console in the Processing IDE to view the names of all available ports.  
Either plug your arduino into whichever port is first, or change the value of the variable portName in thermal_visualizer.pde to whichever place your desired port has in the console of the Processing IDE. 
