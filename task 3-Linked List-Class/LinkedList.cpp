#include <iostream>
using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
};

class LinkedList {
    public:
        Node* head;
        Node* tail;

        LinkedList() : head(nullptr), tail(nullptr) {};

    
        void insert(string data){
            Node* node = new Node();
            node->data= data;

           

                if(head == nullptr){
                    head = node;
                    tail = node;
                }else{
                    tail->next = node;
                    tail = node;
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
};


int main(){
    LinkedList* ll;
    ll= new LinkedList();

    ll->insert("Thsi is a word");
    ll->insert("sup boi");
    
    string data;
    cout << "Enter (Exit) to Exit" << "\n";
    for (int i =0 ; ;i++){
        cout << "Enter another paragraph: ";
        getline(cin,data);
        if(data == "Exit"){
            break;
        }else{
            ll->insert(data);
        }
    }
    ll->displayList();
}   



// construrctor initializer list: helps in compostion, to pass values before allocation as engine runs first before car.
// composition: an ibject exist within an object. a car has a engine.