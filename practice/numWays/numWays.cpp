#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 5e5 + 5;

int N;
int nums[mxN];

template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	template<typename... Args> T sum(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 

int main () {
    //setIO("numWays");	
	cin >> N;
	ll totalSum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		totalSum += nums[i];
	}
	if (totalSum % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	BIT<ll, mxN> bit;
	ll sum = 0;
	for (int i = N; i >= 1; i--) {
		sum += nums[i];
		if (sum == totalSum / 3) {
			bit.upd(i, 1);
		}
	}
	ll ans = 0, cur = 0;
	for (int i = 1; i <= N - 2; i++) {
		cur += nums[i];
		if (cur == totalSum / 3) {
			ans += bit.query(i + 2, N);
		}
	}
	cout << ans << '\n';
}
