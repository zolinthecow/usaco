#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int N = rand(3, 10);
	int K;
	do {
		K = rand(1, 7);
	} while(K > N); 
	vi cows;
	for (int i = 0; i < N; i++) {
		cows.pb(rand(1, 10));
	}
	cout << N << " " << K << endl;
	for (auto it : cows) {
		cout << it << endl;
	}
}
