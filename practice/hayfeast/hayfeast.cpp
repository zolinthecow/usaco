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

ll N, M;
ll flavor[mxN], spicy[mxN];

int main () {
    setIO("hayfeast");	
	cin >> N >> M;
	for (ll i = 0; i < N; i++) cin >> flavor[i] >> spicy[i];
	ll back = 0, front = 0, totalFlavor = 0;
	multiset<ll, greater<ll> > maxSpicy;
	ll ans = INF;
	while (front != N) {
		//move front foward until works
		for ( ; front < N; ) {
			maxSpicy.insert(spicy[front]);
			totalFlavor += flavor[front];
			front++;
			if (totalFlavor >= M) break;
		}
		if (front == N && totalFlavor < M) break;
		ans = min(ans, *maxSpicy.begin());
		//move back forward until doesnt work
		for ( ; back < N; ) {
			maxSpicy.erase(maxSpicy.find(spicy[back]));
			totalFlavor -= flavor[back];
			back++;
			if (totalFlavor < M) break;
			//if (sz(maxSpicy))
			ans = min(ans, *maxSpicy.begin());
		}
	}
	cout << ans << '\n';
}
