#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int LB[n], RS[n];
	LB[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > LB[i - 1]) {
			LB[i] = a[i];
		} else {
			LB[i] = LB[i - 1];
		}
	}
	RS[n - 1] = 1000000001;
	for (int i = n -2; i >= 0; i--) {
		if (a[i] < RS[i + 1]) {
			RS[i] = a[i];
		} else {
			RS[i] = RS[i + 1];
		}
	}
	int index = 0, ans[n];
	for (int i = 0; i < n; i++) {
		if (a[i] >= LB[i] && a[i] <= RS[i]) {
			ans[index++] = a[i];
		} 
	}
	sort(ans, ans + index);
	printf("%d\n", index);
	for (int i = 0; i < index; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}