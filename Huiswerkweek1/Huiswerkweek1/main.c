#include <stdio.h>
#define TNOCHAR 128  /* Total Number of characters is 128: 0 - 127 */
#define MAXLINE 1000
#define LIMIT 80


void Opgave3();
void Opgave5();
void Opgave6();
void Opgave7();
void Opgave13();
void Opgave14();
void Opgave16();
void Opgave17();
int getlineOpg16(char line[], int lim);
void copyOpg16(char to[], char from[]);
int getLineOpg17(char line[], int lim);
int weggooienOpg18(char rline[]);
int getlineOpg18(char line[], int lim);
void Opgave18();
void main()
{
	//Opgave3();
	//Opgave5();
	//Opgave6();
	//Opgave7();
	//Opgave13();
	//Opgave14();
	//Opgave16();
	//Opgave17();
	Opgave18();
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



void Opgave6() 
{
		int c;
		while ((c = getchar()) != EOF) {
			printf("%d ", c != EOF);
			putchar(c);
		}
		printf("\n%d\n", c != EOF);
	}

void Opgave7()
{
	printf("De waarde van EOF is %d ", EOF);
}

void Opgave13()
{
		int c;

		while ((c = getchar()) != EOF)
		{

			if (c == '\n' )
				putchar('\n');
			else
				putchar('*');
		}
}

void Opgave14()
{
 //snap het niet
}


void Opgave16()
{
	int len, max;
	char line[MAXLINE], maxline[MAXLINE];

	max = 0;

	while ((len = getlineOpg16(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copyOpg16(maxline, line);
		}
	}

	if (max>0) printf("%s", maxline);
}


int getlineOpg16(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

void copyOpg16(char to[], char from[])
{
	int i;
	i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}

void Opgave17()
{
	int len;
	char line[MAXLINE];

	while ((len = getLineOpg17(line, MAXLINE)) > 0)
	{
		if (len > LIMIT)
			printf("%s", line);
	}
}

int getLineOpg17(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}


void Opgave18()
{
	int len;
	char line[MAXLINE];

	while ((len = getlineOpg18(line, MAXLINE))>0)
		if (weggooienOpg18(line) > 0)
			printf("%s", line);

	return 0;
}

int getlineOpg18(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}


int weggooienOpg18(char s[])
{
	int i;

	for (i = 0; s[i] != '\n'; ++i);--i; 

	for (i > 0; ((s[i] == ' ') || (s[i] == '\t')); --i);

	if (i >= 0)
	{
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}
