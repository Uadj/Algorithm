#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        if(int(i/n)>i%n)
            answer.push_back((int(i/n))+1);
        else
            answer.push_back((i%n)+1);
    }
    return answer;
}
