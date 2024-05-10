#include <iostream>
using namespace std;

int binarysearch(int li[] , int n , int key){

int left = 0;
int right = n-1;

while(left<=right){

    int mid = (left+right)/2;

    if(li[mid] == key){
        
        cout<<"your desire number have found at"<< mid <<endl;
        return;
    }

    else if(li[mid] < key){
        left = mid + 1;
    }

    else{
        right = mid-1;
    }

}

cout<<"not found"<<endl;
return -1;

}

int main(){
    
    int n;
    cout<<"enter the length of array";
    cin>>n;

    int array [n];
    for (int a = 0 ; a<n ; a++){
        cin>>array[a];
    }

    int key;
    cout<<"enter your desire number"<<endl;
    cin>>key;

    cout<<binarysearch(array , n , key);

    return 0;
}