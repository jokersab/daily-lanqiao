#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int N = 5000001;
int num[N];
long long int pre[N];
int op(string a,int l){
	long long ans = 0;
	memset(pre,0,sizeof pre);
	for(int i = 1; i <= l; ++i){
		pre[i] += pre[i-1] + a[i-1] - '0';
		cout<<a[i-1]<<"  ";
	}
	for(int i = (l+1)/2;i <= l; ++i){
		ans = max(ans,pre[i] - pre[i-(l+1)/2]);
	}
	return ans;
}
int main(){
	int t,l,i = 0,tmp;
	cin>>t;
	string a;
	while(t--){
		cin>>l>>a;
		tmp = op(a,l);
		cout<<"Case #"<<++i<<": "<<tmp<<endl;
	}
	return 0;
}
