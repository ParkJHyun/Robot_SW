#include <stdio.h>
#include <pigpiod_if2.h>
#include <unistd.h>

#define PIN 13

#define DutyCycle(x, range) x/(float)range*100

int main()
{ 
	char range, default_range=255, dutycycle;
	int pi;
	if((pi = pigpio_start(NULL, NULL))<0){
		fprintf(stderr, "%s\n", pigpio_error(pi));
		return 1;
	}
	set_PWM_range(pi, PIN, default_range);
	range=get_PWM_range(pi, PIN);
	printf("range : %d\n", range);
	for(int i=0; i<=range; i++)
	{
		set_PWM_dutycycle(pi, PIN, i);
		dutycycle=get_PWM_dutycycle(pi, PIN);
		time_sleep(0.1);
		printf("Dutycycle = %.1f%%\n%d / %d\n",DutyCycle(dutycycle,range),dutycycle,range);
		time_sleep(0.3);
	}
	set_PWM_dutycycle(pi, PIN, 0);

	pigpio_stop(pi);
	return 0;
}

	
