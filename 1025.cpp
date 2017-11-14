#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct student
{	
	string registration_number;
	int final_rank, location_number, local_rank, grade;
} s[30000];

bool cmp(student a, student b) 
{
	if (a.grade != b.grade) {
		return a.grade > b.grade;
	} else {
		return a.registration_number < b.registration_number; // 注意这里应该是小于号
	}
}

int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a = cnt;
		for (int j = 0; j < k; j++) {
			cin >> s[cnt].registration_number >> s[cnt].grade; 
			s[cnt].location_number = i;
			cnt++; 
		}
		int b = cnt;
		sort(s + a, s + b, cmp);
		for (int j = a, v = 1; j < b; j++, v++) {
			if (j != a && s[j].grade == s[j -1 ].grade) {
				s[j].local_rank = s[j - 1].local_rank;
			} else {
				s[j].local_rank = v;
			}
		}
	}
	sort(s, s + cnt, cmp);
	for (int i = 0, v = 1; i < cnt; i++, v++) {
		if (i != 0 && s[i].grade == s[i - 1].grade) {
			s[i].final_rank = s[i - 1].final_rank;
		} else {
			s[i].final_rank = v;
		}
	}	
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << s[i].registration_number << " " << s[i].final_rank << " " << s[i].location_number << " " << s[i].local_rank << endl;
	}
	return 0;
}