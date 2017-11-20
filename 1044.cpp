#include <cstdio>
#include <algorithm>
using namespace std;

const long long MAX = 100000;

struct chain
{
	int first, end, value;
};

int count(int first, int end, int a[])
{
	int sum = 0;
	for (int i = first; i <= end; i++) {
		sum += a[i];
	}
	return sum;
}

bool cmp(chain a, chain b)
{
	if (a.value != b.value) {
		return a.value < b.value;
	} else if (a.first != b.first) {
		return a.first < b.first;
	} else {
		return a.end < b.end;
	}
}

int main()
{
	int n, m, k = 0;
	scanf("%d%d", &n ,&m);
	int diamond[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &diamond[i]);
	}
	bool flag = false;
	chain ans[MAX];
	for (int i = 0; i < n; i++) {
		int left = i, right = n - 1, middle;
		while (left <= right) {
			middle = (right + left) / 2;
			int sum = count(i, middle, diamond);
			if (sum == m) {
				flag = true;
				ans[k].first = i + 1;
				ans[k++].end = middle + 1;
				break;
			} else if (sum > m) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
	}
	if (!flag) {
		int left, right, middle, sum;
		for (int i = 0; i < n; i++) {
			left = i;
			right = n;
			while (left < right) {
				middle = (left + right) / 2;
				sum = count(i, middle, diamond);
				if (sum > m) {
					right = middle; 
				} else {
					left = middle + 1;
				}
			}
			ans[k].value = count(i, left, diamond);
			ans[k].first = i + 1;
			ans[k++].end = left + 1;
		}
		sort(ans, ans + k, cmp);
		int min = ans[0].value, cnt = 0;
		while (ans[cnt].value == min) {
			cnt++;
		}
		k = cnt;
	}
	//printf("k=%d\n",k);
	for (int i = 0; i < k; i++) {
		printf("%d-%d\n", ans[i].first, ans[i].end);
	}
	return 0;
}
