#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <functional>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define ms(a,b) memset(&a,b,sizeof a);
#define mc(a,b) memcpy(&a,b,sizeof(a));

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("stampede.in");
	fout.open("stampede.out");
	int cowAmount;
	vector< pair< ii , int> > cows;
	map< int,vi > cowTimes;
	fin >> cowAmount;
	for (int i = 0; i < cowAmount; i++) {
		ii temp; int temp1;
		fin >> temp.first >> temp.second >> temp1;
		cows.pb(pair<ii,int>(temp,temp1));
		for (int j = (abs(temp.first) - 1) * temp1; j <= (abs(temp.first) + 1) * temp1; j++) {
			cowTimes[j].pb(i);
		}
	}
	int ans = 0;
	bool *used = new bool[cowAmount];
	for (map<int,vi>::iterator it = cowTimes.begin(); it != cowTimes.end(); it++) {
		int cowVisible = (*it).second.front();
		vi temp = (*it).second;
		for (int j = 1; j < (int)temp.size(); j++) {
			if (cows[cowVisible].first.second > cows[j].first.second && !used[j]) {
				cowVisible = j;
			}
		}
		if (!used[cowVisible]) {
			ans++;
			used[cowVisible] = true;
		}
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
