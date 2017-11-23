
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, Min;
	scanf("%d%d", &n, &m);
	int sum[n+1];
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	Min = sum[n];
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		// int pos = lower_bound(sum+i, sum+n+1, m+sum[i-1]) - sum;
		int middle, left = i, right = n, pos;
		while (left < right) {
			middle = (left + right) / 2;
			if (sum[middle] - sum[i-1] >= m) {
				right = middle;
			} else {
				left = middle + 1;
			}
		}
		pos = right;
		int TmpSum = sum[pos] - sum[i-1];
		if (TmpSum > Min) {
			continue;
		} 
		if (TmpSum >= m) {
			if (TmpSum < Min) {
				Min = TmpSum;
				ans.clear();
			}
			ans.push_back(i);
			ans.push_back(pos);
		}
	}
	for (int i = 0; i < ans.size(); i += 2) {
		printf("%d-%d\n", ans[i], ans[i+1]);
	}
	// for (int i = 1; i <= n; i++) {
	// 	int left = i, right = n, middle;
	// 	while (left <= right) {
	// 		middle = (left + right) / 2;
	// 		if (sum[middle] - sum[i-1] == Min) {
	// 			printf("%d-%d\n", i, middle);
	// 			break;
	// 		} else if (sum[middle] - sum[i-1] < Min) {
	// 			left = middle + 1;
	// 		} else {
	// 			right = middle - 1;
	// 		}
	// 	}
	// }
	return 0;
}