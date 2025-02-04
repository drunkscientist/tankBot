i upgraded my 3d printer with ramps so i had an extra board laying around i wanted to do something with. so i decided to put it in a cigar box along with 4 spare stepper motors i had, and printed some mecanum wheels for it, along with a few spare 18650s for power. serial commands tell the wheels to move, and will be partnered with an esp-cam with some modified firmware for control and vision. should actually be useful for inspection underneath vehicles, or similar ground crawling needs

construction:
- 4 stepper motors, i have 17hs4401 but most similarly sized motors work.
- control board i upgraded from:
![anet](https://github.com/user-attachments/assets/95532785-3c13-4a1d-b2c6-b21d5d85e021)
esp32-cam module of choice. custom firmware can be found https://github.com/drunkscientist/esp32cam-ready for using a ps4 controller. **note you will need sixaxistool to get the controllers mac address and change either it, or the esp firmware for proper connection
and thus had it laying around
- 3 x 18650 cells and bms
- assorted jumpers/wires and connectors, maybe a switch
- printed mecanum wheels, eventually print whole shell but until then a cigar box

connection:
![anetConnection](https://github.com/user-attachments/assets/2b7aad84-29f4-4aa3-92bf-b0ced1794df8)
esp firmware has softwareSerial, which will be connected to the ext-rx1 of the anet lcd connector, as well as power pins

