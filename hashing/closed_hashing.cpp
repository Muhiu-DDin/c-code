// #include <iostream>
// using namespace std;


// // USING LINEAR PROBING:

// #include <iostream>
using namespace std;

void insert(int list[] , int size , int key ){
    int index = key%size;
    int original_index = index;

    if(list[index] == -1){
        list[index] = key;
    }
    else{
        while(list[index] != -1){
        index = (index+1)%size;
        if(index == original_index){
            cout<<"no more space";
            return;
        }
        }
        list[index] = key;
    }
}
void search(int list[] , int key , int size){
    int index = key%size;
    int original_index = index;

    if(list[index] == key){
        cout<<"found";
        return;
    }
    else{
        while(list[index] != key){
            index = (index+1)%size;
            if(index == original_index){
                cout<<"not found";
                return;
            }
        }
        cout<<"found";
    }
}

void print(int list[] , int size){
    for(int a = 0 ; a < size ; a++){
        cout<<list[a]<<" ";
    }
}



int main(){

    int size = 10;
    int list[size];

    for(int a = 0 ; a < size ; a++){
        list[a]  = -1;
    }

    insert(list , size , 10);
    insert(list , size , 20);
    insert(list , size , 30);
    insert(list , size , 43);
    insert(list , size , 31);

    print(list , size);
    search(list , 22 , size);
    

    return 0;
}

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

    

//     search(30 , array , size);



//     for (int a = 0; a < size; a++)
//     {
//         cout << array[a] << endl;
//     }

//     return 0;
// }


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
      
//         index = (original_Index + i*i) % size; 
//         i++;
    
//     if (original_Index == index)
//         {
//             cout << "array is full"<<endl;
//             return;
//         }
//     }
//     array[index] = key_refer ;
// }

// void search(int key , int array[] , int size){

//     int index = key%size;
//    int original_Index =  index;

//     int i = 1;
//     while(array[index]!=-1){

//         index = (index+i*i)%size;
//         i++;
//         if(original_Index==index){
//             cout<<"not found"<<endl; 
//             return;
//         }
//     }

//     cout<<"found at index :"<<" "<<index<<endl;
//     return;
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
    
//     search(50 , array , size); 


//     for (int a = 0; a < size; a++)
//     {
//         cout << array[a] << endl;
//     }

//     return 0;
// }

// -----------------------------------
// #include <iostream>
// using namespace std;

// const int size = 10;
// int array[size];

// void insert(int key)
// {

//     int index = key % size;
//     int originalIndex = index;

//     if (array[index] == -1)
//     {
//         array[index] = key;
//     }
//     else
//     {
//         int i = 1;
//         while (array[index] != -1)
//         {
//             index = (index + i) % size;
//             if (index == originalIndex)
//             {
//                 cout << "array is full";
//                 return;
//             }
//         }
//         array[index] = key;
//     }
// }

// void search(int key)
// {
//     int index = key % size;
//     int originalIndex = index;

//     if (array[index] == key)
//     {
//         cout << "found";
//         return;
//     }

//     else
//     {
//         while (array[index] != key)
//         {
//             index = (index + 1) % size;

//             if (index == originalIndex)
//             {
//                 cout << "not found"<<endl;
//                 return;
//             }
//         }
//         cout << "found"<<endl;
//         return;
//     }
// }

// void print()
// {
//     for (int a = 0; a < size; a++)
//     {
//         cout << array[a] << endl;
//     }
// }

// int main()
// {

//     for (int a = 0; a < size; a++)
//     {
//         array[a] = -1;
//     }

//     insert(10);
//     insert(20);
//     insert(30);
//     insert(40);
//     insert(50);
//     insert(60);

//     search(50);

//     print();

//     return 0;
// }