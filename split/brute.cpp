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

const int mxN = 5e4 + 4;

int N;
ii cows[mxN];

ii hor[mxN];

int main() {
	cin >> N;
	int mnH = INF, mxH = 0, mnV = INF, mxV = 0;
	for (int i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
		mnH = min(mnH, cows[i].first);
		mxH = max(mxH, cows[i].first);
		mnV = min(mnV, cows[i].second);
		mxV = max(mxV, cows[i].second);
	}
	int total = (mxH - mnH) * (mxV - mnV);
	int ans = 0;
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < N; i++) {
			hor[i] = cows[i];
		}
		sort(hor, hor + N);
		int left = INF, right = INF;
		for (int i = 0; i < N - 1; i++) {
			int minHeight = INF, maxHeight = 0;
			for (int j = 0; j <= i; j++) {
				minHeight = min(minHeight, hor[j].second);
				maxHeight = max(maxHeight, hor[j].second);
			}
			left = (hor[i].first - hor[0].first) * 
				(maxHeight - minHeight);
			if (left == 0) left = 1;
			minHeight = INF, maxHeight = 0;
			for (int j = i + 1; j < N; j++) {
				minHeight = min(minHeight, hor[j].second);
				maxHeight = max(maxHeight, hor[j].second);
			}
			right = (hor[N - 1].first - hor[i + 1].first) *
				(maxHeight - minHeight);
			if (right == 0) right = 1;
			ans = max(ans, total - left - right);
		}
		for (int i = 0; i < N; i++) {
			int t = cows[i].first;
			cows[i].first = cows[i].second;
			cows[i].second = t;
		}
	}
	cout << ans << endl;
}
