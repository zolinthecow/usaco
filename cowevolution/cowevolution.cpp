#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int N;
vector<string> cows[30];

vector<string> allCharacteristics;

bool check(int A, int B) {
	bool aNotB = false, bNotA = false, both = false;
	for (int i = 0; i < N; i++) {
		bool hasA = false, hasB = false;
		for (int j = 0; j < (int) cows[i].size(); j++) {
			if (cows[i][j] == allCharacteristics[A]) {
				hasA = true;
			}
			if (cows[i][j] == allCharacteristics[B]) {
				hasB = true;
			}
		}
		if (hasA && !hasB) {
			aNotB = true;
		}
		if (hasB && !hasA) {
			bNotA = true;
		}
		if (hasA && hasB) {
			both = true;
		}
	}
	if (aNotB && bNotA && both) {
		return false;
	} else {
		return true;
	}
}

int main() {
	setIO("evolution");
	cin >> N;
	int num;
	string characteristic;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> characteristic;
			cows[i].push_back(characteristic);
			if (find(allCharacteristics.begin(), allCharacteristics.end(), characteristic) == allCharacteristics.end()) {
				allCharacteristics.push_back(characteristic);
			}
		}
	}
	
	for (int i = 0; i < (int) allCharacteristics.size(); i++) {
		for (int j = i + 1; j < (int) allCharacteristics.size(); j++) {
			if (!check(i, j)) {
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;
}
