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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("split.in");
	fout.open("split.out");
	ll N;
	cin >> N;
	vii cows(N);
	for (ll i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());
	ll *prefSumMax = new ll [N + 1]; prefSumMax[N] = 0;
	ll *prefSumMin = new ll [N + 1]; prefSumMin[N] = INF;
	for (ll i = N - 1; i >= 0; i--) {
		prefSumMax[i] = max(prefSumMax[i + 1], cows[i].second);
		prefSumMin[i] = min(prefSumMin[i + 1], cows[i].second);
	}
	ii firstCow = cows[0];
	ii lastCow = cows[N - 1];
	ll aBef = (lastCow.first - firstCow.first) * (prefSumMax[0] - prefSumMin[0]);
	set<ll, greater<ll> > maxY;
	set<ll> minY;
	ll ans = 0;
	for (ll i = 0; i < N - 1; i++) {
		maxY.insert(cows[i].second);
		minY.insert(cows[i].second);
		ll a1 = (cows[i].first - firstCow.first) * (*maxY.begin() - *minY.begin());
		ll a2 = (lastCow.first - cows[i + 1].first) * (prefSumMax[i + 1] - prefSumMin[i + 1]);
		ans = max(ans, aBef - a1 - a2);
	}
	cout << ans << endl;
	fin.close();
	fout.close();
}
