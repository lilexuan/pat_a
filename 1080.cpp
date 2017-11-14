#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct student
{
	int Ge, Gi, Gl, rank, id;
	int AppSc[5];
};

bool cmp(student a, student b)
{
	if (a.Gl != b.Gl) {
		return a.Gl > b.Gl;
	} else {
		return a.Ge > b.Ge;
	}
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int SchoolAdmitNum[m];
	set<int> SchoolAdmission[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &SchoolAdmitNum[i]);
	}
	student s[n];
	for (int i = 0; i < n; i++) {
		int Ge_temp, Gi_temp;
		scanf("%d%d", &Ge_temp, &Gi_temp);
		s[i].Ge = Ge_temp;
		s[i].Gi = Gi_temp;
		s[i].Gl = Ge_temp + Gi_temp;
		s[i].id = i;
		for (int j = 0; j < k; j++) {
			scanf("%d", &s[i].AppSc[j]);
		}
	}
	sort(s, s + n, cmp);
	s[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (s[i].Gl == s[i - 1].Gl && s[i].Ge == s[i - 1].Ge) {
			s[i].rank = s[i - 1].rank;
		} else {
			s[i].rank = i + 1;
		}
	}
	//test
	// printf("--------------test----------------\n");
	// for (int i = 0; i < n; i++) {
	// 	printf("id=%d rank=%d school=", s[i].id, s[i].rank);
	// 	for (int j = 0; j < k; j++) {
	// 		printf("%d ", s[i].AppSc[j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("--------------test----------------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int school_num = s[i].AppSc[j];
			int last_school;
			if (SchoolAdmission[school_num].size() < SchoolAdmitNum[school_num]) {
				SchoolAdmission[school_num].insert(s[i].id);
				last_school = school_num;
				break;
			} else if (i) {
				if (s[i].rank == s[i - 1].rank && last_school == school_num) {
					SchoolAdmission[school_num].insert(s[i].id);
					break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (SchoolAdmission[i].size()) {
			for (set<int>::iterator it = SchoolAdmission[i].begin(); it != SchoolAdmission[i].end(); it++) {
				if (it != SchoolAdmission[i].begin()) {
					printf(" ");
				}
				printf("%d", *it);
			}
			printf("\n");
		} else {
			printf("\n");
		}
	}
	return 0;
}