#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	int HashTable[10001] = {0};
	bool HashTable2[10001] = {false};
	vector<int> vi;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		HashTable[tmp]++;
		if (!HashTable2[tmp]) {
			vi.push_back(tmp);
			HashTable2[tmp] = true;
		}
	}
	int flag = 1;
	for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
		if (HashTable[*it] == 1) {
			printf("%d\n", *it);
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("None\n");
	}
	return 0;
}