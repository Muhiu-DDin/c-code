#include <iostream>
using namespace std;

// int main(){

//      int l1 [] = {99 , 88 , 77 , 66};

//     int *p = l1;

//      for (int a = 0 ; a<4 ; a++){
//             cout<<*(p+a)<<endl;
//      }
//     return 0;
// }

// ---------------------------------------------------


// using reference variable

// void swapping (int &a , int &b){
//     int temp = a;
//     a = b ; 
//     b = temp ;
// }

// int main(){

//    int li [] = {88 , 55 , 44 ,22};

//     cout<<" before swapping the value of li[0] is"<<li[0]<<endl;
//    cout<<" before swapping the value of li[3] is"<<li[3]<<endl;

//    swapping(li[0] , li[3]);

//     cout<<" after swapping the value of li[0] is"<<li[0]<<endl;
//    cout<<"after swapping the value of li[3] is"<<li[3]<<endl;

//     return 0;
// }



//  ---------------------------------------------------



// using pointers

// void swapping (int* a , int* b){

//     int temp = *a;
//     *a = *b ; 
//     *b = temp ;
// }

// int main(){

//    int li [] = {88 , 55 , 44 ,22};

//     cout<<" before swapping the value of li[0] is"<<li[0]<<endl;
//    cout<<" before swapping the value of li[3] is"<<li[3]<<endl;

//    swapping(&li[0] , &li[3]);

//     cout<<" after swapping the value of li[0] is"<<li[0]<<endl;
//    cout<<"after swapping the value of li[3] is"<<li[3]<<endl;

//     return 0;
// }