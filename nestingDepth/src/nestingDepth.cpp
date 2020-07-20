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
#define MOD 10000000
#define LSOne(S) (S & (-S))

int T;
string S;

int main() {
	cin >> T;
	for (int x = 1; x <= T; x++) {
		cin >> S;
		vi nums;
		for (int i = 0; i < (int)S.length(); i++) {
			nums.pb(stoi(S.substr(i, 1)));
		}
		string ans;
		int openCount = 0;
		for (auto it : nums) {
			if (it > openCount) {
				for (int i = openCount; i < it; i++) {
					ans += "(";
					openCount++;
				}
			} else if (it < openCount) {
				for (int i = openCount - 1; i >= it; i--) {
					ans += ")";
					openCount--;
				}
			}
			ans += to_string(it);
		}
		for (int i = 0; i < openCount; i++) {
			ans += ")";
		}
		cout << "Case #" << x << ": " << ans << endl;
	}
}
