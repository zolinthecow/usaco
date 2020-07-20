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
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("balancing.in");
	fout.open("balancing.out");
	int cowCount;
	fin >> cowCount;
	vii cows;
	for (int i = 0 ; i < cowCount; i++) {
		ii temp;
		fin >> temp.first >> temp.second;
		cows.pb(temp);
	}
	sort(cows.begin(),cows.end());
	int answer = 1000001;
	for (int i = 0; i < cowCount; i++) {
		vii above;
		vii below;
		for (int j = 0; j < cowCount; j++) {
			if (cows[j].second >= cows[i].second) {
				above.pb(cows[j]);
			} else {
				below.pb(cows[j]);
			}
		}
		int aboveIndex = 0;
		int belowIndex = 0;
		while (belowIndex < (int)below.size() || aboveIndex < (int)above.size()) {
			int xBorder = 1000001;
			if (belowIndex < (int)below.size()) {
				xBorder = min(xBorder,below[belowIndex].first);
			}
			if (aboveIndex < (int)above.size()) {
				xBorder = min(xBorder,above[aboveIndex].first);
			}
			while (belowIndex < (int)below.size() && below[belowIndex].first == xBorder) {
				belowIndex++;
			}
			while (aboveIndex < (int)above.size() && above[aboveIndex].first == xBorder) {
				aboveIndex++;
			}
			answer = min(answer,max( max(belowIndex,(int)below.size() - belowIndex) ,max(aboveIndex,(int)above.size() - aboveIndex)));
		}
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
