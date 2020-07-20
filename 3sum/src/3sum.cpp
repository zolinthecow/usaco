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
#define INF 1000000000
#define MOD 1000000007

int main() {
	int N, Q;
	cin >> N >> Q;
	vi nums(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}
	vii queries(Q);
	for (int i = 0; i < Q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}
	vector< map<int, int> > pref(N + 1);
	map<int, int> temp; pref[0] = temp, pref[1] = temp;
	for (int i = 2; i <= N; i++) {
		pref[i] = pref[i - 1];
		for (int j = 1; j < i; j++) {
			pref[i][nums[i] + nums[j]]++;
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << i << ":" << endl;
		for (auto it : pref[i]) {
			cout << it.first << " " << it.second << endl;
		}
	}
	for (auto it : queries) {
		int beg = it.first, end = it.second;
		int ans = 0;
		for (int i = beg; i <= end; i++) {
			int bef = pref[i - 1][-nums[i]] - pref[beg - 1][-nums[i]];
			int aft = pref[end][-nums[i]] - pref[i][-nums[i]];
			cout << -nums[i] << " " << bef << " " << aft << endl;
			ans += bef + aft;
		}
		cout << ans << endl;
	}
}
