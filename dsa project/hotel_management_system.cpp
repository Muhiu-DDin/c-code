#include <iostream>
using namespace std;

class Hotel{

private:
    struct Node{
    int ID,date;
    string customerName,roomType;
    Node* next;
    };

public: 
    Node* head = NULL;
    void menu();
    void insertRoom();
    void searchRoom();
    void updateRoomRecord();
    void del();
    void sort();
    void show();
    void list();
};

void Hotel::menu(){
    int choice;

    cout<<"\n\n\t Welcome To Hotel Management System"<<endl;
    cout<<"\n\t __________Hotel Management System__________"<<endl;
    cout<<"\n\t SN:       Funtions:               Descriptons:";
    cout<<"\n\t 01 \t Allocate Room \t\t Insert New Room";
    cout<<"\n\t 02 \t Search Room \t\t Search Room Via Room ID";
    cout<<"\n\t 03 \t Update Room \t\t Update Room Record Via Room ID";
    cout<<"\n\t 04 \t Delete Room \t\t Delete Room Record Via Room ID";
    cout<<"\n\t 05 \t Show Room Record\t Display Room Record";
    cout<<"\n\t 06 \t exit";

    cout<<"\n\n ENTER YOUR CHOICE";
    cin>>choice;

    switch(choice){
        case 1 :
            insertRoom();
            menu();
            break;
        case 2 :
            searchRoom();
            menu();
            break;
        case 3:
            updateRoomRecord();
            menu();
            break;
        case 4:
            del();
            menu();
            break;
        case 5:
            sort();
            show();
            menu();
            break;
        case 6:
            exit(0);
            break;
        default:
        cout<<"invalid";
    }
}

void Hotel::insertRoom(){
    cout<<"\n\t _______Hotel Management System_______\n";
    Node* new_node = new Node();
    new_node->next = NULL;

    cout<<"\n ENTER ROOM ID";
    cin>>new_node->ID;

    cout<<"\n ENTER YOUR NAME";
    cin>>new_node->customerName;

    cout<<"\n ENTER ROOM TYPE";
    cin>>new_node->roomType;

    cout<<"\n ENTER CURRENT DATE";
    cin>>new_node->date;

    if(head==NULL){
        head = new_node;
    }
    else{
        Node* ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout<<"\n\n \t New Room Inserted";
}

void Hotel::searchRoom(){
     cout<<"\n\t _______Hotel Management System_______\n";

     int ID;
     cout<<"\n\t ENTER YOUR ROOM ID";
     cin>>ID;

     if(head == NULL){
        cout<<"Linked List Is Empty";
        return;
     }
     else{
        Node* ptr = head ;
        while(ptr!=NULL){
            if(ID==ptr->ID){
                cout<<"\n\t Your Room Record:";
                cout<<"\n\n\t ROOM ID"<< " " << ptr->ID;
                cout<<"\n\t CUSTOMER NAME"<< " " << ptr->customerName;
                cout<<"\n\t ROOM TYPE"<< " " << ptr->roomType;
                cout<<"\n\t ALLOCATED DATE"<< " " << ptr->date;
                return;
            }
            else{
                ptr = ptr->next;
            }
        }
     }
}

void Hotel::updateRoomRecord(){
     cout<<"\n\t _______Hotel Management System_______\n";

     int ID;
     cout<<"\n\n\t ENTER YOUR ROOM ID";
     cin>>ID;

     if(head == NULL){
        cout<<"Empty Linked List";
        return;
     }
     else{
     Node* ptr = head;
     while(ptr != NULL){
        if(ID == ptr->ID){

            cout<<"\n\t ENTER NEW ROOM ID";
            cin>>ptr->ID;

            cout<<"\n\t ENTER NEW CUSTOMER NAME";
            cin>>ptr->customerName;

            cout<<"\n\t ENTER NEW ROOM TYPE";
            cin>>ptr->roomType;

            cout<<"\n Room Record Updated Successfully";
            return;

        }
        else{
            ptr = ptr->next;
        }
     }
     }
}

void Hotel::del()
{
   cout<<"\n\t _______Hotel Management System_______\n";
    int ID;

    cout<<"\n ENTER YOUR ROOM ID";
    cin>>ID;

    if (head == NULL){
         cout<<"Empty Linked List";
         return;
    }
    else{
        Node* ptr = head;
        Node* prev = NULL;

        while(ptr != NULL){
            if(ID == ptr->ID){
                if(prev == NULL){
                    head = ptr->next;
                    delete ptr;
                }
                else if(ptr->next == NULL){
                    prev->next = NULL;
                    delete ptr;
                }
                else{
                    prev->next = ptr->next;
                    delete ptr;
                }
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
cout<<"\n\t Record Deleted Successfully";
}

void Hotel::show(){
    Node* ptr = head;
        while(ptr != NULL){
            cout<<"\n\t Your Room Records:";
            cout<<"\n\n\t ROOM ID:"<< " " << ptr->ID;
            cout<<"\n\t CUSTOMER NAME:"<< " " << ptr->customerName;
            cout<<"\n\t ROOM TYPE:"<< " " << ptr->roomType;
            cout<<"\n\t ALLOCATED DATE:"<< " " << ptr->date;

            ptr = ptr->next;
        }
}

void Hotel:: sort(){
    Node* ptr = head;
    int count = 0 ;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    int cID,rDate;
    string cName,rType;

    for(int a = 0 ; a < count-1 ; a++){
        Node* curr = head;
        for(int b = 0 ; b < count-a-1 ; b++){
         if(curr->ID > curr->next->ID){
            cID = curr->ID;
            rDate = curr->date;
            cName = curr->customerName;
            rType = curr->roomType;

            curr->ID = curr->next->ID;
            curr->customerName = curr->next->customerName;
            curr->roomType = curr->next->roomType;
            curr->date = curr->next->date;

            curr->next->ID = cID;
            curr->next->customerName = cName;
            curr->next->date = rDate;
            curr->next->roomType = rType;

         }   
         curr = curr->next;
        }
    }
}

int main(){

    Hotel h1;
    h1.menu();

    return 0;
}