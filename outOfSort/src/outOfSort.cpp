#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>;

int N;
vi B;
vector<ii> A;

// Concise implementation of a binary indexed tree
void modify(int j) {
	for (; j <= N; j += (j & -j))
		B[j]++;
}
int prefix_sum(int j) {
	int sum = 0;
	for (; j > 0; j -= (j & -j))
		sum += B[j];
	return sum;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort.in");
	fout.open("sort.out");
	int answer = 1;
	fin >> N;
	A.resize(N + 1);
	B.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int x;
		fin >> x;
		A[i] = make_pair(x, i);
	}
	sort(A.begin() + 1, A.end());
	for (int i = 1; i <= N - 1; i++) {
		modify(A[i].second);
		answer = max(answer, i - prefix_sum(i));
	}
	fout << answer << "\n";
	fin.close();
	fout.close();
	return 0;
}
