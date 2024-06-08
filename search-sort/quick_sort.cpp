#include <iostream>
using namespace std;

int findPivot(int list[] , int low , int high){

int pivot = list[high];
int i = low-1;

for(int j = low ; j < high ; j++ ){
    if(list[j]< pivot){
        i++;
        int current = list[i];
        list[i]=list[j];
        list[j]=current;
    }
}
i++; 

int temp = list[i];
list[i] = list[high];
list[high] = temp;

return i;
}


void quickSort(int list[] , int low , int high){

if(low < high){
    int pindx = findPivot(list,low,high);
    quickSort(list , low , pindx-1);
    quickSort(list , pindx+1 , high);
}
}


void print(int list[] , int size){
    for(int a = 0 ; a < size ; a++)
    {
        cout<<list[a]<<" ";
    }
}


int main(){
int list[] = {6 , 3 , 5 , 2 , 9, 8};
int size = 6;
int low = 0;
int high = size-1;

quickSort(list , low , high);
print(list , size);
    
    return 0;
}