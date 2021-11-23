// 그대로 따라가 준 후 방문처리한다.
#include <string>
#include <iostream>
using namespace std;
int arr[11][11][11][11];
bool visited[11][11][11][11]={false};
int solution(string dir) {
    int x=5,y=5;
    int count=0;
    for(int i=0; i<dir.size();i++){
        
        if(dir[i]=='U'){
            if(y+1>10) continue;
            if(visited[x][y][x][y+1]){
                y++;
                continue;
            }
            else {
                visited[x][y][x][y+1]=true;
                visited[x][y+1][x][y]=true;
                y++;
                count++;
            }
            
        }
        
        else if(dir[i]=='L'){
            if(x-1<0) continue;
            if(visited[x][y][x-1][y]){
                x--;
                continue;
            }
            else {
                visited[x][y][x-1][y]=true;
                visited[x-1][y][x][y]=true;
                x--;
                count++;
            }
            
        }
        else if(dir[i]=='R'){
            if(x+1>10) continue;
            if(visited[x][y][x+1][y]){
                x++;
                continue;
            }
            else {
                visited[x][y][x+1][y]=true;
                visited[x+1][y][x][y]=true;
                x++;
                count++;
            }
        }
        else if(dir[i]=='D'){
            if(y-1<0) continue;
            if(visited[x][y][x][y-1]){
                y--;
                continue;
            }
            else {
                visited[x][y][x][y-1]=true;
                visited[x][y-1][x][y]=true;
                y--;
                count++;
            }
        }
         //cout << x <<' ' <<  y << endl;
        
    }
    return count;
}
