#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const ll INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const ll mxN = 1e5 + 5;

ll N;
ll nums[mxN];

ll lef[mxN], righ[mxN];

int bit[mxN];

void update(int pos, int val) { for (; pos <= N; pos += (pos & (-pos))) bit[pos] += val; }

int query(int pos) {
    int ans = 0;
    for (; pos; pos -= (pos & (-pos))) ans += bit[pos];
    return ans;
}
int query(int a, int b) {
	return query(b) - (a == 1 ? 0 : query(a - 1));
}

int main () {
    setIO("art2");	
	cin >> N;
	for (ll i = 1; i <= N; i++) cin >> nums[i];
	for (ll i = 1; i <= N; i++) {
		if (lef[nums[i]] == 0 && nums[i] != 0) {
			lef[nums[i]] = i;
			update(i, 1);
		}
	}
	for (ll i = N; i >= 1; i--) {
		if (righ[nums[i]] == 0 && nums[i] != 0) {
			righ[nums[i]] = i;
			update(i, -1);
		}
	}
	for (ll i = 1; i <= N; i++) {
		if (nums[i] == 0) {
			update(i, -mxN);
		}
	}
	for (ll i = 1; i <= N; i++) {
		if (nums[i] != 0 && query(lef[nums[i]], righ[nums[i]]) != 0) {
			cout << -1 << '\n';
			return 0;
		}
	}
	ll ans = 0, sum = 0;
	for (ll i = 1; i <= N; i++) {
		if (lef[nums[i]] == i) {
			sum++;
		}
		ans = max(ans, sum);
		if (righ[nums[i]] == i) {
			sum--;
		}
	}
	cout << ans << '\n';
}
