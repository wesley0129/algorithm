#include <iostream>
#define SWAP(x, y, temp) ( (temp)=(x), (x) = (y), (y) = (temp) )
using namespace std;

int partition(int* arr, int left, int right) {
    int pivot, temp;
    pivot = arr[left];
    int low = left + 1;
    int high = right;
    while(1){
        int check = 0;
        while(low<=right && arr[low] < pivot){
            low++;
        }
        while(high>=left && arr[high] > pivot){
            high--;
        }
        if(low >= high) break;
        SWAP(arr[low], arr[high], temp);
        
    }
    SWAP(arr[left], arr[high], temp);

    return high;
}

void quick_sort(int* arr, int left, int right) {
     if(left < right) {
        int q = partition(arr, left, right);
        quick_sort(arr, left, q - 1);
        quick_sort(arr, q + 1, right);
     }
}
int main(){
    int n;
    cin>>n;
    int* sort = new int[n];
    for(int i = 0; i < n; i++){
        cin>>sort[i];
    }
    quick_sort(sort, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout<<sort[i]<<"\n";
    }
}