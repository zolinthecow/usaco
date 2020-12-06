#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N;
vii xRange, yRange;

int main() {
	int N;
	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 1; i <= N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		xRange.pb(ii(x1, i)); xRange.pb(ii(x2, i));
		yRange.pb(ii(y1, i)); yRange.pb(ii(y2, i));
	}
	sort(xRange.begin(), xRange.end());
	sort(yRange.begin(), yRange.end());
	unordered_set<int> in;
	set<ii> xIntersects;
	for (int i = 0; i < (int) xRange.size(); i++) {
		ii on = xRange[i];
		if (in.find(on.second) == in.end()) {
			
		}
	}
}
