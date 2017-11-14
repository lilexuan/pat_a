#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main()
{
	int HashTable1[256] = {0};
	int HashTable2[256] = {0};
	char s1[1010];
	char s2[1010];
	scanf("%s%s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	set<char> st;
	for (int i = 0; i < len1; i++) {
		HashTable1[s1[i]]++;
	}
	for (int i = 0; i < len2; i++) {
		HashTable2[s2[i]]++;
		st.insert(s2[i]);
	}
	int flag = 0, num = 0;
	for (set<char>::iterator it = st.begin(); it != st.end(); it++) {
		int dif = HashTable2[*it] - HashTable1[*it];
		if (dif > 0) {
			if (!flag) {
				flag = 1;
			}
			num += dif;
		}
	}
	if (flag) {
		printf("No %d\n", num);
	} else {
		printf("Yes %d\n", len1 - len2);
	}
	return 0;
}