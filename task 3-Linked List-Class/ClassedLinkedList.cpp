#include <iostream>
#include "ClassedLinkedList.h"

using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
};

ClassedLinkedList::ClassedLinkedList() {
    this->head = nullptr;
    this->tail= nullptr;
}

class ClassedLinkedList::insertAtHead(string data)
{
            Node* node = new Node();
            node->data= data;

            if(this->head != nullptr){
                    node->next = head;
                    this->head = node;
            }else{
                   this->tail= this->head = node;
            }
            
}

class ClassedLinkedList::insertAtTail(string data)
{
            Node* node = new Node();
            node->data= data;

            if(this->head != nullptr){
                    this->tail->next = node;
                    this->tail = node;
            }else{
                   this->tail = this->head = node;
            }
            
}

        void displayList (){
            Node* cur = head;
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->next;
                }
            }
        // void deleteAt(int location){
        //     if(location < 0 ){
        //         location= 0;
        //     }
        //     Node* cur = head; 
        //     for(int i=0; i<=location; i++){
        //         cur = cur->next;
        //     }
        //     // delete 
        // }

    


int main(){
    LinkedList* ll;
    ll= new LinkedList();

    ll->insertAtHead("Thsi is a word");
    ll->insertAtHead("sup boi");
    
    string data;
    cout << "Enter (Exit) to Exit" << "\n";
    for (int i =0 ; ;i++){
        cout << "Enter another paragraph: ";
        getline(cin,data);
        if(data == "Exit"){
            break;
        }else{
            ll->insertAtHead(data);
        }
    }
    ll->displayList();
}   



// construrctor initializer list: helps in compostion, to pass values before allocation as engine runs first before car.
// composition: an ibject exist within an object. a car has a engine.