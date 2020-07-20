#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

map<char, ii> direction = {
	{'N', ii(0, 1)},
	{'S', ii(0, -1)},
	{'E', ii(1, 0)},
	{'W', ii(-1, 0)}
};

const int mxN = 1e3 + 5;

int N, M;
int fx, fy;
int bx, by;
string fmoves, bmoves;

ii fcoord[mxN], bcoord[mxN];

int dp[mxN][mxN];

inline int dist(ii a, ii b) {
	return pow(abs(a.first - b.first), 2) +
		   pow(abs(a.second - b.second), 2);
}

int solve(int fAt, int bAt) {
	if (fAt == N && bAt == M) {
		return dist(fcoord[fAt], bcoord[bAt]);
	} else {
		int cost = (fAt == 0 && bAt == 0) ? 0 : 
			dist(fcoord[fAt], bcoord[bAt]);
		int ans = INF;
		if (fAt != N) ans = min(ans, solve(fAt + 1, bAt));
		if (bAt != M) ans = min(ans, solve(fAt, bAt + 1));
		if (fAt != N && bAt != M) ans = min(ans, solve(fAt + 1, bAt + 1));
		ans += cost;
		return ans;
	}
}

int main() {
	//setIO("radio");
	cin >> N >> M >> fx >> fy >> bx >> by >> fmoves >> bmoves;
	fcoord[0] = ii(fx, fy);
	bcoord[0] = ii(bx, by);
	for (int i = 1; i <= N; i++) {
		fcoord[i] = ii(fcoord[i - 1].first + direction[fmoves[i - 1]].first,
				  fcoord[i - 1].second + direction[fmoves[i - 1]].second);
	}
	for (int i = 1; i <= M; i++) {
		bcoord[i] = ii(bcoord[i - 1].first + direction[bmoves[i - 1]].first,
				  bcoord[i - 1].second + direction[bmoves[i - 1]].second);
	}
	cout << solve(0,0) << endl;
}
