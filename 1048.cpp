#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int coin[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + n, cmp);
	//test
	// for (int i = 0; i < n; i++) {
	// 	printf(" %d", coin[i]);
	// }
	// printf("\n");
	int flag = 1;
	int v1, v2;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (coin[i] + coin[j] == m) {
				flag = 0;
				v1 = coin[i];
				v2 = coin[j];
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (flag) {
		printf("No Solution\n");
	} else {
		printf("%d %d\n", v1, v2);
	}
	return 0;
}