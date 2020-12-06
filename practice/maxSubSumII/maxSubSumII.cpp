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

int N, A, B;
int x[mxN];

int front, back;
int sum = 0;

int mx = 0;

int main () {
	setIO("maxSubSumII");
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) cin >> x[i];
	back = 0, front = A - 1;
	for (int i = back; i <= front; i++) sum += x[i];
	mx = max(sum, mx);
	while (front < N - 1) {
		while (front < N && front - back + 1 < B) {
			++front;
			sum += x[front];
			mx = max(sum, mx);
		}
		while (x[back] < 0 && front - back + 1 >= A && back + 1 <= front) {
			sum -= x[back];
			mx = max(sum, mx);
			++back;
		}
		while (front - back + 1 >= A && back + 1 <= front) {
			sum -= x[back];
			mx = max(sum, mx);
			++back;
		}
	}
	cout << mx << endl;
}
