#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
 
int N, M, K;
vector<int> nbrs[100001];
map<pair<int,int>, int> edgewt;
int H[100000], Y[100000];
 
map<int,int> dist;
 
void dijkstra(int source)
{
  set<pair<int,int>> visited;
  visited.insert(make_pair(0,source));
  while (!visited.empty()) {
    int i = visited.begin()->second;
    visited.erase(visited.begin());
    for (auto j : nbrs[i])
      if (dist.count(j) == 0 || dist[i] + edgewt[make_pair(i,j)] < dist[j]) {
	dist[j] = dist[i] + edgewt[make_pair(i,j)];
	visited.insert(make_pair(dist[j],j));
      }
  }
}
 
int main(void)
{
  ifstream fin ("dining.in");
  ofstream fout ("dining.out");
  fin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int a, b, t;
    fin >> a >> b >> t;
    a--; b--;
    nbrs[a].push_back(b);
    nbrs[b].push_back(a);
    edgewt[make_pair(a,b)] = t;
    edgewt[make_pair(b,a)] = t;
  }
  for (int i=0; i<K; i++) {
    fin >> H[i] >> Y[i];
    H[i]--;
  }
  
  dijkstra (N-1);
  map<int,int> orig_dist = dist;
  for (int i=0; i<K; i++) {
    nbrs[N].push_back(H[i]);
    edgewt[make_pair(N,H[i])] = orig_dist[H[i]] - Y[i];
  }
  dist.clear();
  dijkstra (N);
  for (int i=0; i<N-1; i++) 
    fout << (dist[i] <= orig_dist[i]) << "\n";
  
  return 0;
}
