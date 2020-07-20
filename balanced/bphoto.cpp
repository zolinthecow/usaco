#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define line pair<int, bool>
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
int heights[mxN];

int pos[mxN];
int wentTo[mxN];

bool heightSort(int a, int b) {
	return heights[a] < heights[b];
}

int main() {
	setIO("bphoto");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> heights[i];
		pos[i] = i;
	}
	FenwickTree ft(N);
	sort(pos, pos + N, heightSort);
	for (int i = 0; i < N; i++) {
		wentTo[pos[i]] = i;
	}
	int left, right;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		left = ft.rsq(wentTo[i] + 1, N);
		right = N - wentTo[i] - 1 - left;
		ft.adjust(wentTo[i] + 1, 1);
		if (max(left, right) > min(left, right) * 2) ans++;
	}
	cout << ans << endl;
}
