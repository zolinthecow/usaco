#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(2, 5);
    int k = rand(2, 10);
    cout << n << ' ' << k << '\n';
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());
    
    random_shuffle(edges.begin(), edges.end()); // random order of edges
    
    for(pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if(rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        printf("%d %d\n", perm[a], perm[b]);
    }
    for (int i = 0; i < k; i++) {
		int a, b;
		a = rand(1, n);
		do {
			b = rand(1, n);
		} while (b == a);
		cout << a << ' ' << b << '\n';
	}
}