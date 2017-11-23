#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int coin[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + n);
	bool flag = false;
	for (int i = 0; i < n-1; i++) {
		int left = i + 1, right = n, middle;
		while (left <= right) {
			middle = (left + right) / 2;
			if (coin[middle] + coin[i] == m) {
				flag = true;
				break;
			} else if (coin[middle] + coin[i] > m) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		if (flag) {
			printf("%d %d\n", coin[i], coin[middle]);
			break;
		}
	}
	if (!flag) {
		printf("No Solution\n");
	}
	return 0;
}