//https://programmers.co.kr/learn/courses/30/lessons/1829
//dfs
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[101][101];
int dirx[4] = {0,0,-1,1};
int diry[4] = {1,-1,0,0};
int number_of_area = 0;
int max_size_of_one_area = 0;
int dfs(int x, int y,const vector<vector<int>> &picture,int m, int n, int type);
 // picture &붙이는 것과 아닌 것 시간차이가 극명함
vector<int> solution(int m, int n, vector<vector<int>> picture) {
 //전역변수 반드시 여기서 초기화해줘야함.
    number_of_area = 0;
    max_size_of_one_area = 0;
    memset(visited,0,sizeof(visited));
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            if(!visited[i][j]&&picture[i][j]!=0){
                number_of_area++;
                 max_size_of_one_area = max(max_size_of_one_area,dfs(i,j,picture,m,n,picture[i][j]));
            }
        }
    }
   
    return {number_of_area,max_size_of_one_area};
}
int dfs(int x, int y, const vector<vector<int>> &picture,int m,int n,int type){
    int depth = 1;
    visited[x][y]=true;
        for(int i=0; i<4; i++){
            int tx = x+dirx[i];
            int ty = y+diry[i];
                if(!visited[tx][ty]&&tx>=0&&ty>=0&&tx<m&&ty<n&&picture[tx][ty]==type)
                {
                    depth+= dfs(tx,ty,picture,m,n,type);
                }
            }
        
    return depth;
    }
