#include <stdio.h>

void Opgave3();
void Opgave5();
int Opgave6();
void main()
{
	//Opgave3();
	//Opgave5();
	Opgave6();
}

void Opgave3()
{
	float fahr, celsius;
	int laagste, hoogste, interval;

	laagste = 0;
	hoogste = 300;
	interval = 20;

	fahr = laagste;
	printf("DIT IS EEN KOP\n");
	while (fahr <= hoogste)
	{
		celsius = (5.0 / 9.0) *(fahr - 32.0);
		printf("%3.0f %6.1f\n", celsius, fahr);
		fahr = fahr + interval;
	}
}

void Opgave5()
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32));
}

	int Opgave6(int argc, char *argv[]) 
	{
		int c;
		while ((c = getchar()) != EOF) {
			printf("%d ", c != EOF);
			putchar(c);
		}
		printf("\n%d\n", c != EOF);
	}
