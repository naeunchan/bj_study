#include <stdio.h>
#include <string.h>

int main(void)
{
	char n[100];
	int a[26];
	int i;
	scanf("%s", n);

	for (i = 0; i < 26; i++)
		a[i] = -1;

	for (i = 0; i < strlen(n); i++)
		if (a[n[i] - 97] == -1)
			a[n[i] - 97] = i;

	for (i = 0; i < 26; i++)
		printf("%d ", a[i]);
	return 0;
}