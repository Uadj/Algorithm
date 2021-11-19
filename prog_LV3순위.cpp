// 플루이드 와샬

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> temp(n+1, vector<bool> (n+1,false));
    for(auto r : results) temp[r[0]][r[1]]=true;
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n;j++){
            for(int k=1; k<=n;k++){
              // j i && i k -> j k 는 되지만 i j && j k 0> i k 는 안됨. 순서 중요
                if(temp[j][i]&&temp[i][k]) temp[j][k]=true;
            }
        }
    }
    int answer=0;
    for(int i=1; i<=n; i++){
        int c = 0;
        for(int j=1; j<=n;j++){
            if(temp[i][j]||temp[j][i]) c++;
        }
      // 각 선수(i)에 대해서 다른 상대 모든 선수와 결과에 대해서 알고 있을 때 정답++ 
        if(c==n-1) answer++;
  
    }
    
    
    return answer;
}
