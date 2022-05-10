#include<vector>
#include <iostream>
#include <queue>
using namespace std;

int dirx[4]= {1,-1,0,0};
int diry[4] = {0,0,1,-1};
int visit[100][100]={0};
int depth[100][100]={1};
int answer = 0;
int N,M;
int solution(vector<vector<int>> maps)
{
    N = maps.size();
    M = maps[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visit[0][0]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x+dirx[i];
            int ny = y+diry[i];
            //cout << nx << ' ' << ny << endl; 
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(nx==N-1 && ny==M-1){
                    answer= depth[x][y]+1;
                    return answer;
                }
                if(maps[nx][ny]==1 && visit[nx][ny]==0){
                    
                    depth[nx][ny]=depth[x][y]+1;
                    q.push(make_pair(nx,ny));
                    visit[nx][ny]=1;
                }
            }
        }
    }
    return -1;
}
