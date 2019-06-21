#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	char arr[100];
	scanf("%s", arr);

	for (i = 0; i < strlen(arr); i++)
	{
		printf("%c", arr[i]);
		if (((i + 1) % 10) == 0)
			printf("\n");
	}
	return 0;
}