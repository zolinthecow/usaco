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

map<int, string> direction = {
	{0, "N"},
	{1, "S"},
	{2, "E"},
	{3, "W"}
};

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int N = rand(2, 10);
	int M = rand(2, 10);
	int fx = rand(0, 10), fy = rand(0, 10);
	int bx = rand(0, 10), by = rand(0, 10);
	string fPath = "", bPath = "";
	for (int i = 0; i < N; i++) {
		fPath += direction[rand(0,3)];
	}
	for (int i = 0; i < M; i++) {
		bPath += direction[rand(0, 3)];
	}
	cout << N << " " << M << endl;
	cout << fx << " " << fy << endl;
	cout << bx << " " << by << endl;
	cout << fPath << endl;
	cout << bPath << endl;
}
