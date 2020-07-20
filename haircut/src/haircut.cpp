#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 10000000
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(ll n) { ft.assign(n + 1, 0); }

  ll rsq(ll b) {                                     // returns RSQ(1, b)
    ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  ll rsq(ll a, ll b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(ll k, ll v) {                    // note: n = ft.size() - 1
    for (; k < (ll)ft.size(); k += LSOne(k)) ft[k] += v; }
};

vi hairs;

bool posSort(ll a, ll b) {
	return hairs[a] > hairs[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin;
    ofstream fout;
    fin.open("haircut.in");
    fout.open("haircut.out");
	ll N;
	fin >> N;
	hairs.resize(N);
	vi pos;
	ll maxLen = 0;
	for (ll i = 0; i < N; i++) {
		fin >> hairs[i];
		if (hairs[i] > N - 1) hairs[i] = N - 1;
		pos.pb(i);
		maxLen = max(maxLen, (ll) hairs[i]);
	}
	sort(pos.begin(), pos.end(), posSort);
	vector<vi> groups(1);
	vi temp;
	ll groupOn = 0;
	for (ll i = 0; i < N; i++) {
		groups[groupOn].pb(pos[i]);
		if (hairs[pos[i]] != ((i < N - 1) ? hairs[pos[i + 1]] : -1)) {
			groups.pb(temp); groupOn++;
		}
	}
	FenwickTree accountFor(N);
	FenwickTree ft(N);
	for (auto it : groups) {
		for (ll i = it.size() - 1; i >= 0; i--) {
			accountFor.adjust(it[i] + 1, ft.rsq(it[i] + 1));
			ft.adjust(it[i] + 1, 1);
		}
	}
	vi ans(N, -1);
	for (auto it : groups) {
		if (it.size() == 0) continue;
		ll val = -accountFor.rsq(it[0] + 1, it[0] + 1);
		for (auto i : it) {
			accountFor.adjust(i + 1, val);
		}
		ans[hairs[it[0]]] = accountFor.rsq(N);
	}
	for (ll i = maxLen + 1; i < N; i++) {
		ans[i] = ans[i - 1];
	}
	for (ll i = N - 2; i >= 0; i--) {
		if (ans[i] == -1) ans[i] = ans[i + 1];
	}
	for (auto it : ans) fout << it << endl;
	fin.close();
	fout.close();
}
