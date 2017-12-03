#include <cstdio>

int main() {
	int n; 
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int last = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > last) {
			sum += (a[i] - last) * 6 + 5;
			last = a[i];
		} else {
			sum += (last - a[i]) * 4 + 5;
			last = a[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}