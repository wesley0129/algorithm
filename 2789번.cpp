#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    int N,M;
    cin>>N>>M;
    while(N--){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    int max = 0;
    for (int i=0;i<arr.size()-2; i++){
        int a=0;
        a+=arr[i];
        if(a>M) continue;
        for(int j=i+1; j<arr.size()-1; j++){
            a+=arr[j];
            if(a>M){
                a-=arr[j];
                continue;
            }
            for(int k=j+1; k<arr.size(); k++){
                a+=arr[k];
                if(a>M){
                    a-=arr[k];
                    continue;
                }else{
                    if(a>max){
                        max=a;
                    }
                    a-=arr[k];
                }
            }
            a-=arr[j];
        }
    }
    cout<<max;
    return 0;
}