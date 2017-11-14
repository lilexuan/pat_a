#include <cstdio>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int HashTable[1001] = {0};
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		HashTable[tmp]++;
	}
	int coin = -1;
	for (int i = 0; i < 1001; i++) {
		if (HashTable[i] && HashTable[m - i] && m > i) {
			if (i == m - i && HashTable[i] >= 2) {
				coin  = i;
				break;
			} else if (i == m - i && HashTable[i] < 2) {
				continue;
			} else if (i != m - i) {
				coin = i;
				break;
			}
		}
	}
	if (coin == -1) {
		printf("No Solution\n");
	} else {
		printf("%d %d\n", coin, m - coin);
	}
	return 0;
}