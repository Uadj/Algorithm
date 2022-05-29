/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int n,m;
int arr[100][100]={100000};
int INF = 10000001;
int main()
{
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            arr[i][j]=10000001;
            if(i==j) arr[i][j]=0;
        }
    }
    for(int i=0; i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(arr[a-1][b-1]>c)
            arr[a-1][b-1]=c;
    }
        
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            for(int k=0; k<n;k++){
                if(arr[k][j]> arr[i][j]+arr[k][i]){
                    arr[k][j] = arr[i][j]+arr[k][i];
                }
            }
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(arr[i][j]==INF) arr[i][j]=0;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
