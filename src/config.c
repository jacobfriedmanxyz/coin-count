#include "config.h"
#include <stdlib.h>
#include <stdio.h>

Config configure()
{
	Config result;

	printf("Currencies: \n");
	printf("EUR: 1\n");
	printf("USD: 2\n");

	while (1) {
		printf("Select currency ('q' to quit): ");

		char input[512];
		fgets(input, 512, stdin);

		if (input[0] == 'q') {
			printf("Quitting...\n");
			exit(EXIT_SUCCESS);
		}
		else if (input[0] == '1') {
			result.currency = EUR;
			return result;
		}
		else if (input[0] == '2') {
			result.currency = USD;
			return result;
		}
		else
			continue;
	}
}
