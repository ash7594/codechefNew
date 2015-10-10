/* 
 * C++ Program to Implement Euler Theorem
 */
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
 
void inverseArray(int n, int m) 
{
    vector<int> modInverse(n + 1, 0);
    modInverse[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        modInverse[i] = (-(m / i) * modInverse[m % i]) % m + m;
    }
	copy(modInverse.begin(),modInverse.end(),ostream_iterator<int>(cout, " "));
    //return modInverse;
}
//Main
int main()
{
    //vector<int>::iterator it;
    int a, m;
	a = 1000;
	m = 1000;
//    cout<<"Enter number to find modular multiplicative inverse: ";
//    cin>>a;
//    cout<<"Enter Modular Value: ";
//    cin>>m;
    inverseArray(a, m);
	cout<<endl;
	return 0;
}
