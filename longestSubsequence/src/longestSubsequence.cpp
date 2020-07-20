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
	int *dp = new int[n];
	vi nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
}
