/*
在斐波那契数列中，Fib0=0,Fib1=1,Fibn=Fibn-1+Fibn-2(n>1)。
给定整数 n，求 Fibnmod10000
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 10000;
//矩阵乘法 
void mul(int a[][2],int b[][2]){
	int c[2][2] = {0};
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				c[i][j] = (c[i][j] + a[i][k] * b[k][j])%mod;
			}
		} 
	}
	memcpy(a,c,sizeof c); 
}
//快速幂 
int fib(int n){
	int a[2][2] = {0,1,0,0};
	int b[2][2] = {0,1,1,1};
	while(n){
		if(n&1){
			mul(a,b);
		}
		mul(b,b);
		n>>=1;
	}
	return a[0][0];
}
int main(){
	int n;
	while(cin>>n,n != -1){
		cout<<fib(n)<<endl;
	}
}
