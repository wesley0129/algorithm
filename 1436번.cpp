#include <iostream>
using namespace std;
bool check(int num){
    string str = to_string(num);
    for(int i=0; i<str.size(); i++){
        if(str.substr(i,3) == "666") return true;
    }
    return false;
}
int main(){
    //n번째로 작은 종말의 수 찾기
    int n = 666;
    int N;
    cin>>N;
    int i=666;
    while(true){
        if(check(i)){
            N--;
            if(N==0){
                cout<<i;
                break;
            }
        }
        i++;
    }
    return 0;
}