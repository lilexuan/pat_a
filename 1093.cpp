#include <cstdio>
#include <cstring>

const int maxn = 100001;

int main() {
	char str[maxn] = {0};
	scanf("%s", str);
	long long leftP[maxn] = {0};
	long long rightT[maxn] = {0};
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			if (str[i] == 'P') {
				leftP[i]++;
			}
		} else {
			if (str[i] == 'P') {
				leftP[i] = leftP[i - 1] + 1;
			} else {
				leftP[i] = leftP[i - 1];
			}
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		if (i == len - 1) {
			if (str[i] == 'T') {
				rightT[i]++;
			}
		} else {
			if (str[i] == 'T') {
				rightT[i] = rightT[i + 1] + 1;
			} else {
				rightT[i] = rightT[i + 1];
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'A') {
			sum += leftP[i] * rightT[i];
		}
	}
	// for (int i = 0; i < len; i++) {
	// 	printf("leftp = %lld, rightT = %lld\n", leftP[i], rightT[i]);
	// }
	int ans = sum % 1000000007;
	printf("%d\n", ans);
	return 0;
}