#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int calc(string prob){
    int result=0;
    stack<int> st;
    for(auto i: prob){
        if(i =='(') st.push(-1);
        else if(i == '[') st.push(-2);
        else if(i == ')'){
            int sum=0;    
            while(!st.empty() && st.top()>0){
                sum+=st.top();
                st.pop();
            }
            if(st.empty() || st.top()!=-1){
                return 0;
            }
            st.pop();
            if(sum==0) st.push(2);
            else st.push(2*sum);
        }
        else if(i == ']'){
            int sum=0;    
            while(!st.empty() && st.top()>0){
                sum+=st.top();
                st.pop();
            }
            if(st.empty() || st.top()!=-2){
                return 0;
            }
            st.pop();
            if(sum==0) st.push(3);
            else st.push(3*sum);
        }
    }
    while(!st.empty()){
        if(st.top()<0) return 0;
        else{
            result+=st.top();
            st.pop();
        }
    }
    return result;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string prob;
    cin>>prob;
    cout<<calc(prob)<<"\n";
    return 0;
};