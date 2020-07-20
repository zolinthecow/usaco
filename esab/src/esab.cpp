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

int main() {
	int T, B;
	cin >> T >> B;
	vi bits;
	for (int x = 0; x < T; x++) {
		bits.clear();
		bits.resize(B);
		int on = 0, qNum = 0;;
		bool finished = false;
		while (!finished) {
			cout << on << endl;
			int r;
			cin >> r;
			bits[on] = r;
			on++;
			qNum++;
			if (on == B) {
				if (qNum % 10 == 1) on--;
				else 				finished = true;
			}
		}
		string ans = "";
		for (auto it : bits) ans += to_string(it);
		cout << ans << endl;
		char ok;
		cin >> ok;
		if (ok == 'N') return 0;
	}
}
