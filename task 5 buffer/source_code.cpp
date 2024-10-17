// This is 7kb size file 

#include <iostream>
using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insert(string data){
            Node* node = new Node();
            node->data= data;

                if(head == nullptr){
                    head = node;
                }
                else if(tail == nullptr){
                    tail = node;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=node;
                    node->prev=tail;
                    tail=node; 
                }
            
        }

        void displayList (){
            Node* cur = head;
            cout << "\n-Straight-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->next;
                }
            }

        void displayListReverse (){
            Node* cur = tail;
            cout << "\n-Reversed-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->prev;
                }
            }
        
};


int main(){
    DoublyLinkedList* ll;
    ll= new DoublyLinkedList();

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
    ll->displayListReverse();
}   

#include <iostream>
using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insert(string data){
            Node* node = new Node();
            node->data= data;

                if(head == nullptr){
                    head = node;
                }
                else if(tail == nullptr){
                    tail = node;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=node;
                    node->prev=tail;
                    tail=node; 
                }
            
        }

        void displayList (){
            Node* cur = head;
            cout << "\n-Straight-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->next;
                }
            }

        void displayListReverse (){
            Node* cur = tail;
            cout << "\n-Reversed-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->prev;
                }
            }
        
};


int main(){
    DoublyLinkedList* ll;
    ll= new DoublyLinkedList();

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
    ll->displayListReverse();
}   










// DATA 




#include <iostream>
using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insert(string data){
            Node* node = new Node();
            node->data= data;

                if(head == nullptr){
                    head = node;
                }
                else if(tail == nullptr){
                    tail = node;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=node;
                    node->prev=tail;
                    tail=node; 
                }
            
        }

        void displayList (){
            Node* cur = head;
            cout << "\n-Straight-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->next;
                }
            }

        void displayListReverse (){
            Node* cur = tail;
            cout << "\n-Reversed-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->prev;
                }
            }
        
};


int main(){
    DoublyLinkedList* ll;
    ll= new DoublyLinkedList();

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
    ll->displayListReverse();
}   


#include <iostream>
using namespace std;
struct Node{
    string data;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insert(string data){
            Node* node = new Node();
            node->data= data;

                if(head == nullptr){
                    head = node;
                }
                else if(tail == nullptr){
                    tail = node;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=node;
                    node->prev=tail;
                    tail=node; 
                }
            
        }

        void displayList (){
            Node* cur = head;
            cout << "\n-Straight-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->next;
                }
            }

        void displayListReverse (){
            Node* cur = tail;
            cout << "\n-Reversed-\n";
                while(cur != nullptr){
                    cout <<  cur->data << "\n";
                    cur = cur->prev;
                }
            }
        
};


int main(){
    DoublyLinkedList* ll;
    ll= new DoublyLinkedList();

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
    ll->displayListReverse();
}   

