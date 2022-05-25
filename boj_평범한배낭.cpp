
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int N,K;
    cin >> N >> K;
     vector<pair<int, int>> v[101];
    int dp[N+1][100001]={0};
    for(int i=0; i<N;i++){
        int a,b;
        cin >> a >> b;
        v[i].push_back(make_pair(a,b));
    }
    for(int i=1; i<=N;i++){
        for(int j=1; j<=K;j++){
            int weight = v[i-1].front().first;
            int value = v[i-1].front().second;
            if(j < weight){
                dp[i][j] = dp[i-1][j];
            }            
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight]+value);
            }
        }
    }
    cout << dp[N][K];
    return 0;
}
