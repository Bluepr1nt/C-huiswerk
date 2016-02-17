#include <stdio.h>
#include "Header.h"

void main() {
	char string = "hallo";
	
	swap(&string);
}

void swap(char * p) {
	char temp[(sizeof(p)/sizeof(char))];
	printf("%s", *(p+=1));
}