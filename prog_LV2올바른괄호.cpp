#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int flag = 0;
    for(int i=0; i<s.size();i++){
        if(flag<0) break;
        if(s[i]=='(') flag++;
        else flag--;
    }
    if(flag==0) return true;
    else return false;

        
}

/* 효율성 통과 실패 코드
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
 
    bool flag=true;

        int L = s.size();
        int i=0;
        for(int i=0; i<L;i++){
            if(s[i]=='(' && s[i+1]==')'){
                if(i==0){
                    s = s.substr(2,L);
                    i-=2;
                    L-=2;
                }
                else{
                    s = s.substr(0,i)+s.substr(i+2,L);
                    i-=2;
                    L-=2;
                }
                //cout << s << endl;
            }
            
        } 
    
    if(s=="") answer = true;
    else answer = false;
    return answer;
}
*/
