#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, count;
    count=0;
    cin>>N;
    for(size_t it=0; it<N; it++){
        int temp, root;
        cin>>temp;
        if(temp==1 || temp==2){
            continue;
        }else if(temp==3){
            count++;
        }
        else{
            bool check = false;
            root = sqrt(temp);
            root = static_cast<int>(root);
            for(size_t jt=2; jt<=root; jt++){
                if(temp%jt==0){
                    check = true;
                }
            }
            if(!check){
                count++;
            }
        }
    }
    cout<<count<<endl;
    
    return 0;
}