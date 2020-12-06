#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 200000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

inline ll calc(ll x, ll y) { return (2019201913 * x + 2019201949 * y) % 2019201997; }

int main() {
	ll i = 7001;
	ll prev = INF;
	cout << calc(7499, 7500) << endl;
	cout << calc(7500, 7499) << endl;
	cout << calc(1, 7500) << endl << calc(2, 7500) << endl << calc(3, 7500) << endl;
	cout << calc(1, 2) << endl << calc(2, 1) << endl;
	while (calc(7000, i) < prev && i <= 7500) i++;
	cout << i << endl;
	for (int j = 1; j <= 7500; j++) 
		for (int k = 1; k < j; k++) 
			if (calc(j, k) > calc(k, j)) cout << j << " " << k << endl;
	//for (ll i = 3; i <= 50; i++) cout << calc(2, i) << endl;
}
