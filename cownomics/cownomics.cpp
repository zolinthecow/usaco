#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 5e2 + 5, mxM = 5e2 + 5;

int N, M;
string genes[2 * mxN];

string subs[2 * mxN][mxM][mxM];

bool works(int mid) {
	string search;
	bool found;
	for (int i = 0; i < M - mid; i++) {
		found = false;
		for (int j = 0; j < N; j++) {
			search = genes[j].substr(i, mid);
			//search = subs[j][i][mid];
			for (int k = N; k < 2 * N; k++) {
				//if (search == subs[k][i][mid]) found = true;
				if (search == genes[k].substr(i, mid)) found = true;
			}
		}
		if (!found) return true;
	}
	return false;
}

int main() {
	setIO("cownomics");
	cin >> N >> M;
	for (int i = 0; i < 2 * N; i++) {
		cin >> genes[i];
	}
	//for (int i = 0; i < 2 * N; i++) {
	//	for (int j = 0; j < M - 1; j++) {
	//		subs[i][j][1] = genes[i].substr(j, 1);
	//	}
	//	for (int j = 0; j < M; j++) {
	//		for (int k = 2; k < M - j; k++) {
	//			subs[i][j][k] = subs[i][j][k - 1] + genes[i].substr(j + k - 1, 1);
	//		}
	//	}
	//}
	int mid;
	int low = 1, up = M;
	while (low < up - 1) {
		mid = low + (up - low) / 2;
		if (works(mid)) {
			up = mid;
		} else {
			low = mid;
		}
	}
	if (works(low)) cout << low << endl;
	else            cout << up << endl;
}
