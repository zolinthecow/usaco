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
	int n, maxWeight;
	cin >> n >> maxWeight;
	vii nums;
	int **dp = new int *[n + 1];
	for (int i = 0; i < n; i++) {
		ii temp;
		cin >> temp.first >> temp.second;
		nums.pb(temp);
	}
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new int[maxWeight + 1];
		for (int j = 0; j < maxWeight + 1; j++) {
			dp[i][j] = 0;
		}
	}
	dp[1][maxWeight - nums[0].first] = nums[0].second;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < maxWeight + 1; j++) {
			if (j - nums[i].first >= 0) {
				dp[i + 1][j] = max(dp[i][j - nums[i].first] + nums[i].second,dp[i][j]);
			} else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < maxWeight + 1; j++) {
		ans = max(ans,dp[n][j]);
	}
	cout << ans << endl;
}
