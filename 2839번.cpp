#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int min = 5000;
    int it = N/5;
    for(int i=0; i<=it; i++){
        int M = N;
        M = M-(i*5);
        if(M%3==0){
            int cnt = i;
            cnt += M/3;
            if(cnt<min) min = cnt;
        }
    }
    if(min==5000) cout<<-1;
    else cout<<min;
    return 0;
}