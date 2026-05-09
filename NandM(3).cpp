#include <iostream>
#include <vector>
using namespace std;

vector<int> box;
vector<vector<int>> result;

void dfs(int n, int m){
    if(box.size()==m){
        result.push_back(box);
        return;
    }

    for(int i=1;i<=n;i++){
        box.push_back(i);
        dfs(n, m);
        box.pop_back();    
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m, first = 1;
    cin>>n>>m;
    dfs(n, m);
    for(auto arr: result){
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}