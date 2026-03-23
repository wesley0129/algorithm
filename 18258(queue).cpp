#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

int arr[2000000];
//front는 맨 앞, rear는 맨 뒤 +1 값
class Queue {
    private:
        int front, rear;
    public:
        Queue(){
            front=rear=-1;
        };
        void push(int x){
            if(front==-1){
                front++;
                arr[front]=x;
                rear=1;
            }else{
                arr[rear]=x;
                rear++;
            }
        };
        void pop(){
            if(front==rear){
                cout<<-1<<"\n";
            }else{
                cout<<arr[front]<<"\n";
                front++; 
            }    
        };
        void size(){
            if(front==rear){
                cout<<0<<"\n";
            }else{
                cout<<rear-front<<"\n";
            } 
        };
        void empty(){
            if(front==rear){
                cout<<1<<"\n";
            }else{
                cout<<0<<"\n";
            } 
        };
        void Front(){
            if(front==rear){
                cout<<-1<<"\n";
            }else{
                cout<<arr[front]<<"\n";
            }
        };
        void Back(){
            if(front==rear){
                cout<<-1<<"\n";
            }else{
                cout<<arr[rear-1]<<"\n";
            }
        };
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Queue queue;
    for(size_t i=0;i<n;i++){
        string order;
        cin>>order;
        if(order=="push"){
            int num;
            cin>>num;
            queue.push(num);
            continue;
        }
        if(order=="pop"){
            queue.pop();
            continue;
        }
        if(order=="front"){
            queue.Front();
            continue;
        }
        if(order=="back"){
            queue.Back();
            continue;
        }
        if(order=="size"){
            queue.size();
            continue;
        }
        if(order=="empty"){
            queue.empty();
            continue;
        }
    }
    return 0;
}