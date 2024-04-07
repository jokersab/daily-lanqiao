/*
�������������� a �� b
����Ҫ�ش� q��ѯ�ʡ�
ÿ��ѯ�ʸ����������� l,r������Ҫ�ҵ��������� x�����㣺
x�� a�� b�Ĺ�Լ����l��x��r
�����ʽ
��һ�а����������� a,b
�ڶ��а���һ������ q
������ q�У�ÿ�а����������� l,r
�����ʽ
ÿ��ѯ�����һ�д𰸣����������������� x
���ѯ���޽⣬����� -1
���ݷ�Χ
ǰ�������Ե����� 1��a,b��100��1��q��20
���в��Ե����� 1��a,b��109��1��q��104��1��l��r��109
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
