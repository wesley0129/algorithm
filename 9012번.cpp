#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <stack>
using namespace std;

bool check(string tmp){
    stack<char> ps;
    for(auto i:tmp){
        if(ps.top() == '(' && i==')'){
            ps.pop();
        }else{
            ps.push(i);
        }
    }
    if(ps.empty()){
        return true;
    }
    else{
        return false;
    }
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
}