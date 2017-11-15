#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) 
{
	return a + b < b + a; // a + b 小于 b + a时，a排在前面；
}

int main()
{
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, cmp);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += s[i];
	}
	while (ans[0] == '0' && ans.size() != 0) {
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) {
		cout << 0 << endl;
	} else {
		cout << ans << endl;
	} 
	return 0;
}