#include <cstdio>
#include <algorithm>
using namespace std;

bool hashTable[100010];

bool isPrime(int a) {
	if (a <= 1) {
		return false;
	}
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	fill(hashTable, hashTable + 100010, false);
	int Tsize, n;
	scanf("%d%d", &Tsize, &n);
	while (isPrime(Tsize) == false) {
		Tsize++;
	}
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		int H = key % Tsize;
		if (hashTable[H] == false) {
			hashTable[H] = true;
			if (i) {
				printf(" ");
			}
			printf("%d", H);
		} else {
			int cnt = 1, flag = 0;
			while (cnt < Tsize) {
				key = key + cnt * cnt;
				H = key % Tsize;
				if (hashTable[H] == false) {
					if (i) {
						printf(" ");
					}
					printf(" %d", H);
					hashTable[H] = true;
					break;
				}
				cnt++;
			}
			if (flag == 0) {
				if (n) {
					printf(" ");
				}
				printf("-");
			}
		}
	}
	return 0;
}