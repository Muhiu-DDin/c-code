#include <iostream>
using namespace std;

void maxHeap(int list[] , int size , int index){
    int parent = (index-1)/2;
    while(index > 0 && list[parent]<list[index]){
        int temp = list[parent];
        list[parent] = list[index];
        list[index] = temp;

        index = parent;
        parent = (index-1)/2;
    }

}
void insert(int list[] , int size , int &heap , int data){
    if(heap == size){
        cout<<"no more space";
        return;
    }
    list[heap] = data;
    heap++;
    maxHeap(list , size , heap-1);
}
void deleted(int list[] , int size , int& heap){
   swap(list[0] , list[size-1]);
    heap--;
    int index = 0;
    while(index < heap){
    int left = (index*2)+1;
    int right = (index*2)+2;
    int largest = index;
    if(heap > left && list[largest]<list[left]){
        largest = left;
    }
    if(right < heap && list[largest]<list[right]){
        largest = right;
    }
    if(largest != index){
        swap(list[largest] , list[index]);
        index = largest;
    }
    else{
        return;
    }
    }
}
void maxHeapForSort(int list[] , int index , int& heap){
    while(index < heap){
    int left = (index*2)+1;
    int right = (index*2)+2;
    int largest = index;
    if(heap > left && list[largest]<list[left]){
        largest = left;
    }
    if(right < heap && list[largest]<list[right]){
        largest = right;
    }
    if(index!=largest){
        swap(list[largest] , list[index]);
        index = largest;
    }
    else{
        return;
    }
    }
}
void heapSort(int list[] , int&heap){
    for(int a = heap/2-1 ; a>= 0 ; a--){
    maxHeapForSort(list , a , heap);
    }
    for(int a = heap-1 ; a>0 ; a--){
        swap(list[a] , list[0]);
        maxHeapForSort(list , 0 , a);
    }
}


void print(int list[] ,int &heap){
    for(int a = 0 ; a < heap ; a++){
        cout<<list[a]<<" ";
    }
}
int main(){
    int size = 5;
    int heap = 0;
    int list[size];

    insert(list , size , heap , 32);
    insert(list , size , heap , 54);
    insert(list , size , heap , 76);
    insert(list , size , heap , 39);
    insert(list , size , heap , 69);  

    // deleted(list , size , heap);
        print(list , heap);
        cout<<endl;

    heapSort(list , heap);
     
  

    print(list , heap);
    return 0;
}