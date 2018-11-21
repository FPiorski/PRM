#include <stdio.h>
#include <locale.h>

int main(void)
{
	float x=66.6666;
	printf("%-8.2e\n", x);
	setlocale(LC_NUMERIC, "pl_PL");
	printf("%6.0f\n", x);
	return 0;
}
