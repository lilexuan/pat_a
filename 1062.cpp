#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct student {
	char number[9];
	int De;
	int Cai;
	int type;
};

bool cmp(student a, student b) 
{
	if ((a.De + a.Cai) != (b.De + b.Cai)) {
		return (a.De + a.Cai) > (b.De + b.Cai);
	} else if (a.De != b.De) {
		return a.De > b.De;
	} else {
		return strcmp(a.number, b.number) < 0;
	}
}

int main()
{
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	student s[N];
	int TypeCnt[5];
	fill(TypeCnt, TypeCnt + 5, 0); 
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d", s[i].number, &s[i].De, &s[i].Cai);
		if (s[i].De < L || s[i].Cai < L) {
			s[i].type = 0;	
			TypeCnt[0]++;
		} else if (s[i].De >= H && s[i].Cai >= H) {
			s[i].type = 1;
			TypeCnt[1]++;
		} else if (s[i].De >= H && s[i].Cai < H) {
			s[i].type = 2;
			TypeCnt[2]++;
		} else if (s[i].De < H && s[i].Cai < H && s[i].De >= s[i].Cai ) {
			s[i].type = 3;
			TypeCnt[3]++;
		} else {
			s[i].type = 4;
			TypeCnt[4]++;
		}
	}
	student s1[TypeCnt[1]], s2[TypeCnt[2]], s3[TypeCnt[3]], s4[TypeCnt[4]];
	int j = 0, k = 0, u = 0, v = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].type == 1) {
			s1[j++] = s[i];
		} else if (s[i].type == 2) {
			s2[k++] = s[i];
		} else if (s[i].type == 3) {
			s3[u++] = s[i];
		} else if (s[i].type == 4) {
			s4[v++] = s[i];
		}
	}
	sort(s1, s1 + j, cmp);
	sort(s2, s2 + k, cmp);
	sort(s3, s3 + u, cmp);
	sort(s4, s4 + v, cmp);
	printf("%d\n", TypeCnt[1] + TypeCnt[2] + TypeCnt[3] + TypeCnt[4]);
	for (int i = 0; i < j; i++) {
		printf("%s %d %d\n", s1[i].number, s1[i].De, s1[i].Cai);
	}
	for (int i = 0; i < k; i++) {
		printf("%s %d %d\n", s2[i].number, s2[i].De, s2[i].Cai);
	}
	for (int i = 0; i < u; i++) {
		printf("%s %d %d\n", s3[i].number, s3[i].De, s3[i].Cai);
	}
	for (int i = 0; i < v; i++) {
		printf("%s %d %d\n", s4[i].number, s4[i].De, s4[i].Cai);
	}
	
	return 0;	
} 
