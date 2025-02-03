#include "bits/stdc++.h"
using namespace std;


// modular operations
    int MOD = 1e9 + 7;
    int modexp(int x , int n){
      if(n==0) return 1%MOD;
    
      int u = modexp(x,n/2);
      u = (u*u)%MOD;
      if(n&1) u *= x;
      return u%MOD;
    }
    
    int modadd(int a,int b){ return ( ( (a%MOD) + (b%MOD) ) % MOD );}
    int modsub(int a,int b){ return ( ( (a%MOD) - (b%MOD) + MOD ) % MOD );}
    int modmul(int a,int b){return ( ( (a%MOD) * (b%MOD) ) % MOD );}
    int moddiv(int a,int b){ return ( modmul(a , modexp(b,MOD-2 )));}
    int modinv(int y){return modexp(y,MOD-2);}
    
int main () {
    // finding the ceil value of division of two numbers

    // ceil(2/3) = 1, ceil(12/5) = 3

    int a = 12;
    int b = 5;
    int ceilRes = (a + b - 1) / b;
    // dont use ceilRes = ceil((float) a/b)
    // floating point data type can lead to rounding errors

    
    
}