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

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxN = 1e4, mxM = 1e4;

ll N, M;
ii f, b;
string fm, bm;

ii fMoves[mxN + 1];
ii bMoves[mxM + 1];

//N = 0, S = 1, E = 2, W = 3
ll df[4] = {0, 0, 1, -1};
ll ds[4] = {1, -1, 0, 0};

ll fToll[mxN + 1];
ll bToll[mxM + 1];

ll dp[mxN + 1][mxM + 1];

inline ll distSq (ii a, ii b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main() {
	setIO("radio");
	cin >> N >> M;
	cin >> f.first >> f.second;
	cin >> b.first >> b.second;
	cin >> fm >> bm;
	for (ll i = 1; i <= N; i++) {
		if     (fm[i - 1] == 'N') fToll[i] = 0;
		else if(fm[i - 1] == 'S') fToll[i] = 1;
		else if(fm[i - 1] == 'E') fToll[i] = 2;
		else				      fToll[i] = 3;
	}
	for (ll i = 1; i <= M; i++) {
		if     (bm[i - 1] == 'N') bToll[i] = 0;
		else if(bm[i - 1] == 'S') bToll[i] = 1;
		else if(bm[i - 1] == 'E') bToll[i] = 2;
		else				      bToll[i] = 3;
	}
	fMoves[0] = f;
	bMoves[0] = b;
	for (ll i  = 1; i <= N; i++) {
		fMoves[i] = ii(fMoves[i - 1].first + df[fToll[i]], fMoves[i - 1].second + ds[fToll[i]]);
	}
	for (ll i  = 1; i <= M; i++) {
		bMoves[i] = ii(bMoves[i - 1].first + df[bToll[i]], bMoves[i - 1].second + ds[bToll[i]]);
	}
	for (ll i = 0; i <= mxN; i++) {
		for (ll j = 0; j <= mxM; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (ll i = 0; i <= N; i++) {
		for (ll j = 0; j <= M; j++) {
			ll dist = distSq(fMoves[i], bMoves[j]);
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist);
			if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist);
		}
	}
	cout << "HI" << "\n";
	cout << dp[N][M] << "\n";
}
