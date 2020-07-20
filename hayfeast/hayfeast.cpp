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

const ll mxN = 1e5 + 5, mxM = 1e18 + 5;

ll N, M;
ii bales[mxN];

ll currFlav = 0;
multiset< ll, greater<ll> > mx;

ll front = 0, back = 0;

ll ans = INF;

int main() {
	setIO("hayfeast");
	cin >> N >> M;
	for (ll i = 0; i < N; i++) cin >> bales[i].first >> bales[i].second;
	for (; front < N; ) {
		for( ; front < N && currFlav < M; front++) {
			currFlav += bales[front].first;
			mx.insert(bales[front].second);
		}
		for ( ; back < N && currFlav >= M; back++) {
			ans = min(ans, *(mx.begin()));
			currFlav -= bales[back].first;
			mx.erase(mx.find(bales[back].second)); 
		}
	}
	cout << ans << endl;
}
