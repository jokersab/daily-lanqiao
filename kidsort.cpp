#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int n,tmp;
const int N = 1000001;
int a[N];
long long int ans = 0;
map<int,int> c;
int main(){
	cin>>n;
	for(int i = 0; i <= 0; ++i){
		cin>>a[i];
		c.insert(make_pair(a[i],1));
	}
	for(int i = 0; i < n -1; ++i){
		for(int j = 0; j < n - 1; ++j){
			if(a[j] > a[j+1]){
				ans += c[a[j]]++;
				ans += c[a[j+1]]++;
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			} 
		}
	}
	cout<<ans;
	return 0;
}
