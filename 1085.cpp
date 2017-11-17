#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int Max = 1;
	for (int i = 0; i < n; i++) {
		int len = upper_bound(a + i + 1, a + n, (long long)p * a[i]) - a;
		Max = max(Max, len - i);
	}
	printf("%d\n", Max);
	return 0;
}