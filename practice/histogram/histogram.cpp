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

vi calc(vi heights, int N) {
	vii stack = {{0, 0}};
	vi ans(N + 1);
	for (int i = 1; i <= N; i++) {
		while (stack.size() && stack.back().first >= heights[i]) stack.pop_back();
		ans[i] = stack.back().second;
		stack.pb(ii(heights[i], i));
	}
	return ans;
}

int main () {
	//setIO("histogram");
	int N;
	cin >> N;
	vi heights(N + 1);
	for (int i = 1; i <= N; i++) cin >> heights[i];
	heights[0] = 0;
	vi back = calc(heights, N);
	reverse(begin(heights) + 1, end(heights));
	vi front = calc(heights, N);
	reverse(begin(heights) + 1, end(heights));
	reverse(begin(front) + 1, end(front));
	for (int i = 0; i < (int) front.size(); i++) 
		front[i] = N - front[i] + 1;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, heights[i] * (front[i] - back[i] - 1));
	}
	cout << ans << endl;
}
