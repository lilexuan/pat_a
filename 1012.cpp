#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
//排名并列的问题没能解决

struct student{
	string number;
	int C;
	int M;
	int E;
	int A;
	char BestRank;
};

bool init(string s, vector<string> vi) 
{
	for (vector<string>::iterator it = vi.begin(); it != vi.end(); it++) {
		if (*it == s) {
			return true;
		}
	}
	return false;
}

bool cmpA(student a, student b)
{
	if (a.A != b.A) {
		return a.A > b.A;
	} else if (a.C != b.C) {
		return a.C > b.C;
	} else if (a.M != b.M) {
		return a.M > b.M;
	} else {
		return a.E > b.E;
	}
}

bool cmpC(student a, student b)
{
	if (a.C != b.C) {
		return a.C > b.C;
	} else if (a.A != b.A) {
		return a.A > b.A;
	} else if (a.M != b.M) {
		return a.M > b.M;
	} else {
		return a.E > b.E;
	}
}

bool cmpM(student a, student b)
{
	if (a.M != b.M) {
		return a.M > b.M;
	} else if (a.A != b.A) {
		return a.A > b.A;
	} else if (a.C != b.C) {
		return a.C > b.C;
	} else {
		return a.E > b.E;
	}
}

bool cmpE(student a, student b)
{
	if (a.E != b.E) {
		return a.E > b.E;
	} else if (a.A != b.A) {
		return a.A > b.A;
	} else if (a.C != b.C) {
		return a.C > b.C;
	} else {
		return a.M > b.M;
	}
}

int main()
{
	int N, M;
	vector<string> vi;
	map<string, int> mp;;
	cin >> N >> M;
	student s[N], sA[N], sC[N], sM[N], sE[N];
	int result[N][4];
	char grade[4] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < N; i++) {
		cin >> s[i].number >> s[i].C >> s[i].M >> s[i].E;
		double aver = (s[i].C + s[i].M + s[i].E) / 3.0;
		aver = round(aver);
		s[i].A = (int)aver;
		vi.push_back(s[i].number);
		mp[s[i].number] = i;
	}
	for (int i = 0; i < N; i++)  {
		sA[i] = s[i];
		sC[i] = s[i];
		sM[i] = s[i];
		sE[i] = s[i];
	}
	sort(sA, sA + N, cmpA);
	sort(sC, sC + N, cmpC);
	sort(sM, sM + N, cmpM);
	sort(sE, sE + N, cmpE);
	for (int i = 0; i < N; i++) {
		result[mp[sA[i].number]][0] = i + 1;
		result[mp[sC[i].number]][1] = i + 1;
		result[mp[sM[i].number]][2] = i + 1;
		result[mp[sE[i].number]][3] = i + 1;
	}
	//test
	// cout << "-------------------test--------------------" << endl;
	// for (int i = 0; i < N; i++) {
		// cout << s[i].number;
		// for (int j = 0; j < 4; j++) {
			// cout << " " << result[i][j];
		// }
		// cout << endl;
	// }
	// cout << "-------------------test---------------------" << endl;
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		if (init(tmp, vi)) {
			int min = 9999;
			int k;
			for (int j = 0; j < 4; j++) {
				int tmp2 = result[mp[tmp]][j];
				if (tmp2 < min) {
					min = tmp2;
					k = j;
				}
			}
			cout << min << " " << grade[k] << endl;
		} else {
			cout << "N/A" << endl;
		}
	}
	return 0;	
} 
