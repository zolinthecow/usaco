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
#define pb push_back

long long dp[2001];

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("wifi.in");
	fout.open("wifi.out");
	int cowCount, installationCost, transmissionCost;
	fin >> cowCount >> installationCost >> transmissionCost;
	vi cowPos(cowCount);
	for (int i = 0; i < cowCount; i++) {
		fin >> cowPos[i];
	}
	sort(cowPos.begin(),cowPos.end());
	for (int i = 1; i <= cowCount; i++) {
		dp[i] = 1000000000LL;
		for (int j = 0; j < i; j++) {
			dp[i] = min(dp[i],dp[j] + 2 * installationCost + transmissionCost * (cowPos[i - 1] - cowPos[j]));
		}
	}
	if (dp[cowCount] % 2 == 0) {
		fout << dp[cowCount] / 2 << endl;
	} else {
		fout << dp[cowCount] / 2 << ".5" << endl;
	}
	fin.close();
	fout.close();
}
