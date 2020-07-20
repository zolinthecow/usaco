#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxH = 1e3 + 5, mxG = 1e3 + 5;

int H, G;
ii hols[mxH], guers[mxG];

int dp[mxH][mxG][2];

inline int dist(ii a, ii b) { 
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int calc(int hUsed, int gUsed, int on) {
	int ans;
	if (dp[hUsed][gUsed][on] != -1) return dp[hUsed][gUsed][on];
	if (hUsed == H && gUsed != G) {
		return INF;
	} else if (hUsed == H && gUsed == G) {
		ans = 0;
	} else {
		int ret = INF;
		//increase hUsed by one
		if (hUsed + 1 <= H) {
			if (on == 0) {
				//on hols
				ret = min(ret, dist(hols[hUsed], hols[hUsed + 1])
					+ calc(hUsed + 1, gUsed, 0));
			} else {
				//on guers
				ret = min(ret, dist(guers[gUsed], hols[hUsed + 1]) 
					+ calc(hUsed + 1, gUsed, 0));
			}
		}
		//increase gUsed by one
		if (gUsed + 1 <= G) {
			if (on == 0) {
				// on hols
				ret = min(ret, dist(hols[hUsed], guers[gUsed + 1]) 
					+ calc(hUsed, gUsed + 1, 1));
			} else {
				//on guers
				ret = min(ret, dist(guers[gUsed], guers[gUsed + 1])
					+ calc(hUsed, gUsed + 1, 1));
			}
		}
		ans = ret;
	}
	dp[hUsed][gUsed][on] = ans;
	return ans;
}

int main() {
	setIO("checklist");
	cin >> H >> G;
	for (int i = 1; i <= H; i++) {
		cin >> hols[i].first >> hols[i].second;
	}
	for (int i = 1; i <= G; i++) {
		cin >> guers[i].first >> guers[i].second;
	}
	hols[0] = hols[1];
	guers[0] = guers[1];
	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= G; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	int startH = calc(1, 0, 0);
	cout << startH << endl;
}
