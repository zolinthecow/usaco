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

int main() {
	setIO("cardgame");
	int N;
	cin >> N;
	vi seen(2 * N + 1, 0);
	vi elsie;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		seen[a] = 1;
		elsie.pb(a);
	}
	vi bessie;
	for (int i = 1; i < 2 * N + 1; i++) {
		if (!seen[i]) bessie.pb(i);
	}
	sort(bessie.begin(), bessie.end(), greater<int>());
	vi firstHalfB(bessie.begin(), bessie.begin() + N / 2);
	vi secondHalfB(bessie.begin() + N / 2, bessie.end());
	queue<int> firstHalfE, secondHalfE;
	for (int i = 0; i < N; i++) {
		if (i < N / 2) firstHalfE.push(elsie[i]);
		else		   secondHalfE.push(elsie[i]);
	}
	int ans = 0;
	while(!firstHalfE.empty()) {
		int on = firstHalfE.front(); firstHalfE.pop();
		if (on > firstHalfB.front()) continue;
		int mid;
		int low = 0, up = firstHalfB.size() - 1;
		while (low < up - 1) {
			mid = low + (up - low) / 2;
			if (firstHalfB[mid] > on) up = mid;
			else					  low = mid;
		}
		ans++;
		firstHalfB.erase(firstHalfB.begin() + mid);
	}
	sort(secondHalfB.begin(), secondHalfB.end());
	while(!secondHalfE.empty()) {
		int on = secondHalfE.front(); secondHalfE.pop();
		if (on < secondHalfB.front()) continue;
		int mid;
		int low = 0, up = secondHalfB.size() - 1;
		while (low < up - 1) {
			mid = low + (up - low) / 2;
			if (secondHalfB[mid] < on) up = mid;
			else					  low = mid;
		}
		ans++;
		secondHalfB.erase(secondHalfB.begin() + mid);
	}
	cout << ans << "\n";
}


