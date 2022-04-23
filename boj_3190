#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
char chdir[10001];
int N, K, L;
queue<pair<int, int>> q;
int dirx[] = {-1,1,0,0}; //상, 하, 우, 좌
int diry[] = {0,0,1,-1};
int dirL[] = {3,2,0,1}; //상->좌 하->우, 우->상, 좌->하
int dirD[] = {2,3,1,0}; //상->우 하->좌 우->하 좌->상
int main(){
    //-------
    arr[0][0]=2;
    q.push({0,0});
    cin >> N;
    cin >> K;
    for(int i=0; i<K;i++){
        int a,b;
        cin >> a >> b;
        arr[a-1][b-1]=1;
    }
    cin >> L;
    for(int i=0;i<L;i++){
        int a; char b;
        cin >> a >> b;
        chdir[a]=b;
    }
    //-------
    int x=0, y=0, i=0, d=2;
    while(true){
        x += dirx[d];
        y += diry[d];
        i++;
        if(x>=N || x<0 || y<0 || y>=N || arr[x][y]==2){
            cout << i << endl; break;
        }
        if(arr[x][y]==0){
            int nx=q.front().first, ny=q.front().second;
            arr[nx][ny]=0;
            q.pop(); 
        }
        arr[x][y]=2;
        q.push({x,y});
        if(chdir[i]=='L'){
            d = dirL[d];
        }
        else if(chdir[i]=='D'){
            d = dirD[d];
        }
    }
    return 0;
}
