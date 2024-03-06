#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int N = 501;
int n,m;
int cf[N][N];
void op(int x1,int y1,int x2,int y2){
	cf[x1][y1] += 1;
	cf[x1][y2+1] -= 1;
	cf[x2+1][y1] -= 1;
	cf[x2+1][y2+1] += 1;
}
int main(){
	cin>>n>>m;
	int x1,y1,x2,y2;
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		op(x1,y1,x2,y2); 
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cf[i][j] += cf[i-1][j] + cf[i][j-1] - cf[i-1][j-1];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d",cf[i][j]%2);
		}
		puts(""); 
	}
	return 0; 
}
