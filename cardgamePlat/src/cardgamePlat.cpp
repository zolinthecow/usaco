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

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 5e4;

int seen[2 * mxN + 1];

vi bessie, elsie;
set<int, greater<int> > bessieF, elsieF;
set<int> bessieS, elsieS;

int main() {
	setIO("cardgame");
	int N;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		seen[a] = 1;
		elsie.pb(a);
	}
	for (int i = 1; i <= 2 * N; i++) {
		if (!seen[i]) bessie.pb(i);
	}
	bessieF.insert(bessie.begin(), bessie.end());
	elsieF.insert(elsie.begin(), elsie.end());
	int ret = 0;
	auto bessieCurr = bessieF.begin(), elsieCurr = elsieF.begin();
	for (int i = 0; i < N; i++) {
		if (*bessieCurr > *elsieCurr) {
			ret++;
			bessieCurr++;
		}
		elsieCurr++;
	}
	for (int i = N - 1; i >= 0; i--) {
		bessieF.erase(bessieF.find(bessie[i]));
		elsieF.erase(elsieF.find(elsie[i]));
		bessieS.insert(bessie[i]);
		elsieS.insert(elsie[i]);
		int ans = 0;
		auto bessieCurrF = bessieF.begin(), elsieCurrF = elsieF.begin();
		for (int j = 0; i < i; i++) {
			if (*bessieCurrF > *elsieCurrF) {
				ans++;
				bessieCurrF++;
			}
			elsieCurrF++;
		}
		auto bessieCurrS = bessieS.begin(), elsieCurrS = elsieS.begin();
		for (int j = 0; j < N - i; j++) {
			if (*bessieCurrS < *elsieCurrS) {
				ans++;
				bessieCurrS++;
			}
			elsieCurrS++;
		}
		ret = max(ret, ans);
	}
	cout << ret << "\n";
}
