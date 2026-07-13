#include<iostream>

using namespace std;


int fac(int n){
    if(n == 0|| n == 1){
        return 1;
    }
    return n*fac(n-1);
}

int solve(int n){
    int numerator = fac(2*n);
    int denominator = fac(n+1);

    return numerator/denominator;
}


int main(){
    int n = 3;

    cout<<solve(n);

    return 0;
}

