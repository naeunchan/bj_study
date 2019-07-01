#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[1000000];
	int cnt[26] = { 0, }, tmp = 0, max = -1;

	scanf("%s", S);
	for (int i = 0; i < strlen(S); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (S[i] == (97 + j) || S[i] == (65 + j))
			{
				cnt[j]++;
				if (max < cnt[j])
				{
					max = cnt[j];
					tmp = j;
				}
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (i != tmp && max == cnt[i])
		{
			printf("?");
			return 0;
		}
	}
	printf("%c", 65 + tmp);

	return 0;
}