#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long map[512];

void init()
{
	for (char c = '0'; c <= '9'; c++) {
		map[(long long)c] = c  -'0';
	}	
	for (char c = 'a'; c <= 'z'; c++) {
		map[(long long)c] = c - 'a' + 10;
	}
}

long long ConvertDec(char number[], long long radix)
{
	long long ans = 0;
	int len = strlen(number);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + map[(long long)number[i]];
		if (ans < 0) {
			return -1;
		}
	}
		return ans;
}

long long FindLow(char number[])
{
	long long MaxNum = -1, len = strlen(number);
	for (int i = 0; i < len; i++) {
		MaxNum = max(MaxNum, map[(long long)number[i]]);
	}
	return MaxNum + 1;
}

int cmp(long long N1, char N2_number[], long long radix)
{
	long long N2 = ConvertDec(N2_number, radix);
	if (N2 < 0) {
		return -1;
	}
	if (N1 > N2) {
		return 1;
	} else if (N1 == N2) {
		return 0;
	} else {
		return -1;
	}
}

long long FindRadix(long long lowbound, long long upbound, long long N1, char N2[])
{
	long long middle, ans = -1;
	while (lowbound <= upbound) {
		middle = (lowbound + upbound) / 2;
		int flag = cmp(N1, N2, middle);
		if (flag == 1) {
			lowbound = middle + 1;
		} else if (flag == -1) {
			upbound = middle - 1;
		} else {
			ans = middle;
			break;
		}
	}
	return ans;
}

int main()
{
	init();
	char N1[11] = {0}, N2[11] = {0};
	int tag, radix;
	scanf("%s%s%d%d", N1, N2, &tag, &radix);
	if (tag == 2) {
		char tmp[11];
		strcpy(tmp, N1);
		strcpy(N1, N2);
		strcpy(N2, tmp);
	}
	long long N1_DEC = ConvertDec(N1, radix);
	long long low = FindLow(N2);
	long long high = max(low, N1_DEC) + 1;
	long long N2_radix = FindRadix(low, high, N1_DEC, N2);
	if (N2_radix == -1) {
		printf("Impossible\n");
	} else {
		printf("%lld\n", N2_radix);
	}
	return 0;
}