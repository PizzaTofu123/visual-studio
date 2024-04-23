#include <stdio.h>


main() {
	printf("hello world.\n");

	int undef = 0;
	printf("\n%d\n", undef);

	printf("with a step of 10 until undef is 100\n");

	while (undef <= 100) {
		printf("\nundef is %d\n", undef);
		undef += 10;
	}

	int tempInt = 120;
	if (tempInt > undef) {
		printf("\nThe second integer is bigger than the first (%d and %d)\n", tempInt, undef);
	}

	int fah = -5;

	printf("\n%d fahrenheit is  the same as %d celcius\n", fah, (fah - 32) * 5 / 9);

	if (fah > 0 || fah == -5) {
		printf("\nTrue\n");
	}



}