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
#define INF 1000000000
#define MOD 1000000007

inline ll sum (ll n, ll m) { return m * (m + 1) / 2 - n * (n + 1) / 2; }

bool faster(ll K, ll distTraveled, ll speed, ll reach) {
	if (sum(reach, speed + 1) + distTraveled < K) {
		return true;
	}
	return false;
}

bool stay(ll K, ll distTraveled, ll speed, ll reach) {
	if (sum(reach, speed) + distTraveled >= K) {
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("race.in");
	fout.open("race.out");
	ll N, K;
	fin >> K >> N;
	vi X(N);
	for (ll i = 0; i < N; i++) {
		fin >> X[i];
	}
	for (ll i = 0; i < N; i++) {
		ll distTraveled = 0, speed = 0, counter = 0;;
		while (distTraveled < K) {
			if (faster(K, distTraveled, speed, X[i])) {
				speed++;
			} else if (!stay(K, distTraveled, speed, X[i])) {
				speed--;
			}
			distTraveled += speed;
			counter++;
		}
		fout << counter << endl;
	}
}
