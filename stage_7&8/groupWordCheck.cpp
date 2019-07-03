#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N, i, j, cnt = 0;
	char * s[100];
	bool ch[26] = { false, };
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		s[i] = (char *)malloc(sizeof(char *) * 101);
		scanf("%s", s[i]);
	}

	for (i = 0; i < N; i++)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != s[i][j + 1])
			{
				if (ch[s[i][j] - 97] == false)
					ch[s[i][j] - 97] = true;
				else
				{
					cnt--;
					break;
				}
			}
			j++;
		}
		cnt++;
		for (j = 0; j < 26; j++)
			ch[j] = false;
	}
	printf("%d", cnt);

	for (i = 0; i < N; i++)
		free(s[i]);

	return 0;
}