#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, res = 0;
	char * c;
	scanf("%d", &n);
	c = (char *)malloc(sizeof(char*) * n);
	scanf("%s", c);

	for (i = 0; i < n; i++)
	{
		res += (c[i] - '0');
	}
	printf("%d\n", res);
	free(c);
	return 0;
}