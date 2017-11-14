#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake
{
	double restore, sum_price; //必须是double才可以
	double price;
	double sold_num;
};

bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	mooncake m[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf", &m[i].restore);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &m[i].sum_price);
		m[i].price = m[i].sum_price / m[i].restore;
		m[i].sold_num = 0;
	}
	sort(m, m + n, cmp);
	for (int i = 0; i < n; i++) {
		if (m[i].restore > d) {
			m[i].sold_num = d;
			break;
		} else {
			m[i].sold_num = m[i].restore;
			d -= m[i].restore;
		}
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += m[i].price * m[i].sold_num;
	}
	printf("%.2lf\n", sum);
	return 0;
}