#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>


int refresh_interval,beg_day_hour, beg_day_min, beg_day_sec,end_day_hour,end_day_min,end_day_sec;

int pin = PIN; //Defined in makefile during compilation

int isday(int cur_hour,int cur_min,int cur_sec,int beg_day_hour,int beg_day_min,int beg_day_sec,int end_day_hour,int end_day_min,int end_day_sec)
{
	int current_time_int = cur_hour *  10000 + cur_min * 100 + cur_sec;
	int beg_time_int = beg_day_hour * 10000 + beg_day_min * 100 + beg_day_sec;
	int end_time_int = end_day_hour * 10000 + end_day_min * 100 + end_day_sec;
	return current_time_int >= beg_time_int && current_time_int <= end_time_int;
}

int main()
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(pin,OUTPUT);
	printf("Refrech Time (In seconds) : ");
	scanf("%d",&refresh_interval);
	printf("When Your day begins ? (HH:MM:SS) : ");
	scanf("%d:%d:%d",&beg_day_hour,&beg_day_min,&beg_day_sec);
	printf("When Your day ends ? (HH:MM:SS) : ");
	scanf("%d:%d:%d",&end_day_hour,&end_day_min,&end_day_sec);
	printf("\nYour day begins at %d:%d:%d  \n",beg_day_hour,beg_day_min,beg_day_sec);
	printf("Your day ends %d:%d:%d  \n",end_day_hour,end_day_min,end_day_sec);

	while(1)
	{
		time_t rawtime;
		struct tm * timeinfo;
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		int hour = timeinfo->tm_hour;
		int minute = timeinfo->tm_min;
		int second = timeinfo->tm_sec;
		if(isday(hour,minute,second,beg_day_hour, beg_day_min, beg_day_sec,end_day_hour,end_day_min,end_day_sec))
		{
			digitalWrite(pin,LOW);
		}
		else
		{
			digitalWrite(pin,HIGH);
		}
	delay(refresh_interval * 1000);
	}
	return 0;
}
