#include<bits/stdc++.h>
using namespace std;
int c,d,tmp;
int n;
const int N = 5000000;
int t[N];
int main(){
	cin>>n;
	memset(t,-1,sizeof t);
	for(int i = 0; i * i <= n; ++i){
		for(int j = i; j*j +i*i <= n; ++j){
			tmp = i*i + j*j;
			if(t[tmp] == -1){
				t[tmp] = i;
			}
		}
	}
	for(int i = 0; i*i <= n; ++i){
		for(int j = 0; i*i + j*j <= n; ++j){
			tmp = n - i*i - j*j;
			c = t[tmp];
			if(c == -1) continue;
			d = sqrt(n - c*c);
			cout<<i<<" "<<j<<" "<<c<<" "<<d;
			return 0;
		}
	}
	return 0;
} 
