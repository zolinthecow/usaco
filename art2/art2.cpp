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

const int mxN = 1e5 + 5;

int N;
int paint[mxN];

int enter[mxN], leave[mxN];

int pos[mxN];

int main() {
	//setIO("art2");
	cin >> N;
	int counter = 1;
	pos[0] = -1;
	for (int i = 0; i < N; i++) {
		cin >> paint[i];
		if (pos[paint[i]] == 0) {
			pos[paint[i]] = counter;
			counter++;
			enter[paint[i]] = i;
		}
	}
	leave[0] = -1;
	for (int i = N - 1; i >= 0; i--) {
		if (leave[paint[i]] == 0) leave[paint[i]] = i;
	}
	FenwickTree ft(N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (paint[i] == 0) continue;
		if (enter[paint[i]] == i) {
			ft.adjust(pos[paint[i]], 1);
		}
		if (leave[paint[i]] == i) {
			ans = max(ans, ft.rsq(pos[paint[i]]));
			ft.adjust(pos[paint[i]], -1);
		}
	}
	cout << ans << endl;
}
