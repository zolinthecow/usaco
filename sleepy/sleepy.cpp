#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

const int mxN = 1e5 + 5;

int N;
int nums[mxN];

indexed_set en;

int main() {
	setIO("sleepy");
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
	en.insert(nums[N - 1]);
	for (int i = N - 2; i >= 0; i--) 
		if (nums[i + 1] > nums[i]) en.insert(nums[i]);
		else break;
	int ans = 0;
	vi moves;
	int on = 0;
	while ((int) en.size() < N) {
		en.insert(nums[on]);
		ans++;
		moves.pb(N - en.size() + en.order_of_key(nums[on]));
		on++;
	}
	cout << ans << '\n';
	for (int i = 0; i < (int) moves.size(); i++)
		cout << moves[i] << (i == (int) moves.size() - 1 ? '\n' : ' ');
}
