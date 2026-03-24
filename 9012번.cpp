#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

bool check(string tmp){
    stack<char> ps;
    for(auto i:tmp){
        if(!ps.empty() && ps.top() == '(' && i==')'){
            ps.pop();
        }else{
            ps.push(i);
        }
    }
    return ps.empty();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ans;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        if(check(tmp)){
            ans.push_back("YES");
        }else{
            ans.push_back("NO");
        }
    }
    for(auto a: ans){
        cout<<a<<"\n";
    }
    return 0;
}