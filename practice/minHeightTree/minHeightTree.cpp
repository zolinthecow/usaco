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

const int mxN = 2e5 + 5;

int T, N;
int nums[mxN];

int main () {
    //setIO("minHeightTree");	
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> nums[i];
		
		int ans = 0;
		
		int curLayerNodes = 0;
		int prevLayerNodes = 1;
		
		
		for (int i = 1; i < N; ) {
			for (int j = 0; j < prevLayerNodes; j++) {
				while (i < N && nums[i + 1] > nums[i]) {
					i++;
					curLayerNodes++;
				}
				i++;
				curLayerNodes++;
			}
			ans++;
			prevLayerNodes = curLayerNodes;
			curLayerNodes = 0;
		}
		
		cout << ans << '\n';
	}
}
