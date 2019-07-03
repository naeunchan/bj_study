#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[1000001];
	int cnt = 0, i;
	fgets(s, sizeof(s), stdin);

	for (i = 0; i < sizeof(s); i++)
	{
		if (s[i] == ' ')
			cnt++;
		if (s[i] == '\n')
			break;
	}
	if (s[0] != ' ')
		cnt++;
	if (s[i - 1] == ' ')
		cnt--;
	printf("%d", cnt);

	return 0;
}