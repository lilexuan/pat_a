#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
	char id[6];
	int rank, sum, perfect_num;
	int p[6];
	bool handin[6];
};

bool cmp(student a, student b) 
{
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	} else if (a.perfect_num != b.perfect_num){
		return a.perfect_num > b.perfect_num;
	} else {
		return strcmp(a.id, b.id) < 0;
	}
}

bool isComplete(student a, int k) 
{
	for (int i = 1; i <= k; i++) {
		if (a.p[i] != -1) {
			return true;
		}
	} 
	return false;
}

int id2index(char id[]) 
{
	return (id[0] - '0') * 10000 + (id[1] - '0') * 1000 + (id[2] - '0') * 100 + (id[3] - '0') * 10 + (id[4] - '0');
}

int main()
{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	int s[k + 1];
	student st[n + 1];
	for (int i = 1; i <= k; i++) { //录入成绩满分，下标从1开始
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < n + 1; i++) { // 每个学生的各题目成绩默认为-1
		fill(st[i].p, st[i].p + 6, -1);
		fill(st[i].handin, st[i].handin + 6, false);
	}
	for (int i = 0; i < m; i++) {
		char t_id[6];
		int question, mark;
		scanf("%s %d %d", t_id, &question, &mark);
		int index = id2index(t_id);
		strcpy(st[index].id, t_id);
		st[index].handin[question] = true;
		// printf("%d\n", index);
		if (mark > st[index].p[question]) {
			st[index].p[question] = mark;
		}
		// printf("i=%d\n", i);
	}

	for (int i = 0; i <= n; i++) {
		int sum = 0;
		int cnt = 0;
		for (int j = 1; j <= k; j++) {
			if (st[i].p[j] != -1) {
				sum += st[i].p[j];
			}
			if (st[i].p[j] == s[j]) {
				cnt++;
			}
		}
		st[i].sum = sum;
		st[i].perfect_num = cnt;
	}
	sort(st + 1, st + n + 1, cmp);
	st[0].rank = 0;
	for (int i = 1; i < n + 1; i++) {
		if (st[i].sum == st[i - 1].sum) {
			st[i].rank = st[i - 1].rank;
		} else {
			st[i].rank = i;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (isComplete(st[i], k)) {
			printf("%d %s %d", st[i].rank, st[i].id, st[i].sum);
			for (int j = 1; j <= k; j++) {
				if (st[i].p[j] != -1) {
					printf(" %d", st[i].p[j]);
				} else if (!st[i].handin[j]){
					printf(" -");
				} else {
					printf(" 0");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
