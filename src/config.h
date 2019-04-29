#ifndef CONFIG_H
#define CONFIG_H

#define EUR 1
#define USD 2

typedef struct {
	int currency;
} Config;

Config configure();

#endif
