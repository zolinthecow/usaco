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

const int mxN = 2e2 + 5;

int N;
ii vertices[mxN];

int totalDist = 0;

int toExit[mxN];
vi pathAround;

int twoPointsDist(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int minDistToExit(int on) {
	int ans = 0;
	for (int i = on; i < N; i++) {
		int nextI = (i + 1 == N) ? 0 : i + 1;
		ans += twoPointsDist(vertices[i], vertices[nextI]);
	}
	return min(ans, totalDist - ans);
}

bool canStillIterate(vi toBeIterated) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		count += (toBeIterated[i] >= 0) ? 1 : 0; 
	}
	return count > 1;
}

int main() {
	setIO("lightsout");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> vertices[i].first >> vertices[i].second;
	}
	for (int i = 0; i < N; i++) {
		int nextI = (i + 1 == N) ? 0 : i + 1;
		totalDist += twoPointsDist(vertices[i], vertices[nextI]);
	}
	pathAround.resize(1, 0);
	for (int i = 0; i < N; i++) {
		int j = (i + 1) % N;
		int k = (i + 2) % N;
		pathAround.push_back(abs(vertices[i].first - vertices[j].first) +
                abs(vertices[i].second - vertices[j].second));
		if ((vertices[i].first - vertices[j].first) * 
			(vertices[k].second - vertices[j].second) -
			(vertices[k].first - vertices[j].first) * 
			(vertices[i].second - vertices[j].second) > 0) {
			pathAround.push_back(-1);
		} else {
		  pathAround.push_back(-2);
		}
		toExit[i] = minDistToExit(i);
	}
	toExit[N] = 0;
	pathAround.back() = 0;
	multiset<vi> paths;
	for (int i = 0; i + 2 < (int) pathAround.size(); i += 2) {
		for (int j = i + 1; j <= (int) pathAround.size(); j += 2) {
			paths.insert(vector<int>(pathAround.begin() + i, 
				pathAround.begin() + j));
		}
	}
	int ans = 0;
	for (int i = 2; i + 2 < (int) pathAround.size(); i += 2) {
		int moveClockwise = 0;
		int j;
		for (j = i + 1; ; j += 2) {
			if (paths.count(vector<int>(pathAround.begin() + i, 
				pathAround.begin() + j)) == 1) {
				break;
			}
			moveClockwise += pathAround[j];
		}
		ans = max(ans, moveClockwise + toExit[j / 2] - 
			toExit[i / 2]);
	}
	cout << ans << endl;
}
