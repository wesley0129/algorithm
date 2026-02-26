#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    vector<string> pVec;
    map<int, string> pMap;
    map<string, int> oMap;
    for(size_t i=0; i<N; i++){
        string name;
        cin>>name;
        pMap[i] = name;
        oMap[name] = i;
    }
    for(size_t i=0; i<M; i++){
        string str;
        cin>>str;
        if(isdigit(str[0])){
            int num = stoi(str);
            pVec.push_back(pMap[num-1]);
        }
        else {
            pVec.push_back(to_string(oMap[str]+1));
        }
    }
    for(auto s : pVec){
        cout<<s<<"\n";
    }
}