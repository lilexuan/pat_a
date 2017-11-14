#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

struct car
{
	string plate;
	int in_hh, in_mm, in_ss;
	int out_hh, out_mm, out_ss;
	bool in;
	bool out;
};

int main()
{
	int n, k, plate_num = 0;;
	cin >> n >> k;
	map<string, int> mp;
	car c[10000];
	for (int i = 0; i < 10000; i++) {
		c[i].in = false;
		c[i].out = false;
	}
	for (int i = 0; i < n ; i++) {
		string tmp_plate, status;
		int tmp_hh, tmp_mm, tmp_ss;
		cin >> tmp_plate;
		scanf("%d:%d:%d", &tmp_hh, &tmp_mm, &tmp_ss);	
		cin >> status;
		map<string, int>::iterator it = mp.find(tmp_plate);
		int index;
		if (it == mp.end()) {
			mp[tmp_plate] = plate_num;
			index = plate_num;
			plate_num++;
		} else {
			index = mp[tmp_plate];
		}
		if (status == "in") {
			c[index].in = true;
			c[index].in_hh = tmp_hh;
			c[index].in_mm = tmp_mm;
			c[index].in_ss = tmp_ss;
		} else {
			c[index].out = true;
			c[index].out_hh = tmp_hh;
			c[index].out_mm = tmp_mm;
			c[index].out_ss = tmp_ss;
		}
	}
	int valid_num = 0;
	for (int i = 0; i < plate_num; i++) {
		if (c[i].in && c[i].out) {
			valid_num++;
		}
	}
	return 0;
}