#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> factor;
	int sqr = (int)sqrt(1.0 * n);
	bool sqrFlag = false;
	for (int i = 2; i <= sqr + 1; i++) {
		if (n % i == 0) {
			factor.push_back(i);
			if (!sqrFlag) {
				sqrFlag = true;
			}
		}
		printf("i=%d\n", i);
	}
	if (sqrFlag) {
		factor.push_back(n);
	}
	int maxLen = 1, len = factor.size(), nowLen = 1, position = 0, maxPosition = 0;
	for (int i = 1; i < len; i++) {
		if (factor[i] == (factor[i - 1] + 1)) {
			nowLen++;
			if (nowLen > maxLen) {
				maxLen = nowLen;
				maxPosition = position;
			}
		} else {
			nowLen = 1;
			position = i;
		}
	}
	printf("%d\n", maxLen);
	bool flag = false;
	while (maxLen--) {
		if (flag) {
			printf("*");
		}
		printf("%d", factor[maxPosition]);
		maxPosition++;
		if (!flag) {
			flag = true;
		}
	}
	return 0;
}