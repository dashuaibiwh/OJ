#include <iostream>
#include <cstdio>
#define ll long long 
using namespace std;
int N;
int revnum[10] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };
bool if_can( int n ){
	int t = n;
	int newnum = 0;
	if ( n % 10 == 0 ) 
		return false;	
	while (n){
		if ( n%10==3 || n%10==4 || n%10==7 ) return false;
		newnum = newnum*10 + revnum[n%10];
		n /= 10;	
	}
	if ( newnum > N ) 
		return false;
	if ( newnum == t ) 
		return false;
	
	
	return true;
}

int main(){
	scanf( "%d", &N );
	if ( N >= 9 ){
		cout<<6<<endl<<9<<endl;
	}
	for ( int i = 12 ; i <= N ; ++ i ){
		if ( if_can(i) ){
			cout<<i<<endl;
		}
	}
    return 0;
}

