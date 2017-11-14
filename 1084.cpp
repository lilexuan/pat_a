#include <cstdio>
#include <cstring>

int main()
{
	char s1[82];
	char s2[82];
	scanf("%s%s", s1, s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	bool HashTable[128] = {false};
	for (int i = 0; i < len1; i++) {
		char c1 = s1[i];
		if ('a' <= c1 && c1 <= 'z') {
			c1 -=32;
		}
		int flag = 0;
		for (int j = 0; j < len2; j++) {
			char c2 = s2[j];
			if ('a' <= c2 && c2 <= 'z') {
				c2 -= 32;
			}
			if (c1 == c2) {
				flag = 1;
				break;
			}
		}
		if (!flag && !HashTable[(int)c1]) {
			printf("%c", c1);
			HashTable[(int)c1] = true;
		}
	}
	return 0;
}