#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 1000000007


int main() {
	int N;
	cin >> N;
	vii segs(N);
	for (int i = 0; i < N; i++) {
		cin >> segs[i].first >> segs[i].second;
	}
	sort(segs.begin(), segs.end());
	vii inView;

}
