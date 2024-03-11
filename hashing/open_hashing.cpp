#include <iostream>
using namespace std;


// USING LINEAR PROBING:

void insert(int key, int array[], int size)
{

    int key_refer = key;

    int index = key_refer % size;
    int original_Index = index;

    int i = 1 ;
    while (array[index] != -1) 
    {
      
        index = (index + i) % size;
 
        if (original_Index == index)
        {
            cout << " no more insertion as array is full"<<endl;
            return;
        }
    }
    array[index] = key_refer ;
}

void search(int key , int array[] , int size){

int index = key % size;
int original_Index = index;

    while(array[index] != key ){
        index = (index+1)%size;

        if(original_Index == index){
            cout<<"not found"<<endl;
            return;
        }
    }

    cout<<"found"<<endl;
    return;
}

int main()
{

    cout << "enter size of array";
    int size;
    cin >> size;

    int array[size];

    for (int a = 0; a < size; a++)
    {
        array[a] = -1;
    }

    insert(10, array, size);
    insert(20, array, size);
    insert(30, array, size);
    insert(40, array, size);
    insert(50, array, size);

    

    search(30 , array , size);



    for (int a = 0; a < size; a++)
    {
        cout << array[a] << endl;
    }

    return 0;
}


// -------------------------------------------------------------------------------------------

// #include <iostream>
// using namespace std;

// // USING QUADRATIC PROBING:

// void insert(int key, int array[], int size)
// {

//     int key_refer = key;

//     int index = key_refer % size;
//     int original_Index = index;

//     int i = 1 ;
//     while (array[index] != -1) 
//     {
      
//         index = (index + i*i) % size;
//         i++;
 
//         if (original_Index == index)
//         {
//             cout << " no more insertion as array is full"<<endl;
//             return;
//         }
//     }
//     array[index] = key_refer ;
// }

// int main()
// {

//     cout << "enter size of array";
//     int size;
//     cin >> size;

//     int array[size];

//     for (int a = 0; a < size; a++)
//     {
//         array[a] = -1;
//     }

//     insert(10, array, size);
//     insert(20, array, size);
//     insert(30, array, size);
//     insert(40, array, size);
//     insert(50, array, size);
//     insert(60, array, size);
    

//     for (int a = 0; a < size; a++)
//     {
//         cout << array[a] << endl;
//     }

//     return 0;
// }