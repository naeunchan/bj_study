#include <stdio.h>
#include <string.h>

int main(void)
{
	int T, r;
	char S[20];

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %s", &r, S);
		for (int j = 0; j < strlen(S); j++)
		{
			for (int k = 0; k < r; k++)
				printf("%c", S[j]);
		}
		printf("\n");
	}
	return 0;
}