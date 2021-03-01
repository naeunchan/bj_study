#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b, ans = "";
	int sum = 0, up = 0;
	cin >> a >> b;
	
	if(a.size() > b.size()){
		swap(a, b);
	}	
	
	for(int i = a.size(); i < b.size(); i++){
		a = "0" + a;
	}
	
	for(int i = b.size() - 1; i >= 0; i--){
		sum = up + (a[i] - '0') + (b[i] - '0');
		
		if(sum >= 10){
			up = 1;
			ans.push_back(sum - 10 + '0');
		}
		else{
			up = 0;
			ans.push_back(sum + '0');
		}
	}
	
	if(up){
		ans.push_back('1');
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans;
	
	return 0;
}