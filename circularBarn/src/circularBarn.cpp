#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <functional>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long

long long sumn2(long long v) {
  return v * (v + 1) * (2 * v + 1) / 6;
}

int main() {
  int N; cin >> N;
  vector<long long> A(N);

  int c = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    c = max(0ll, c + A[i] - 1);
  }

  for (int i = 0; ; i++) {
    if (c == 0) {
      rotate(A.begin(), A.begin() + i, A.begin() + N);
      break;
    }
    c = max(0ll, c + A[i] - 1);
  }


  long long result = 0;
  for (int i = 0; i < N; i++) {
    result += sumn2(A[i] + c - 1) - sumn2(c - 1);
    c = max(0ll, c + A[i] - 1);
  }
  cout << result << endl;
}
