#include <stdio.h>

int main(void)
{
	int A, B, V, cnt = 0;

	scanf("%d %d %d", &A, &B, &V);

	cnt = (V - B - 1) / (A - B) + 1;
	printf("%d", cnt);
	return 0;
}