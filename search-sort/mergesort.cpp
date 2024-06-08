#include <iostream>
using namespace std;

void conqure(int list[] , int si , int ei , int mid){
    int *arr = new int[ei-si+1];
    int idx1 = si;
    int idx2 = mid+1;
    int x = 0;

    while(idx1 <= mid && idx2 <= ei){
        if(list[idx1] <= list[idx2]){
            arr[x] = list[idx1];
            x++;
            idx1;;
        }
        else{
            arr[x] = list[idx2];
            x++;
            idx2++;
        }
    }
    while(idx2 <= ei){
        arr[x] = list[idx2];
         x++;
        idx2++;
    }
    while(idx1 <= mid){
        arr[x] = list[idx1];
        x++;
        idx1;;
    }
}
void divide(int list[] , int si , int ei){

    if(si >= ei){
        return;
    }
    int mid = si+ei/2;
    divide(list , si , mid);
    divide(list , mid+1 , ei);
    conqure(list , si , ei , mid);
}
int main(){
    int size = 5 ;
    int list[size] = {6 , 3 , 9 , 5 , 2 };
    divide(list , 0 , size-1);
    return 0;
}