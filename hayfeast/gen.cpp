#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxN = 1e5, mxM = 1e18, mxF = 1e9, mxS = 1e9;

ll rand(ll a, ll b) {
	return a + rand() % (b - a + 1);
}
int main(int argc, char* argv[]) {
	setIO();
	srand(atoi(argv[1]));
	ll N = rand(1, mxN), M = rand(1, mxM);
	cout << N << " " << M << endl;
	for (ll i = 0; i < N; i++) {
		cout << rand(1, mxF) << " " << rand(1, mxS) << endl;
	}
}
