#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    string word;
    Node *next = NULL;
};


void insert(Node *head, string word){

    Node *currentNode = head;
    // cout << "Data "<< currentNode->word << "Next: " << currentNode->next;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    Node *newNode = new Node;
    newNode->word = word;
    currentNode->next = newNode;


}
void displayList (Node* head){
    
    Node* node = head;
    while(node){
        cout << "Word-> "<< node->word << " <-";
        node = node->next;
    }
}

// void deleteAt(){
// }

int main (){

    Node *head = NULL;
    string word;

    for (int i = 0;i<10 ;i++){
        // getline(cin, word);
        cout << "\nEnter Word: ";
        cin >> word;
        
        if(word == "-1"){
            break;
        }
        if (head){
            
            insert(head,word);
        }else{
            
            head = new Node;
            head->word = word;
            // insert(head,word);
        }
        
    }
    displayList(head);
    
    // insertFirst(node);
    // cout<< node->word << "\n";
    // delete node;
}

