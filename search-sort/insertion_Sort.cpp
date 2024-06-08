#include <iostream>
using namespace std;

void insertionSort(int list[] , int size){

for(int i = 1 ; i < size ; i++ ){
    int j = i-1;
    int temp = list[i];
    while(j >= 0 && temp<list[j]){
        list[j+1] = list[j]; 
        j--; 
    }
    list[j+1] = temp; 
}
}

void print(int list[] , int size){
    for(int i = 0 ; i < size ; i++){
        cout<<list[i]<< " ";
    }
}

int main(){
    
    int list[] = {7, 8 , 3, 2,1};
    int size = 5;

    insertionSort(list , size);
    print(list , size);

    
    return 0;
}