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
#define INF 1000000000

int length, skip;
vii points;
int **dp;

int calculateBest(){
	for(int i=0; i<=skip; i++){
		for(int j=0; j<length; j++){
			for(int k=j+1; k<length && i+k-j-1<=skip; k++){
				int nextI=i+(k-j-1), nextJ=k;
				int nextValue=abs(points[j].first-points[k].first)+abs(points[j].second-points[k].second);
				dp[nextI][nextJ]=min(dp[nextI][nextJ], dp[i][j]+nextValue);
			}
		}
	}
	return dp[skip][length-1];
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("marathon.in");
	fout.open("marathon.out");
	fin>>length>>skip;
	int smallest=1001;
	for(int i=0; i<length; i++){
		ii a;
		fin>>a.first>>a.second;
		smallest=min(smallest, a.first); smallest=min(smallest, a.second);
		points.push_back(a);
	}
	for(int i=0; i<length; i++){
		points[i].first+=abs(smallest), points[i].second+=abs(smallest);
	}
	dp=new int*[skip+1];
	for(int i=0; i<skip+1; i++){
		dp[i]=new int[length];
	}
	for(int i=0; i<skip+1; i++){
		for(int j=0; j<length; j++){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	int best=calculateBest();
	fout<<best<<endl;
	fin.close();
	fout.close();
}
