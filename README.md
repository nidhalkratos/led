### Description:
Are you tired turning the lights on when it is night and off otherwise ? Why don't you use your raspbery pi to automate this process.
This tool will handle the light switching automatically, all you need to do is to specify when you want it to be off and it will do the rest.
###Installation + Running:
Clone the repository then edit the makefile to set your day interval (When you want the LED to be off) as well as the PIN number.  
To build the program run ``` make ```
To start the service run ``` make start ```  
To stop the srevice run  ``` make stop ```  
To install the service ``` make install ```  
To uninstall the service ``` make remove ```  
###Notes:
This script was tested on a raspberry pi 3 running debian based linux.
Pin Numbering uses GPIO numbering. (PIN 27 is the default pin for this project but can be changed at the makefile)
This project requires wiringPi library , Find it at http://wiringpi.com/download-and-install/
