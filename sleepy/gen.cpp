#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int N = rand(1, 10);
	cout << N << endl;
	unordered_set<int> nums;
	while((int) nums.size() < N) {
		nums.insert(rand(1, N));
	}
	for (auto it : nums) cout << it << " ";
	cout << endl;
}
