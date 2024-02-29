#include <iostream>
using namespace std;

// in selection sort array decreases form left side while in bubble sort array decreases from right side

void selectionsort(int list[] , int n){

for (int a = 0 ; a<n-1 ; a++){
    int smallerindex = a;
    for(int b = a+1 ; b<n ; b++){
        if(list[smallerindex]>list[b]){
            smallerindex = b;
        }
    }

     int temp =list[smallerindex];
      list[smallerindex] = list[a];
        list[a] = temp;
}

for(int y = 0 ; y<n ; y++){
    cout<<list[y]<<endl;
}

}

int main(){

    int n;
    cout<<"enter the length of array";
    cin>>n;

    int array[n];
    cout<<"enter the itmes of array";
    for(int x = 0 ; x<n ; x++){
        cin>>array[x];
    }

    selectionsort(array , n);

}