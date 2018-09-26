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
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define pb push_back
#define MAX 2000

int n,c,x[MAX],y[MAX],mat[MAX][MAX];

// MST with Prim
int mst()
{
	int from[MAX];
	bool mark[MAX];
	fill(from,from+n,-1);
	fill(mark,mark+n,false);

	int x=0,l=0;			// start from vertex 0
					// initial length of MST is 0
	for (int i=0; i<n-1; i++)
	{
		mark[x]=true;

		// expand the vertex and update edges in the queue
		for (int j=0; j<n; j++)
			if (!mark[j])
				if (mat[x][j])	// if there is (x,j) edge
					if (from[j]==-1 || mat[from[j]][j]>mat[x][j])
						from[j]=x;

		// choose the unused edge with minimum length in the queue
		x=-1;
		for (int j=0; j<n; j++)
			if (!mark[j] && from[j]!=-1)
				if (x==-1 || mat[from[x]][x]>mat[from[j]][j])
					x=j;

		// if graph is not connected
		if (x==-1) return -1;

		// update total cost of mst
		l+=mat[from[x]][x];
	}

	return l;
}

int main()
{
	ifstream fin("irrigation.in");
	int m;
	fin >> n >> c;
	for (int i=0; i<n; i++)
		fin >> x[i] >> y[i];
	fin.close();

	// construct the MST graph
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			mat[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			// remove the edge from graph if cost is less than c
			if (mat[i][j]<c) mat[i][j]=0;
		}

	ofstream fout("irrigation.out");
	fout << mst() << endl;	// write total length of MST
	fout.close();
}
