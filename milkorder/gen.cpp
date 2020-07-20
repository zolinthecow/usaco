#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int N = rand(1, 10), M = rand(1, 10);
	cout << N << " " << M << endl;
	for (int i = 0; i < M; i++) {
		int mi = rand(1, N);
		cout << mi << " ";
		set<int> order;
		while ((int) order.size() < mi) order.insert(rand(1, N));
		for (auto it : order) cout << it << " ";
		cout << endl;
	}
}
