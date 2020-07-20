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

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

const int mxN = 5e4 + 5;

int N;
int crossings[2 * mxN];

int pos[mxN];
int sums[mxN];

int main() {
	setIO("circlecross");
	cin >> N;
	for (int i = 0; i < 2 * N; i++) {
		cin >> crossings[i];
	}
	FenwickTree ft(N);
	int on = 1;
	for (int i = 0; i < 2 * N; i++) {
		if (!pos[crossings[i]]) {
			pos[crossings[i]] = on;
			sums[crossings[i]] = ft.rsq(on);
			ft.adjust(on, 1);
			on++;
		} else {
			ft.adjust(pos[crossings[i]], -1);
			sums[crossings[i]] -= ft.rsq(pos[crossings[i]]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans += sums[i];
	}
	cout << ans << endl;
}
