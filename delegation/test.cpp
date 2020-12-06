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

vi findDivisors(int n) {
	vi ans;
	int sq = sqrt(n) + 1;
	for (int i = 2; i < sq; i++) {
		if (n % i == 0) {
			if (n / i == i) ans.pb(i);
			else ans.pb(i), ans.pb(n / i);
		}
	}
	return ans;
}

int main () {
	vi d = findDivisors(12);
	for (auto it : d) cout << it << " ";
	cout << endl;
}
