#include <cstdio>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

#define NMAX 100000
#define MMAX 50000

// entry i is the list of edges implied
// by observation i
vector<pair<int, int>> edges[MMAX];

// For each cow, list of successors of that cow
// in the graph constructed from some set of the
// observations.
vector<int> succ[NMAX];

// For each cow, the number of precessors
// in the graph.
int pred[NMAX];

// Resulting lexicographically earliest topological sort.
int result[NMAX];

// Check if topological sort is doable, for the first
// k observations, and if so, put the answer
// in the `result` array.
bool doable(int n, int k) {
  // Setup the graph from the first k observations.
  for (int i = 0; i < n; i++) {
    succ[i].clear();
    pred[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    for (auto p : edges[i]) {
      succ[p.first].push_back(p.second);
      pred[p.second]++;
    }
  }

  // Initialize the queue with cows that can be first.
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    if (pred[i] == 0) {
      // Use the negative of the ID because we want
      // to get the min when we pop, but priority_queue
      // returns the max.
      q.push(-i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (q.empty()) {
      // Nothing in queue - topological sort is impossible.
      return false;
    }
    int v = -q.top();
    q.pop();

    result[i] = v;
    for (int next : succ[v]) {
      pred[next]--;
      if (pred[next] == 0) {
        q.push(-next);
      }
    }
  }

  return true;
}

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  assert(1 <= m && m <= MMAX);
  assert(1 <= n && n <= NMAX);

  for (int i = 0; i < m; i++) {
    int d;
    scanf("%d", &d);
    int last;
    for (int j = 0; j < d; j++) {
      int e;
      scanf("%d", &e);
      e--;
      if (j > 0) {
        edges[i].push_back(make_pair(last, e));
      }
      last = e;
    }
  }

  // Binary search
  // Invariant: lo <= ans < hi
  int lo = 0;
  int hi = m+1;
  while (hi > lo+1) {
    int mid = (lo + hi) / 2;
    if (doable(n, mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int ans = lo;

  // Run this again, to get the answer
  // into the `result` array.
  doable(n, ans);

  for (int i = 0; i < n; i++) {
    printf("%d%c", result[i] + 1, i == n-1 ? '\n' : ' ');
  }
}
