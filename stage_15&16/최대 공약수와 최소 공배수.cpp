#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int c;

    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(void){
    int a, b;
    int ans1 = 0, ans2 = 0;

    cin >> a >> b;

	ans1 = gcd(a, b);
	ans2 = lcm(a, b);
	
    cout << ans1 << "\n" << ans2;

    return 0;
}