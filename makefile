#Defines the pin to be used
CFLAGS=-D PIN=27 
#Defines The LED Must be off
DAY_BEG_TIME=07:00:00
DAY_END_TIME=19:00:00
REFRESH_INTERVAL=2
build:led.c
	@echo Compiling led.c --> led
	@gcc led.c -l wiringPi -o led $(CFLAGS)
start:install 
	@echo Starting service
	@echo $(REFRESH_INTERVAL) $(DAY_BEG_TIME) $(DAY_END_TIME) | sudo led&
	@echo Started
stop:
	@if [ -z `pidof led` ]; then echo Service is already stopped; else echo Stopping service; sudo kill `pidof led` ;  fi	
install:build
	@echo Installing led at /usr/local/bin
	@sudo cp led /usr/local/bin
	@rm led
remove: stop 
	@echo Removing led from /usr/local/bin
	@sudo rm -r -f /usr/local/bin/led
