#include <iostream>
using namespace std;

int main(){
    
    int key;
    cout<<"enter the desire number";
    cin>>key;
    int a;

    int li [] = {5,3,7,43,2};

    for(a=0 ; a<5 ; a++){

        if(li[a]==key){
            cout<<"your desire number have found at"<< a <<endl;
            break;
            
            //either use return or break , bcz both terminate the loop;
        }
    }

    cout<<"not found";
    return -1;
}