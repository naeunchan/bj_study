#include <iostream>
using namespace std;

int main(void)
{
	int x, y, w, h;
	int mx = 0, my = 0;

	cin >> x >> y >> w >> h;

	mx = (w - x < x ? w - x : x);
	my = (h - y < y ? h - y : y);

	if (mx < my)
		cout << mx;
	else
		cout << my;
	return 0;

}