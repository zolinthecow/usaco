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
	int A = rand(1, 1000000000);
	int B = rand(1, 1000000000);
	int N = rand(0, 2000);
	int M = rand(0, 2000);
	set<int> n;
	while ((int) n.size() < N) {
		n.insert(rand(0, 999999999));
	}
	set<int> m;
	while ((int) m.size() < M) {
		m.insert(rand(0, 999999999));
	}
	vi cows;
	cout << A << " " << B << " " << N << " " << M << endl;
	for (auto it : n) {
		cout << it << endl;
	}
	for (auto it : m) {
		cout << it << endl;
	}
}
