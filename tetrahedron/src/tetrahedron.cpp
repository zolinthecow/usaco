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

int **dp;
int start, moves;
vector<vi> AdjList(4);

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) AdjList[i].pb(j);
		}
	}
	cin >> start >> moves;
	dp = new int *[moves];
	start -= 1;
	for (int i = 0; i < moves; i++) {
		dp[i] = new int [4];
		for (int j = 0; j < 4; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][start] = 1;
	for (int i = 0; i < moves - 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (dp[i][j] >= 1) {
				for (int k = 0; k < (int)AdjList[j].size(); k++) {
					dp[i + 1][AdjList[j][k]] += dp[i][j];
				}
			}
		}
	}
	cout << dp[moves - 1][start];
}
