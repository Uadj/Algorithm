#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int distance[N+1]; //1에서 인덱스까지 소요시간
    distance[1]=0;
    for(int i=2; i<=N;i++){
        distance[i]=500002;
    }
    priority_queue<pair<int, int>> q; //1부터 총 소요시간, 현재위치 
    vector<pair<int,int>> town[N+9];//인덱스에서 first까지 시간second
   
    for(int i=0; i<road.size();i++){
        int x = road[i][0];
        int y = road[i][1];
        int t = road[i][2];
        town[x].push_back(make_pair(y,t));
        town[y].push_back(make_pair(x,t));
    }
    //cout << town[1].front().first <<' ' <<  town[1].front().second;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int cost = q.top().first;
        int pos = q.top().second;
        //cout << "cost "<< cost << " pos " << pos <<endl;
        q.pop();
        for(int i=0;i<town[pos].size();i++){
            int next = town[pos][i].first;
            int tcost = town[pos][i].second;
           //cout << next << ' ' <<tcost <<endl;
            if(distance[next]>cost+tcost){
                distance[next] = cost+tcost;
                q.push(make_pair(distance[next],next));
                //cout << distance[pos] << ' ' << next << " next" <<endl;
            }
        }
    }
    for(int i=1; i<=N;i++){
        if(distance[i]<=K){
            //cout << i << ' ' << distance[i] <<" dis" <<endl;
            answer++;
        }
    }
    return answer;
}
