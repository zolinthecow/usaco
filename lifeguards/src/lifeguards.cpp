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
#include <unordered_set>
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
	fin.open("lifeguards.in");
	fout.open("lifeguards.out");
	int guardsAmount;
	fin >> guardsAmount;
	vii lifeguards;
	for (int i = 0; i < guardsAmount; i++) {
		int startTime, endTime;
		fin >> startTime >> endTime;
		ii temp(startTime,i), temp1(endTime,i);
		lifeguards.pb(temp); lifeguards.pb(temp1);
	}
	sort(lifeguards.begin(),lifeguards.end());
	unordered_set<int> working;
	vi individualWorking(guardsAmount,0);
	int totalWorking = 0;
	for (int i = 0; i < (int)lifeguards.size(); i++) {
		if(working.find(lifeguards[i].second) == working.end()) {
			working.insert(lifeguards[i].second);
		} else {
			working.erase(lifeguards[i].second);
		}
		if (working.size() == 1) {
			auto it = working.begin();
			individualWorking[*it] += lifeguards[i + 1].first - lifeguards[i].first;
		}
		if (working.size() != 0) {
			totalWorking += lifeguards[i + 1].first - lifeguards[i].first;
		}
	}
	int ans = 0;
	for (int i = 0; i < guardsAmount; i++) {
		ans = max(ans, totalWorking - individualWorking[i]);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
