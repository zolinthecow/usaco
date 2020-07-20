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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("helpcross.in");
	fout.open("helpcross.out");
	int chickenAmount, cowAmount;
	fin >> chickenAmount >> cowAmount;
	vi chickens(chickenAmount); vii cows;
	for (int i = 0; i < chickenAmount; i++) {
		fin >> chickens[i];
	}
	for (int i = 0; i < cowAmount; i++) {
		ii cow;
		fin >> cow.second >> cow.first;
		cows.pb(cow);
	}
	int answer = 0;
	sort(chickens.begin(),chickens.end());
	sort(cows.begin(),cows.end());
	for (int i = 0; i < chickenAmount; i++) {
		for (int j = 0; j < (int)cows.size(); j++) {
			if (cows[j].second <= chickens[i] && chickens[i] <= cows[j].first) {
				answer++;
				cows.erase(cows.begin() + j);
				break;
			}
		}
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
