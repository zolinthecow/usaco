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
	int places, cows;
	cin>>places>>cows;
	int *values=new int[places];
	for(int i=0; i<places; i++){
		cin>>values[i];
	}
	sort(values, values+places);
	int min=0, max=500000000;
	int last=0, used=0;
	while(last<places){
		int mid=(min+max)/2;
		while()
	}
	cout<<min<<endl;
}
