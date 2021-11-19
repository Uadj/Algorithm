# 이유는 알 수 없지만 단순히 내림차순 정렬 후 뒤의 숫자보다 앞이 큰 숫자면 --해주는 방법은 통과하지 못했다.
# n번동안 가장 큰 값을 뺐다가 -1하고 다시 넣는(음수가 되면 안된다.) 우선 순위 큐를 이용한 방법이다.
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(),works.end());
    while(n>0){
        
        int temp = q.top();
        if(temp>0){
            q.pop();
            q.push(temp-1);
        }
        n--;
    }
    while(!q.empty()){
        answer += q.top()*q.top();
        q.pop();
    }
    
    return answer;
}
