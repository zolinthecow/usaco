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

const int mxN = 1e5 + 5;

int N;
int nums[mxN];
int res[mxN];

bool works(int mid) {
	int u = N - 1, l = mid - 1;
	if (nums[u] > nums[l] && nums[u - 1] > nums[l] && nums[u - mid + 1] > nums[0] && nums[u - mid] > nums[0])
		return true;
	else
		return false;
}

int bin() {
	int low = 0, up = N / 2 + 1;
	int mid;
	while (low < up - 1) {
		mid = low + (up - low) / 2;
		if (works(mid)) 
			up = mid;
		else
			low = mid;
	}
	if (works(low)) return low;
	else return up;
}

int main () {
	setIO("sageBirthday");
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
	sort(nums, nums + N);
	int ans = bin();
	cout << ans << '\n';
}
