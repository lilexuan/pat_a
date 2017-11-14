//不知道为什么最后一个测试点过不去
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;


int toll[24];

struct user
{
	string name;
	int month, day, hour, minute;
	bool online;	
};

bool cmp(user a, user b) 
{
	if (a.name != b.name) {
		return a.name < b.name;
	} else if (a.month != b.month) {
		return a.month < b.month;
	} else if (a.day != b.day) {
		return a.day < b.day;
	} else if (a.hour != b.hour) {
		return a.hour < b.hour;
	} else if (a.minute != b.minute) {
		return a.minute < b.minute;
	} else {
		return true;
	}
}

int CntTime(user a, user b) 
{
	int cnt = 0;
	while (a.day < b.day || a.hour < b.hour || a.minute < b.minute) {
		a.minute++;
		if (a.minute == 60) {
			a.hour++;
			a.minute = 0;
		}
		if (a.hour == 24) {
			a.day++;
			a.hour = 0;
		}
		cnt++;
	}
	return cnt;
}

double CntMoney(user a, user b) 
{
	double money = 0;
	while (a.day < b.day || a.hour < b.hour || a.minute < b.minute) {
		a.minute++;
		money += toll[a.hour];
		if (a.minute == 60) {
			a.hour++;
			a.minute = 0;
		}
		if (a.hour == 24) {
			a.day++;
			a.hour = 0;
		}
	}
	money /= 100.0;
	return money;
}

int main()
{
	for (int i = 0; i < 24; i++) {
		cin >> toll[i];
	}
	int N;
	cin >> N;
	user u[N];
	for (int i = 0; i < N; i++) {
		cin >> u[i].name;
		scanf("%d:%d:%d:%d", &u[i].month, &u[i].day, &u[i].hour, &u[i].minute);
		string tmp;
		cin >> tmp;
		if (tmp == "on-line") {
			u[i].online = true;
		} else {
			u[i].online = false;
		}
	}
	sort(u, u + N, cmp);
	//test
	// cout << "---------------test-----------------" << endl;
	// cout << "toll" << endl;
	// for (int i = 0; i < 24; i++) {
	// 	cout << " " << toll[i];
	// }
	// cout << endl;
	// cout << "user" << endl;
	// for (int i = 0; i < N; i++) {
	// 	cout << u[i].name << " " << u[i].month << ":" << u[i].day << ":" << u[i].hour << ":" << u[i].minute << " " << u[i].online << endl;
	// }
	// cout << endl;
	// cout << "----------------test-----------------" << endl;
	user nu[N];
	int k = 0;
	for (int i = 0; i < N - 1; i++) {
		if (u[i].name == u[i + 1].name && u[i].online == true && u[i + 1].online == false) {
			nu[k] = u[i];
			nu[k + 1] = u[i + 1];
			k += 2;
		}
	}
	// test
	// cout << "-------------test-----------------" << endl;
	// for (int i = 0; i < k; i++) {
	// 	cout << nu[i].name << " " << nu[i].month << ":" << nu[i].day << ":" << nu[i].hour << ":" << nu[i].minute << " " << nu[i].online << endl;
	// }
	// cout << endl;
	// cout << "-------------test------------------" << endl;
	string now_name = "null";
	double sum = -1;
	for (int i = 0; i < k; i += 2) {
		if (nu[i].name == now_name) {
			int time = CntTime(nu[i], nu[i + 1]);
			double money = CntMoney(nu[i], nu[i + 1]);
			sum += money;
			printf("%02d:%02d:%02d %02d:%02d:%02d %.2d $%.2f\n", nu[i].day, nu[i].hour, nu[i].minute, nu[i + 1].day, nu[i + 1].hour, nu[i + 1].minute, time, money);
		} else {
			if (sum != -1) {
				printf("Total amount: $%.2f\n", sum);
			}
			cout << nu[i].name << " ";
			printf("%02d\n", nu[i].month);
			now_name = nu[i].name;
			int time = CntTime(nu[i], nu[i + 1]);
			double money = CntMoney(nu[i], nu[i + 1]);
			sum = 0; 
			sum += money;
			printf("%02d:%02d:%02d %02d:%02d:%02d %.2d $%.2f\n", nu[i].day, nu[i].hour, nu[i].minute, nu[i + 1].day, nu[i + 1].hour, nu[i + 1].minute, time, money);
		}
	}
	if (sum != -1)
		printf("Total amount: $%.2f\n", sum);
	return 0;
}