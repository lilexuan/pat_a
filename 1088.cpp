#include <cstdio>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

struct Fraction {
	long long up, down;
};

 Fraction reduction(Fraction a) {
 	if (a.down < 0) {
 		a.up = -a.up;
 		a.down = -a.down;
 	}
 	if (a.up == 0 && a.down != 0) {
 		a.down = 1;
 	} else {
 		long long d = gcd(abs(a.up), abs(a.down));
 		a.up /= d;
 		a.down /= d;
 	}
 	return a;
 }

Fraction FracAdd(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	result = reduction(result);
	return result;
}

Fraction FracSub(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down - a.down * b.up;
	result.down = a.down * b.down;
	result = reduction(result);
	return result;
}

Fraction FracMul(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	result = reduction(result);
	return result;
}

Fraction FracDiv(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	result = reduction(result);
	return result;
}

void Output(Fraction a) {
	bool flag = 0;
	if (a.up < 0) {
		flag = 1;	
		a.up = -a.up;
	}
	if (flag) {
		printf("(-");
	}
	if (a.down == 1) {
		printf("%lld", a.up);
	} else if (a.up > a.down) {
		printf("%lld %lld/%lld", a.up / a.down, a.up % a.down, a.down);
	} else if (a.up < a.down) {
		printf("%lld/%lld", a.up, a.down);
	}
	if (flag) {
		printf(")");
	}
	return;
}

void OutputSum(Fraction a, Fraction b, Fraction sum) {
	Output(a);
	printf(" + ");
	Output(b);
	printf(" = ");
	Output(sum);
	printf("\n");
}

void OutputDif(Fraction a, Fraction b, Fraction difference) {
	Output(a);
	printf(" - ");
	Output(b);
	printf(" = ");
	Output(difference);
	printf("\n");
}

void OutputPro(Fraction a, Fraction b, Fraction product) {
	Output(a);
	printf(" * ");
	Output(b);
	printf(" = ");
	Output(product);
	printf("\n");
}

void OutputQuo(Fraction a, Fraction b, Fraction quotient) {
	Output(a);
	printf(" / ");
	Output(b);
	printf(" = ");
	if (b.up == 0) {
		printf("Inf");
	} else {
		Output(quotient);
	}
	printf("\n");
}

int main() {
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	Fraction sum, difference, product, quotient;
	sum = FracAdd(a, b);
	difference = FracSub(a, b);
	product = FracMul(a, b);
	quotient = FracDiv(a, b);
	a = reduction(a);
	b = reduction(b);
	OutputSum(a, b, sum);
	OutputDif(a, b, difference);
	OutputPro(a, b, product);
	OutputQuo(a, b, quotient);
	return 0;
}