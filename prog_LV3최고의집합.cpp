//https://programmers.co.kr/learn/courses/30/lessons/12938
//중간값의 곱들이 가장 크기 때문에 s/n을 한 뒤 나머지는 1씩 더해준다. 그리고 오름차순 출력
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s){
        return {-1};
    }
    int a = int(s/n);
    int b = s%n;
    int c[n];
    for(int i=0; i<n;i++)
        c[i]= a;
    for(int i=0; i<b;i++){
        c[i]++;
    }
    for(int i=n-1; i>=0;i--)
    answer.push_back(c[i]);
    return answer;
}
