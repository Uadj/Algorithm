#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;.
 // 시간을 초 단위로 바꾸는 함수를 구현한다.
int convert(string time){
    stringstream ss(time);
    int h,m,s;
    char tmp;
    ss >> h >> tmp >> m >> tmp >> s;
    return h*60*60+m*60+s;
}
string solution(string play_time, string adv_time, vector<string> logs){
    int playSec = convert(play_time);
    int advSec = convert(adv_time);
    int totalSec[100*3600]={0};
  
// 시청시간 목록을 for문 돌면서 시청시간이 겹치는 횟수를 배열에 저장한다. 
    for(string log : logs){
        int start = convert(log.substr(0,8));
        int end = convert(log.substr(9,8));
        for(int i=start; i<end;i++){
            totalSec[i] += 1;
        }
        
    }
    long long currSum = 0;
  
// 각 구간(광고시간 길이의)마다 시청시간의 합 중 가장 큰 값의 구간을 구한다. 겹치는 횟수를 더하면 시청시간의 합이된다.
    for(int i=0; i<advSec;i++){
        currSum += totalSec[i];
    }
    long long maxSum = currSum;
    int maxIdx = 0;
    for(int i=advSec;i<playSec;i++){
       currSum += totalSec[i]-totalSec[i-advSec]; 
       if(currSum > maxSum){
        maxSum = currSum;
        maxIdx= i-advSec +1;
       }
    }
    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", maxIdx / 3600, maxIdx / 60 % 60, maxIdx%60);
    string answer = buf;
    return answer;
}
