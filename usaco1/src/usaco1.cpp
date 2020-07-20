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

int main() {
	int N, M, K
	cin >> N >> M >> K;
	string combo;
	cin >> combo;
	int **trainTimes = new int*[M];
	for (int i = 0; i < M; i++) {
		trainTimes[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> trainTimes[i][j];
		}
	}
	for (int k = 0; k < M; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				trainTimes[i][j] = min(trainTimes[i][j], trainTimes[i][k] + trainTimes[k][j]);
			}
		}
	}
	int **ps = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		ps[i] = new int[M];
	}
	for (int i = 0; i < M; i++) {
		ps[0][i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ps[i][j] = ps[i - 1][j] + trainTimes[combo[i] - 97][j];
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ps[i][j] << " ";
		}
		cout << endl;
	}
}
