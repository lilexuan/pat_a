#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 99999999;
int n, a[maxn], b[maxn], c[maxn];
bool flag = false;

void showArray(int a[])
{
	for (int i = 0; i < n; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", a[i]);
	} 
	printf("\n");
}

bool isSame(int a[], int b[])
{
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;	
		}
	}
	return true;
}

void mergeSort(void) 
{
	for (int step = 2; step <= n; step *= 2) {
		if (step != 2 && isSame(a, b)) {
			flag = true;
		}
		for (int i = 0; i < n; i += step) {
			sort(a + i , a + min(i + step, n));
		}
		if (flag) {
			printf("Merge Sort\n");
			showArray(a);
			return;
		}
	}
}

void insertSort(void) 
{
	bool fflag = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(c, b)) {
			fflag = true;
		}
		int temp = c[i], j = i;
		while (j > 0 && c[j - 1] > temp) {
			c[j] = c[j - 1];
			j--;
		}
		c[j] = temp;
		if (fflag) {
			printf("Insertion Sort\n");
			showArray(c);
			return;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	mergeSort();
	if (!flag) {
		insertSort();
	}
	return 0;
}