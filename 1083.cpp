#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
	char name[20];
	char id[20];
	int grade;
};

bool cmp(student a, student b) 
{
	return a.grade > b.grade;
}

int main()
{
	int n;
	scanf("%d", &n);
	student s[n];
	for (int i = 0;i < n; i++) {
		scanf("%s%s%d", s[i].name, s[i].id, &s[i].grade);
	}
	sort(s, s + n, cmp);
	int min, max;
	scanf("%d%d", &min, &max);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].grade <= max && s[i].grade >= min) {
			printf("%s %s\n", s[i].name, s[i].id);
			cnt++;
		}
	}
	if (!cnt) {
		printf("NONE\n");
	}
	return 0;
} 