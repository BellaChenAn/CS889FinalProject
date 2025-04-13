**How to connect?**

**First Step:**  
Prepare some conductive metal foils and connect them to wires. Attach the other ends to the pins of the first ESP32-S3. Use the following pins: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12.  
Prepare some LED lights. Connect the positive leg of each LED to a resistor, then connect them to the pins of the second ESP32-S3. Use the following pins: 47, 2, 42, 41, 40, 38, 4, 5, 6, 7, 15, 39.  
Connect all the negative legs of the LEDs together and attach them to the GND pin of the ESP32-S3.

**Second Step:**  
Connect the first ESP32-S3 to your computer and upload the `TouchInputSystem` code. Be sure to modify the Wi-Fi information in the code to match your own network.  
Then connect the second ESP32-S3 to your computer and upload the `LightSystem` code.

**Third Step:**  
Once both systems are running successfully, open the Max software and load the Max patch file to start the program.

**Note:**  
Your computer and both ESP32-S3 devices must be connected to the same Wi-Fi network!
