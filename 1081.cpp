#include <cstdio>
#include <cmath>
using namespace std;

struct Fraction {
	long long up, down;
};

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

Fraction reduction(Fraction a) {
	if (a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
	if (a.up == 0) {
		a.down = 1;
	} else {
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}

Fraction FracAdd(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down * b.down;
	result = reduction(result);
	return result;
}

int main() {
	int n;
	scanf("%d", &n);
	Fraction F[n], sum;
	sum.up = 0;
	sum.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &F[i].up, &F[i].down);
		sum = FracAdd(sum, F[i]);
	}
	if (sum.down == 1) {
		printf("%lld\n", sum.up);
	} else if (sum.down > sum.up) {
		printf("%lld/%lld\n", sum.up, sum.down);
	} else if (sum.down < sum.up) {
		printf("%lld %lld/%lld\n", sum.up / sum.down, sum.up % sum.down, sum.down);
	}
	return 0;
}