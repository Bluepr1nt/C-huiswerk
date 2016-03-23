#include <stdio.h>
#define TNOCHAR 128  /* Total Number of characters is 128: 0 - 127 */
#define MAXLINE 1000
#define LIMIT 80
#define TABINC 8


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
void Opgave20();
void Opgave21();
int mgetlineOpg2p4(char line[], int maxline);
void squeezeOpg2p4(char s1[], char s2[]);
void Opgave2p4();
int mgetlineOpg2p5(char line[], int maxline);
int anyOpg2p5(char s1[], char s2[]);
void Opgave2p5();
unsigned invertOpg2p7(unsigned x, int p, int n);
void Opgave2p7();
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
	//Opgave18();
	//Opgave20();
	//Opgave21();
	//Opgave2p4();
	//Opgave2p5();
	Opgave2p7();
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


void Opgave20()
{
	int nb, pos, c;

	nb = 0;
	pos = 1;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nb = TABINC - ((pos - 1) % TABINC);

			while (nb > 0)
			{
				putchar('n');
				pos++;
				nb--;
			}
		}
		else if (c == '\n')
		{
			putchar(c);
			pos = 1;
		}
		else
		{
			putchar(c);
			pos++;
		}
	}
}

void Opgave21()
{
	int nb, nt, pos, c;

	nb = 0;
	nt = 0;

	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ')
		{
			if ((pos % TABINC) != 0)
				nb++;
			else
			{
				nb = 0;
				nt++;
			}
		}
		else
		{
			for (; nt > 0; --nt)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else
				for (; nb > 0; nb--)
					putchar(' ');

			putchar(c);

			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
		}

	return 0;
}




void Opgave2p4()
{
	char s1[MAXLINE], s2[MAXLINE];

	putchar('s');
	putchar('1');
	mgetlineOpg2p4(s1, MAXLINE);

	putchar('s');
	putchar('2');
	mgetlineOpg2p4(s2, MAXLINE);

	squeezeOpg2p4(s1, s2);

	printf("%s", s1);

}

int mgetlineOpg2p4(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
}

void squeezeOpg2p4(char s1[], char s2[])
{
	int i, j, k;
	k = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; j++)
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}

	s1[k] = '\0';
}

void Opgave2p5()
{
	char s1[MAXLINE], s2[MAXLINE];
	int val;

	mgetlineOpg2p5(s1, MAXLINE);

	mgetlineOpg2p5(s2, MAXLINE);

	val = anyOpg2p5(s1, s2);

	printf("%d", val);
}

int mgetlineOpg2p5(char s[], int lim)
{
	int i, c;
	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
}

int anyOpg2p5(char s1[], char s2[])
{
	int i, j, check_next_char;

	check_next_char = 1;

	for (i = 0; s1[i] != '\0' && (check_next_char);)
	{
		for (j = 0; s2[j] != '\0' && (s1[i] != s2[j]); j++);

		if (s2[j] == '\0') {
			check_next_char = 1;
			i++; 
		}
		else
			check_next_char = 0; 
	}
	if (s1[i] == '\0')
		return -1;
	else
		return i;
}

void Opgave2p7()
{
	printf("%u", (unsigned)invertOpg2p7((unsigned)8, (int)3, (int)3));
}

unsigned invertOpg2p7(unsigned x, int p, int n)
{
	return   x ^ (~(~0 << n) << (p + 1 - n));
}