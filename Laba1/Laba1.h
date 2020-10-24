#pragma once
#pragma warning( disable : 6054 )
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <clocale>


void outstring(struct company*, int);
int main(void);

struct company {
	char name[256];
	int products;
	unsigned long year_money;
	float market_part;
};
