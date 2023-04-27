# Simple-LED-Tree
This project involved creating a wire sculpture tree with WiFi-controllable LEDs using an ESP8266. 
The project features 10 lighting modes using three separate color channels, and a simple controller interface utilizing LAN connection.
While the project may not be optimized well and lacks options and an attractive interface, it was created from scratch with limited experience in C++ 
(although I do have some knowledge in C# and attempted to translate it the best I could). 

If you come across this project, feel free to take the code and improve it for your own projects!

The main components of the project include the NORDmcu ESP8266, a simple LED driver from Amazon, and brass wire for the sculpture itself. 
All of the electronics are contained within a wooden base with a slot for a power cord and USB connection, in case the code needs to be updated in the future.

To create the lighting effect, 5mm RGB LEDs were wired in parallel into the power source with properly suited resitors and activated by a MOSFET. 
The sculpture itself was used as the ground for simplicity, with each LED soldered directly to the brass wire to add support and prevent mishaps. 
Finally, the sculpture was grounded to the driver.

Overall, this project represents a fun and creative way to explore the potential of the ESP8266 and create a visually stunning wire sculpture. 
The code can be further optimized and improved upon to suit your specific needs and interests.

NOTE: code was written in Arduino IDE and does require proper set up and libraries for your board, but should be simple enough.
