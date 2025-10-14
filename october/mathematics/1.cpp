#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int revNUm=0;
    int dup=n;
    while(n>0){
        int lastDig=n%10;
        revNUm=revNUm*10+lastDig;
        n=n/10;
    }
    if(dup==revNUm){
        cout<<"Palindrome";
    }
    
    
    return 0;
}