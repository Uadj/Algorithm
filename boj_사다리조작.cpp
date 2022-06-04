/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int N, M, H, ans=4;
int way[11][33];
bool check(){ // 자신의 세로줄이 다시 돌아오는지 확인
    for(int i=1; i<=N;i++){
        int current = i;
        for(int j=1; j<=H;j++){
            if(way[current][j]==1) current++;
            else if(way[current-1][j])current--;
        }
        if(current!=i) return false;
    }
    return true;
}
void dfs(int start, int cnt){ // 하나씩 사다리를 설치해봄
    if(cnt>3) return;
    if(check()){
        ans = min(ans, cnt);
        return;
    }
    for(int i=start;i<=H;i++){
        for(int j=1;j<N;j++){
            if(way[j][i]==true) continue;
            if(way[j-1][i]==true) continue; // 양 옆에 사다리가 있으면 생략
            if(way[j+1][i]==true) continue; 
            way[j][i] = true;
            dfs(i, cnt+1);
            way[j][i] = false;
        }
    }
}
int main()
{
    cin >> N >> M >> H;
    for(int i=0;i<M;i++){
        int r, c;
        cin >> r >> c;
        way[c][r]=1;
    }
    dfs(1,0);
    if(ans>3) cout << -1;
    else cout << ans;
    
    return 0;
}
