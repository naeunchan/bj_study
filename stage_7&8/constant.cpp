#include <stdio.h>

int main(void)
{
	char A[4], B[4];
	int a, b;
	scanf("%s %s", &A, &B);

	a = (A[0] - 48) + ((A[1] - 48) * 10) + ((A[2] - 48) * 100);
	b = (B[0] - 48) + ((B[1] - 48) * 10) + ((B[2] - 48) * 100);

	printf("%d", a > b ? a : b);
	return 0;
}