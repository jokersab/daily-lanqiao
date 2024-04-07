/*
给定两个正整数 a 和 b
你需要回答 q个询问。
每个询问给定两个整数 l,r，你需要找到最大的整数 x，满足：
x是 a和 b的公约数。l≤x≤r
输入格式
第一行包含两个整数 a,b
第二行包含一个整数 q
接下来 q行，每行包含两个整数 l,r
输出格式
每个询问输出一行答案，即满足条件的最大的 x
如果询问无解，则输出 -1
数据范围
前六个测试点满足 1≤a,b≤100，1≤q≤20
所有测试点满足 1≤a,b≤109，1≤q≤104，1≤l≤r≤109
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
vector<int> tmp;
void divide(int t){
	tmp.push_back(1);
	for(int i = 2; i * i <= t; ++i){
		if(t % i == 0){
			tmp.push_back(i);
			if(i * i != t){
				tmp.push_back(t/i);
			}
		}
	}
	tmp.push_back(t);
}
int main(){
	int a,b,q;
	cin>>a>>b>>q;
	int t = gcd(a,b);
	divide(t);
	sort(tmp.begin(),tmp.end());
	while(q--){
		int lef,rig;
		cin>>lef>>rig;
		if(rig < 0 || lef > b){
			cout<<-1<<endl;
			continue;
		}
		int l = 0,r = tmp.size()-1;
		while(l < r){
			int mid = (l + r +1)>>1;
			if(tmp[mid] <= rig){
				l = mid;
			}else{
				r = mid-1;
			}
		}
		if(tmp[l] >= lef && tmp[l] <= rig){
			cout<<tmp[l]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
} 
