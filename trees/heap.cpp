#include <iostream>
using namespace std;


void maxHeap(int list[] , int index, int size){
    int parent = (index-1)/2;
    while(index > 0  &&  list[parent] < list[index]){
        int temp = list[parent];
        list[parent] = list[index];
        list[index] = temp;
        index = parent;
        parent = (index-1)/2;
    }
}
void minHeap(int list[] , int index , int size){
    int parent = (index-1)/2;
    while(index > 0 && list[parent] >= 0 && list[parent] > list[index]){
        int temp = list[parent];
        list[parent] = list[index];
        list[index] = temp;
        index = parent;
        parent = (index-1)/2;
    }
}
void deletedMax(int list[] , int size , int& heap){
    list[0] = list[heap-1];
    heap--;
    int index = 0 ;

    while(index < heap){
    int left = (2*index)+1;
    int right = (2*index)+2;
    int largest = index;

    if(left < heap && list[largest]<list[left]){
        largest = left;
    }
    if(right < heap && list[largest]<list[right]){
        largest = right;    
    }
    if(index != largest){
        int temp = list[largest];
        list[largest] = list[index];
        list[index] = temp;

        index = largest;
    }
    else{
        return;
    }
    }
}
void maxHeapForSort(int list[] ,  int index , int& heap){
    while(index < heap){
    int left = (2*index)+1;
    int right = (2*index)+2;
    int largest = index;

    if(left < heap && list[largest]<list[left]){
        largest = left;
    }
    if(right < heap && list[largest]<list[right]){
        largest = right;    
    }
    if(index != largest){
        int temp = list[largest];
        list[largest] = list[index];
        list[index] = temp;

        index = largest;
    }
    else{
        return;
    }
    }
}
void heapSort(int list[] , int size , int&heap){
    for(int i = heap/2-1 ; i >= 0 ; i--){
        maxHeapForSort(list , i , heap);
    }
    for(int i = heap-1 ; i > 0 ; i--){
        int temp = list[0];
        list[0] = list[i];
        list[i] = temp;
        maxHeapForSort(list , 0 , i);
    }
}
void insert(int list[] , int size , int& heap , int data){
     if (heap == size)
    {
        cout << "array is full";
        return;
    } 
    list[heap] = data;
    heap++;
    maxHeap(list , heap-1 , size);
}
void print(int list[] , int heap){
    for(int a = 0 ; a < heap ; a++){
        cout<<list[a]<<" ";
    }
}

int main(){
    int size = 5;
    int heap = 0;
    int list[size];
    insert(list , size , heap , 10);
    insert(list , size , heap , 50);
    insert(list , size , heap , 90);
    insert(list , size , heap , 20);
    insert(list , size , heap , 60);
   print(list , heap);
   cout<<endl;
    heapSort(list , size , heap);
    print(list , heap);
    }