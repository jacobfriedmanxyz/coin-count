#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EUR 1
#define USD 2

const int EUROS[15] = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
const int DOLLARS[12] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1 };

typedef struct {
	int currency;
	char curr[5];
	const int *cash;
	int cash_len;
} Config;

Config configure()
{
	Config ret;

	printf(
		"Currencies: \n"
		"EUR: 1\n"
		"USD: 2\n");

	while (1) {
		char input[512];

		printf("Select currency ('q' to quit): ");
		fgets(input, 512, stdin);

		if (input[0] == 'q') {
			printf("Quitting...\n");
			exit(EXIT_SUCCESS);
		}
		else if (input[0] == '1') {
			ret.currency = EUR;
			strncpy(ret.curr, "EUR", 4);
			ret.cash = EUROS;
			ret.cash_len = 15;
			return ret;
		}
		else if (input[0] == '2') {
			ret.currency = USD;
			strncpy(ret.curr, "USD", 4);
			ret.cash = DOLLARS;
			ret.cash_len = 12;
			return ret;
		}
		else
			continue;
	}
}

int main() {
	int total = 0;
	int i;

	Config conf = configure();

	printf("\n");
	for (i = 0; i < conf.cash_len; i++) {
		char input[512];
		int number;

		printf("%6.2f: ", conf.cash[i] / 100.0);

		fgets(input, 512, stdin);
		number = atoi(input);

		total += number * conf.cash[i];
		printf("               = %6.2f %s\n", total / 100.0, conf.curr);
	}

	return 0;
}
