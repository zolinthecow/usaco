#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 252645135
#define LSOne(S) (S & (-S))
	
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e3 + 5;

int N, K;
int berries[mxN];

int main() {
	setIO("berries");
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> berries[i];
	sort(berries, berries + N, greater<int>());
	multiset<int, greater<int> > E, B;
	for (int i = 0; i < K; i++) {
		if (i < K / 2) E.insert(berries[i]);
		else           B.insert(berries[i]);
	}
	auto bBack = prev(B.end());
	auto eBack = prev(E.end());
	while(*(E.begin()) - *bBack >=  *(B.begin())) {
		int n = *bBack + 1;
		for ( ; n <= *eBack && *(E.begin()) - n >= *(B.begin()); n++) {}
		B.erase(bBack);
		B.insert(n);
		E.erase(E.begin());
		E.insert(*(E.begin()) - n);
		bBack = prev(B.end());
		eBack = prev(E.end());
	}
	int ans = 0;
	for (auto it : B) ans += it;
	cout << ans << endl;
}
