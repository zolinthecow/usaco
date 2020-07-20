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

struct comp{
	bool operator() (pair<ii, string> a, pair<ii, string> b) const {
		return a.first.second < b.first.second;
	}
};

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector< pair<ii, int> > activities(N);
		for (int i = 0; i < N; i++) {
			cin >> activities[i].first.first >> activities[i].first.second;
			activities[i].second = i;
		}
		sort(activities.begin(), activities.end());
		multiset<pair<ii, string>, comp> curr;
		vector<string> ans(N);
		bool cUsed = false, jUsed = false, failed = false;
		for (int i = 0; i < N; i++) {
			while (curr.size() && curr.begin() -> first.second <= activities[i].first.first) {
				if (curr.begin() -> second == "C") cUsed = false;
				else							   jUsed = false;
				curr.erase(curr.begin());
			}
			if (!cUsed) {
				ans[activities[i].second] = "C";
				curr.insert(make_pair(activities[i].first, "C"));
				cUsed = true;
			} else {
				if (!jUsed) {
					ans[activities[i].second] = "J";
					curr.insert(make_pair(activities[i].first, "J"));
					jUsed = true;
				} else {
					cout << "Case #" << x << ": IMPOSSIBLE\n";
					failed = true;
					break;
				}
			}
		}
		if (!failed) {
			cout << "Case #" << x << ": ";
			for (auto it : ans) cout << it;
			cout << "\n";
		}
	}
}
