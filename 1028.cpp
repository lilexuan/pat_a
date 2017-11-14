#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{	
	int grade;
	char id[10];
	char name[10];
};

bool cmp1(student a, student b) 
{
	return	strcmp(a.id, b.id) < 0; 
}

bool cmp2(student a, student b) 
{
	if (strcmp(a.name, b.name) != 0) {
		return strcmp(a.name, b.name) < 0;
	} else {
		return strcmp(a.id, b.id);
	}
}

bool cmp3(student a, student b)
{
	if (a.grade != b.grade) {
		return a.grade < b.grade;
	} else {
		return strcmp(a.id, b.id);
	}
}

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	student s[n];
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", s[i].id, s[i].name, &s[i].grade);
	}
	if (c == 1) {
		sort(s, s + n, cmp1);
	} else if (c == 2) {
		sort(s, s + n, cmp2);
	} else {
		sort(s, s + n, cmp3);
	}
	for (int i = 0; i < n; i++) {
		printf("%s %s %d\n", s[i].id, s[i].name, s[i].grade);
	}
	return 0;
}