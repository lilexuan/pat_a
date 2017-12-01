#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	double v, sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &v);
		sum += v * i * (n - i + 1); // (i - 1) * (n - i + 1) + (n - i + 1) 推导出这个结果就好了
	}
	printf("%.2lf\n", sum);
	return 0;
}