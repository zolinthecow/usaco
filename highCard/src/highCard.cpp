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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("bob.txt");
	fout.open("highcard.out");
	int a;
	fin>>a;
	vi elsie, bessie;
	bool *elsiehas=new bool[2*a+1];
	for(int i=0; i<a; i++){
		int temp;
		fin>>temp;
		elsiehas[temp]=true;
	}
	for(int i=1; i<=2*a+1; i++){
		if(elsiehas[i]){
			elsie.push_back(i);
		}else{
			bessie.push_back(i);
		}
	}
	int count=0;
	int bessieOn=0, elsieOn=0;
	while(bessieOn<a && elsieOn<a){
		if(bessie[bessieOn]>elsie[elsieOn]){
			count++, bessieOn++, elsieOn++;
		}else{
			bessieOn++;
		}
	}
	cout<<count<<endl;
	fin.close();
	fout.close();
}
