#include <iostream>
using namespace std;
const int size = 10;
int array[size];
int heap = 0;

void maxHeapify(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && array[index] > array[parent])
    {
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void minHeapify(int index)
{
    int parent = (index - 1) / 2;
    while (parent > 0 && array[parent] > array[index])
    {
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(int data)
{
    if (heap == size - 1)
    {
        cout << "array is full";
        return;
    }
    else
    {
        array[heap] = data;
        heap++;
        maxHeapify(heap - 1);
        minHeapify(heap - 1);
    }
}

void deleted()
{

    array[0] = array[heap - 1];
    heap--;

    int index = 0;
    while (index < heap)
    {

        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        int largest = index;

        if (left < heap && array[left] > array[largest])
        {
            largest = left;
        }
        if (right < heap && array[right] > array[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            int temp = array[index];
            array[index] = array[largest];
            array[largest] = temp;

            index = largest;
        }
        else
        {
            return;
        }
    }
}

void print()
{

    for (int a = 0; a < size; a++)
    {
        cout << array[a] << " ";
    }
}

int main()
{

    insert(5);
    insert(10);
    insert(3);
    insert(7);
    insert(1);

deleted();
    print();
    return 0;
}