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
	freopen((s + "2.out").c_str(), "w", stdout);
}

const ll mxN = 5e4 + 5;

struct vertMax {
	bool operator() (const ll& a, const ll& b) const {
		return a > b;
	}
};

ll N;
ii cows[mxN];

ii hor[mxN];

int main() {
	setIO("split");
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	ll total;
	ll hLeft = INF, hRight = 0, vDown = INF, vUp = 0;
	for (ll i = 0; i < N; i++) {
		hLeft = min(hLeft, cows[i].first);
		hRight = max(hRight, cows[i].first);
		vDown = min(vDown, cows[i].second);
		vUp = max(vUp, cows[i].second);
	}
	total = (hRight - hLeft) * (vUp - vDown);
	ll best = INF;
	for (ll z = 0; z < 2; z++) {
		for (ll i = 0; i < N; i++) {
			hor[i] = cows[i];
		}
		sort(hor, hor + N);
		ll toLeft, toRight;
		ll leftHeightMax = 0, leftHeightMin = INF;
		map<ll, ll, vertMax> rightHeightsMax;
		map<ll, ll> rightHeightsMin;
		for (ll i = 0; i < N; i++) {
			rightHeightsMax[cows[i].second]++;
			rightHeightsMin[cows[i].second]++;
		}
		for (ll i = 0; hor[i].first < hor[N - 1].first; ) {
			ll j = i + 1;
			while (j < N && hor[i].first == hor[j].first) {
				j++;
			}
			for (ll k = i; k < j; k++) {
				leftHeightMax = max(leftHeightMax, hor[k].second);
				leftHeightMin = min(leftHeightMin, hor[k].second);
				rightHeightsMax[hor[k].second]--;
				rightHeightsMin[hor[k].second]--;
				if (rightHeightsMax[hor[k].second] == 0) {
					rightHeightsMax.erase(
						rightHeightsMax.find(hor[k].second));
				}
				if (rightHeightsMin[hor[k].second] == 0) {
					rightHeightsMin.erase(
						rightHeightsMin.find(hor[k].second));
				}
			}
			toLeft = (hor[i].first - hor[0].first) * 
				(leftHeightMax - leftHeightMin);
			toRight = (hor[N - 1].first - hor[j].first) *
				(rightHeightsMax.begin() -> first - 
				rightHeightsMin.begin() -> first);
			best = min(best, toLeft + toRight);
			i = j;
		}
		for (ll i = 0; i < N; i++) {
			ll temp = cows[i].first;
			cows[i].first = cows[i].second;
			cows[i].second = temp;
		}
	}
	cout << total - best << endl;
}
