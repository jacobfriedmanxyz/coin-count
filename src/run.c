#include "run.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(Config config)
{
	int cash[15];
	int cash_len;
	char curr[5];

	if (config.currency == EUR) {
		cash[0]=50000; cash[1]=20000; cash[2]=10000; cash[3]=5000;
		cash[4]=2000; cash[5]=1000; cash[6]=500; cash[7]=200;
		cash[8]=100; cash[9]=50; cash[10]=20; cash[11]=10;
		cash[12]=5; cash[13]=2; cash[14]=1;
		cash_len = 15;
		strncpy(curr, "EUR", 4);
	}
	else if (config.currency == USD) {
		cash[0]=10000; cash[1]=5000; cash[2]=2000; cash[3]=1000;
		cash[4]=500; cash[5]=200; cash[6]=100;  cash[7]=50;
		cash[8]=25; cash[9]=10; cash[10]=5; cash[11]=1;
		cash_len = 12;
		strncpy(curr, "USD", 4);
	}

	int total = 0;
	printf("\n");
	for (int i = 0; i < cash_len; i++) {
		printf("%6.2f: ", cash[i] / 100.0);

		char input[512];
		fgets(input, 512, stdin);
		int number = atoi(input);

		total += number * cash[i];
		printf("               = %6.2f %s\n", total / 100.0, curr);
	}
}
