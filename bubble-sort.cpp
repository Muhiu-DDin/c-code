#include <iostream>
using namespace std;

void bubblesort(int li[] , int n){

    for (int a = 0 ; a<n-1 ; a++){
        for(int b = 0 ; b<n-a-1 ; b++){
            if(li[b]>li[b+1]){
                int temp = li[b];
                li[b] = li[b+1];
                li[b+1] = temp;
            }
        }
    }

    for(int x = 0 ; x<n ; x++){
        cout<< li[x]<<" ";
    }

}

int main(){

int n;
cout<<"enter the length of array"<<endl;
cin>>n;

int array [n];
cout<<"enter the list items"<<endl;
for (int a = 0 ; a<n ; a++){
    cin>> array[a];
}

bubblesort(array , n);
    return 0;
}