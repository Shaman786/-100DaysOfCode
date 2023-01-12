#include<bits/stdc++.h>
using namespace std;

int main(){
	int first = 8;
	int second = 10;
	int *ptr  = &second;
	*ptr = 9;
	cout << first <<" "<<second << endl;
	return 0;
}