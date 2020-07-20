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
#define MOD 10000000

int N, M, K;
vii swapSegs;


int main() {
	ifstream fin;
	ofstream fout;
	fin.open("swap.in");
	fout.open("swap.out");
	fin >> N >> M >> K;
	swapSegs.resize(M);
	for (int i = 0; i < M; i++) {
		fin >> swapSegs[i].first >> swapSegs[i].second;
		swapSegs[i].first--, swapSegs[i].second--;
	}
	vi firstRound;
	for (int i = 0; i < N; i++) {
		firstRound.pb(i);
		for (int j = 0; j < M; j++) {
			if (firstRound[i] >= swapSegs[j].first && firstRound[i] <= swapSegs[j].second) {
				firstRound[i] = swapSegs[j].first + swapSegs[j].second - firstRound[i];
			}
		}
	}
	vi cycleNum(N, 0);
	vector<vi> cycles(N + 1);
	vi posInCycle(N);
	int cycleOn = 1;
	for (int i = 0; i < N; i++) {
		if (cycleNum[i]) continue;
		cycleNum[i] = cycleOn;
		cycles[cycleOn].pb(i);
		int on = firstRound[i];
		if (on != i) posInCycle[on] = 1;
		while (on != i) {
			cycles[cycleOn].pb(on);
			cycleNum[on] = cycleOn;
			if (firstRound[on] != i) posInCycle[firstRound[on]] = posInCycle[on] + 1;
			on = firstRound[on];
		}
		cycleOn++;
	}
	vi ans(N);
	for (int i = 0; i < N; i++) {
		ans[cycles[cycleNum[i]][(posInCycle[i] + K) % cycles[cycleNum[i]].size()]] = i;
	}
	for (auto it : ans) fout << it + 1 << endl;
	fin.close();
	fout.close();
}
