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
	int numAmount, target;
	cin >> numAmount >> target;
	vi nums(numAmount);
	for (int i = 0; i < numAmount; i++) {
		cin >> nums[i];
	}
	int **dp = new int *[numAmount + 1];
	for (int i = 0; i < numAmount + 1; i++) {
		dp[i] = new int[target + 1];
		for (int j = 0; j < target + 1; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][target] = 1;
	for (int i = 0; i < numAmount; i++) {
		for (int j = 1; j < target + 1; j++) {
			if (dp[i][j] > 0) {
				if (j - nums[i] >= 0) {
					dp[i + 1][j - nums[i]] += dp[i][j];
				}
				dp[i + 1][j] += dp[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < numAmount; i++) {
		ans += dp[i][0];
	}
	cout << ans << endl;
}
