#include<bits/stdc++.h>
using namespace std;
const double esp = 1e-10; 
const int N = 105;
char g[N][N];
int pos = 0,w,h,top;
struct point{
	int x,y;
}p[101*101];
double hash[26];
double getdis(point a,point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
double hashcode(int n){
	double sum = 0;
	for(int i = 0; i <n; ++i){
		for(int j = i + 1; j < n; ++j){
			sum += getdis(p[i],p[j]);
		}
	}
	return sum;
}
int gethash(double has){
	for(int i = 0; i < pos; ++i){
		if(hash[i] == has){
			return i;
		}
	}
	hash[pos++] = has;
	return pos-1;
}
void dfs(int nx,int ny){
	p[top++] = {nx,ny};
	g[nx][ny] = '0';
	for(int x = nx - 1; x <= nx + 1; ++x){
		for(int y = ny - 1; y <= ny + 1; ++y){
			if(x == nx && y == ny)	continue;
			if(x >= 0 && x < h && y >= 0 && y < w && g[x][y] == '1'){
				dfs(x,y);
			}
		}
	}	
}

int main(){
	cin>>w>>h;
	for(int i = 0; i < h; ++i){
		cin>>g[i];
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(g[i][j] == '1'){
				top = 0;
				dfs(i,j);
				double code = hashcode(top);
				int c = gethash(code);
				for(int i = 0; i < top; ++i){
					g[p[i].x][p[i].y] = 'a' + c; 
				}
			}
		} 
	} 
	for(int i = 0; i < h; ++i){
		cout<<g[i]<<endl;
	}
	return 0;
}
