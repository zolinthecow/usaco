#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 1000000007


int main() {
	vi coins = {1, 5, 10, 25};
	int dp[26];
	for (int i = 0; i <= 25; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int i = 0; i <= 25; i++) {
		for (int j = 0; j < 4; j++) {
			if (i - coins[j] >= 0) {
				dp[i] += dp[i - coins[j]];
			}
		}
	}
	cout << dp[25] << endl;
}
