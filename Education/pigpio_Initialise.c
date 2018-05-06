#include <stdio.h>
#include <pigpio.h>

int main()
{
	int pigpio_version;

	pigpio_version = gpioVersion();
	printf("pigpio version : %d\n", pigpio_version);

	if(gpioInitialise() == 64)
		printf("pigpio Initialise OK\n");
    else
		printf("pigpio Initialise Failed\n");	

	gpioTerminate();
	return 0;
}
