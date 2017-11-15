#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	int nc, np;
	scanf("%d", &nc);
	int coupons[nc];
	for (int i = 0; i < nc; i++) {
		scanf("%d", &coupons[i]);
	}
	scanf("%d", &np);
	int products[np];
	for (int i = 0; i < np; i++) {
		scanf("%d", &products[i]);
	}
	sort(coupons, coupons + nc, cmp);
	sort(products, products + np, cmp);
	// for (int i = 0; i < nc; i++) {
	// 	printf(" %d", coupons[i]);
	// }
	// printf("\n");
	// for (int i = 0; i < np; i++) {
	// 	printf(" %d", products[i]);
	// }
	// printf("\n");
	int sum = 0;
	for (int i = 0; i < nc && i < np; i++) {
		if (coupons[i] <= 0 || products[i] <= 0) {
			break;
		}
		sum += coupons[i] * products[i];
		// printf("a%d\n", sum);
	}
	for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0; i--, j--) {
		if (coupons[i] >= 0 || products[j] >= 0) {
			break;
		}
		sum += coupons[i] * products[j];
		// printf("b%d\n", sum);
	}
	printf("%d\n", sum);
	return 0;
}