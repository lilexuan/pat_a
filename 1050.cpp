#include <cstdio>
#include <cstring>

int main()
{
	char s1[10001];
	char s2[10001];
	gets(s1);
	gets(s2);
	bool HashTable[512] = {false};
	for (int i = 0; i < strlen(s2); i++) {
		HashTable[s2[i]] = true;
	}
	for (int i = 0; i < strlen(s1); i++) {
		if (HashTable[s1[i]] == false) {
			printf("%c", s1[i]);
		}
	}
	return 0;
}