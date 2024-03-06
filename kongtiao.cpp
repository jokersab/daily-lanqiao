#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int N = 100001;
int num[N],b[N];
int n,tmp;
int main(){
	cin>>n;
	for(int i = 1; i <= n; ++i){
		cin>>num[i];
	}
	for(int i = 1; i <= n; ++i){
		cin>>tmp;
		num[i] -= tmp;
	}
	for(int i = 1; i <= n; ++i){
		b[i] = num[i] - num[i-1];
	}
	int z = 0,f = 0;
	for(int i = 1; i <= n; ++i){
		if(b[i] >0){
			z += b[i];
		}else{
			f -= b[i];
		}
	}
	cout<<max(z,f);
	return 0;
}
