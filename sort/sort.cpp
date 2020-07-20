#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
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
int nums[mxN];
int idx[mxN];

bool idxSort(int a, int b) { return nums[a] < nums[b]; }

int main() {
	setIO("sort");
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		idx[i] = i;
	}
	sort(idx + 1, idx + N + 1, idxSort);
	int ans = 0;
	FenwickTree ft(N);
	for (int i = 1; i < N; i++) {
		ft.adjust(idx[i], 1);
		ans = max(ans, i - ft.rsq(i));
	}
	cout << max(ans, 1) << endl;
}
