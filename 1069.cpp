#include <cstdio>
#include <algorithm>
using namespace std;

bool decrease(char a, char b) {
	return a > b;
}

bool increase(char a, char b) {
	return a < b;
}

bool isSame(char str[]) {
	for (int i = 0; i <= 2; i++) {
		if (str[i] != str[i + 1]) {
			return false;
		}
	}	
	return true;
}

int func(int n) {
	char str[4];
	sprintf(str, "%04d", n);
	if (isSame(str)) {
		printf("%04d - %04d = 0000\n", n, n);
		return 6174;
	}
	sort(str, str + 4, decrease);
	int a, b;
	sscanf(str, "%d", &a);
	sort(str, str + 4, increase);
	sscanf(str, "%d", &b);
	printf("%04d - %04d = %04d\n", a, b, a - b);
	return a - b;
}

int main() {
	int n;
	scanf("%d", &n);
	int ans = func(n);
	while (ans != 6174) {
		ans = func(ans);
	}
	return 0;
}