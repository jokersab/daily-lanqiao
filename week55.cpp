#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int w[N];
int f[N][N];
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>w[i];
	} 
//区间dp模板，先枚举len，在枚举下标 
	for(int len = 1; len <= n; len++){
		for(int i = 0; i + len -1 < n; ++i){
			int j = i + len -1;
			f[i][j] = max(w[i]-f[i+1][j],w[j]-f[i][j-1]);
		}
	}
	int sum = 0,subs = f[0][n-1];
	for(int i = 0; i < n; ++i){
		sum += w[i]; 
	}
	printf("%d %d",(sum + subs)/2,(sum - subs)/2);
	return 0;
} 
