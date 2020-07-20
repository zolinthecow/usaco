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
	int n;
	cin >> n;
	vi nums(n);
	int *dp = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		dp[i] = -1000000;
	}
	dp[0] = nums[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + nums[i],nums[i]);
	}
	int ans = -1000000;
	for (int i = 0; i < n; i++) {
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
}
