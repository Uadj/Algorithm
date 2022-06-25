/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int arr[100][100];int N;
int dirx[] = {1,0,0,-1};
int diry[] = {0,1,-1,0};
void dfs(int x, int y, int temp[100][100], int visit[100][100]){
    visit[x][y] = 1;
    for(int i=0; i<4;i++){
        int nx = x+dirx[i];
        int ny = y+diry[i];
        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(visit[nx][ny]==0 && temp[nx][ny]!=-1){
                dfs(nx,ny,temp,visit);
            }
        }
    }
}
int main()
{
    
    cin >> N;
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int t=0; t<100;t++){
        int tempans = 0;
        int temp[100][100]={0};
        int visit[100][100]={0};
        for(int i=0; i<N;i++){
            for(int j=0; j<N;j++){
                temp[i][j] = arr[i][j];
                if(temp[i][j]<=t){
                    temp[i][j]=-1;
                }
            }
        }
       
         for(int i=0; i<N;i++){
            for(int j=0; j<N;j++){
                if(temp[i][j]!=-1 && visit[i][j]==0) {
                    dfs(i,j, temp, visit); tempans++;
                }
            }
         }
         //cout << tempans << ' ';
         if(ans<tempans) ans = tempans;
        
    }
    cout << ans;
    return 0;
}
