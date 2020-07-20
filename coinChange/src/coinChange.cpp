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
	int n, v;
	cin >> n >> v;
	vi coins(n);
	int *dp = new int[v + 1];
	for (int i = 0; i < v + 1; i++) {
		dp[i] = 1000000;
	}
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 0;
	sort(coins.begin(),coins.end());
	for (int i = coins[0]; i < v + 1; i++) {
		for (int j = 0; j < n; j++) {
			dp[i] = min(dp[i],dp[i - coins[j]] + 1);
		}
	}
	cout << (dp[v] != 1000000 ? dp[v] : -1) << endl;
}
