/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int arr[8][8];
int N, M;
int ans=0;

void bfs(int arr3[8][8]){
    int arr2[8][8];
    for(int i=0; i<N;i++){
      for(int j=0; j<M;j++){
            arr2[i][j]=arr3[i][j];
        }
     }
    queue<pair<int, int>> q;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            if(arr2[i][j]==2){
                q.emplace(i,j);
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4;k++){
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(xx<N && xx>=0 && yy<M && yy>=0){
                if(arr2[xx][yy]==0) {
                    arr2[xx][yy]=2;
                    q.emplace(xx,yy);
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            if(arr2[i][j]==0){
                cnt++;
            }
        }
    }
    ans = max(cnt, ans);
}

void dfs(int arr2[8][8], int cnt){
    if(cnt==0){
        bfs(arr2);
        return;
    }
    for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			if (arr2[k][m] == 0){
			    arr2[k][m]=1;
			    dfs(arr2, cnt - 1);
			    arr2[k][m]=0;
			}
		}
	}
}

int main(){

    cin >> N >> M;
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            if(arr[i][j]==0){ 
                int arr2[8][8];
			    for(int i=0; i<N;i++){
                  for(int j=0; j<M;j++){
                    arr2[i][j]=arr[i][j];
                    }
                 }
                arr2[i][j]=1;
                dfs(arr2,2);
                arr2[i][j]=1;
            }
            
        }
    }
    cout << ans;
}
