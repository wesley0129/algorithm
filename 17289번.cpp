#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
//오큰수: NGE(i)는 Ai의 오른쪽에 있으면서 Ai보다 큰 수 중에 가장 왼쪽에 있는 수.


vector<int> calc(vector<int> a){
    vector<int> vec(a.size());
    stack<int> st; 
    for(int i=0; i<a.size(); i++){
        while(!st.empty() && a[st.top()] < a[i]){
            vec[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        vec[st.top()] = -1;
        st.pop();
    }
    return vec;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> out(n);
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        out[i] = tmp;
    }
    out = calc(out);

    for(auto i: out){
        cout<<i<<" ";
    }
    return 0;
}