#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

 
int repeatedStringMatch(string A, string B) {
    int n1 = A.size(), n2 = B.size(), cnt = 1;
    string t = A;
    while (t.size() < n2) {
        t += A;
        ++cnt;
    } 
    if (t.find(B) != string::npos) return cnt;
    t += A;
    return (t.find(B) != string::npos) ? cnt + 1 : -1;
}


int main()
{
	string a,b;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		cout << repeatedStringMatch(a,b)<<endl; 		
	} 
	return 0;
}
