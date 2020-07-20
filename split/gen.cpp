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
	int N = rand(3, 50000);
	set<ii> points;
	while((int) points.size() < N) {
		points.insert(ii(rand(1, 1000000000), rand(1, 1000000000)));
	}
	cout << N << endl;
	for (auto it : points) {
		cout << it.first << " " << it.second << endl;
	}
}
