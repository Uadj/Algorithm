#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int N = arr1[0].size();
    int M = arr1.size();
    int L = arr2[0].size();
    vector<vector<int>> answer(M, vector<int>(L));
    
    
    for(int i=0; i<M;i++){
        for(int k=0; k<L;k++){
            int temp=0;
        for(int j=0; j<N;j++){
            
                temp += arr1[i][j]*arr2[j][k];
                //cout << arr1[i][j]*arr2[j][i+k] << endl;;
            }
            answer[i][k]=temp;
            //cout << temp<<endl;
        }
    }
    return answer;
}
