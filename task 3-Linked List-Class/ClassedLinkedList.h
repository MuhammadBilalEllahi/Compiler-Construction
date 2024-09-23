#ifndef ClassedLinkedList_H
#define ClassedLinkedList_H

ClassedLinkedList {
    public: 
        ClassedLinkedList();
        void insertAtHead(string);
        void insertAtTail(string);
        virtual ~ClassedLinkedList();

    private:
        Node* head; //use this.head 
        Node* tail;
}
#endif