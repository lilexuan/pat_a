#include <cstdio>

const int maxn= 1000000;
int a[maxn], b[maxn];

int main() {
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	int i = 0, j = 0, index = 0, c[n + m];
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			c[index++] = a[i++];
		} else {
			c[index++] = b[j++];
		}
	}
	while (i < n) {
		c[index++] = a[i++];
	}
	while (j < m) {
		c[index++] = b[j++];
	}
	int median = (index - 1) / 2;
	printf("%d\n", c[median]);
	return 0;
}