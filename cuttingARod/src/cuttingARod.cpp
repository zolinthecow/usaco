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
	int N;
	cin >> N;
	vi prices(N + 1);
	int *dp = new int [N + 1];
	for (int i = 1; i < N + 1; i++) {
		cin >> prices[i];
		dp[i] = 0;
	}
	dp[0] = 0; prices[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = prices[i];
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i],dp[i - j] + dp[j]);
		}
	}
	cout << dp[N] << endl;
}
