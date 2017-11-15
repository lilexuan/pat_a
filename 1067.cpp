#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn];

int main()
{
	int n;
	int right = 0, cnt = 0, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //转变一下思路，a[i]表示的是数字i所在的位置，而不是第i个位置的数字
		scanf("%d", &tmp);
		a[tmp] = i;
		if (a[i] == i) {
			right++;
		}
	}	
	while (right != n) {
		if (a[0] == 0) {
			for (int i = 1; i < n; i++) {
				if (a[i] != i) {
					swap(a[0], a[i]);
					right--;
					cnt++;
					break;
				}
			}
		}
		int index = a[0];
		swap(a[0], a[index]);
		right++;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}