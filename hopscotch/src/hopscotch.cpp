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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define pb push_back

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("hopscotch.in");
	fout.open("hopscotch.out");
	int width, height, maxlabel;
	fin>>width>>height>>maxlabel;
	int **grid=new int*[width];
	for(int i=0; i<width; i++){
		grid[i]=new int[height];
	}
	for(int i=0; i<width; i++){
		for(int j=0; j<width; j++){
			fin>>grid[i][j];
		}
	}
	int **dp=new int*[width];
	for(int i=0; i<width; i++){
		dp[i]=new int[height];
	}
	dp[0][0]=1;
	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			for(int k=i+1; k<width; k++){
				for(int l=j+1; l<height; l++){
					if(grid[i][j]!=grid[k][l]){
						dp[k][l]+=dp[i][j];
						dp[k][l]%=1000000007;
					}
				}
			}
		}
	}
	fout<<dp[width-1][height-1]<<endl;
	fin.close();
	fout.close();
}
