#include <iostream>
using namespace std;

int findPivot(int list[] , int low , int high){

int pivot = list[high];








}


void quickSort(int list[] , int low , int high){

    int pindx = findPivot(list,low,high);
    quickSort(list , low , pindx-1);
     quickSort(list , pindx+1 , high);

}


int main(){
int list[] = {6 , 3 , 9 , 5 , 2 , 9, 8};
int size = 7;
int low = 0;
int high = size-1;

quickSort(list , low , high);
    
    return 0;
}