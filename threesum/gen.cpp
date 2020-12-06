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
	int N = rand(3, 10), Q = rand(1, 10);
	cout << N << " " << Q << endl;
	for (int i = 0; i < N; i++) cout << rand(-10, 10) << " ";
	cout << endl;
	for (int i = 0; i < Q; i++) {
		int a = rand(1, N - 2);
		int b = rand(a + 2, N);
		cout << a << " " << b << endl;
	}
	
}
