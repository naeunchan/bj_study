#include <stdio.h>

int main(void)
{
	int x, y, i;
	const char * day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d %d", &x, &y);

	for (i = 1; i < x; i++)
		y += month[i];
	printf("%s\n", day[y % 7]);

	return 0;
}