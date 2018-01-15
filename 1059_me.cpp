#include <cstdio>
#include <cmath>

struct factor {
	int x, cnt;
} fac[10];

int prime[100010];
int primeFacotrNum = 0;
int index = 0;

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void printPrime(void) {
	for (int i = 1; i < 100010; i++) {
		if (isPrime(i)) {
			prime[index++] = i;
		}
	}
	return;
}

void findPrimeFactor(int n) {
	int i = 0;
	int sqr = (int)sqrt(1.0 * n);
	while (prime[i] <= sqr && i < index) {
		if (n % prime[i] == 0) {
			fac[primeFacotrNum].x = prime[i];
			fac[primeFacotrNum].cnt = 0;
			while (n % prime[i] == 0) {
				fac[primeFacotrNum].cnt++;
				n /= prime[i];
			}
			primeFacotrNum++;
		}
		i++;
	}
	if (n != 1) {
		fac[primeFacotrNum].x = n;
		fac[primeFacotrNum++].cnt = 1;
	}
	return;
}

void output(int n) {
	if (n == 1) {
		printf("1==1");
		return;
	}
	printf("%d=", n);
	for (int i = 0; i < primeFacotrNum; i++) {
		if (i) {
			printf("*");
		}
		printf("%d", fac[i].x);
		if (fac[i].cnt > 1) {
			printf("^%d", fac[i].cnt);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printPrime();
	findPrimeFactor(n);
	output(n);
	return 0;
}