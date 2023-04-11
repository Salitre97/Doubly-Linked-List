#include "Dlinked_list.h"

template <typename T>
Node<T>::Node(){ 
    cout << "Node Constructor called!" << endl;
}
template <typename T>
Node<T>::~Node(){
    cout << "Node Destructor Called" << endl;
}

// DoublyLinkedList Class
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //cout << "Dll Destructor Called" << endl;
    
    Node<T>* temp = head;
    while(head != nullptr){

        head = head->next;
        delete temp;
        temp = head;
    }

}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& rhs){
    //cout << "Copy Constructor Called!" << endl;
    head = nullptr;
    tail = nullptr;
        for(int i = 0; i < rhs.size(); i++){
        
            int variable = rhs.at(i);
            push_back(variable);
            
        }
}

template <typename T>
void DoublyLinkedList<T>::operator =(const DoublyLinkedList& rhs){
    // free the original list
        while(head != nullptr){
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
        tail = nullptr;
        // copy rhs list
        for(int i = 0; i < rhs.size(); i++ ){
            push_back(rhs.at(i));
            //cout << "here" << endl;
        }
    
    }

template <typename T>     
void DoublyLinkedList<T>::push_back(T data){
    if(head == nullptr){
        head = new Node<T>;
        head->data = data;
        head->next = nullptr;
        head->previous = nullptr;
        head = head;
        tail = head;
        return;
    }
    
    Node<T>* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    currentNode->next = new Node<T>;
    (currentNode->next)->next = nullptr;
    (currentNode->next)->data = data;
    currentNode->next->previous = currentNode;
    tail = currentNode->next;
    
}

template <typename T>
T& DoublyLinkedList<T>::at(T index) const{
    Node<T>* currentNode = head;
    int i = 0;
    while(i < index){
        currentNode = currentNode->next;
        i++;
    }
    
    return currentNode->data;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int index){
    
    if(index == 0){
        Node<T>* temp = head;
        head = new Node<T>;
        head->data = data;
        head->next = temp;
        head->previous = nullptr;
        return;
    }
    
    Node<T>* currentNode = head;
    int i = 0;
    while(i < index - 1){
        currentNode = currentNode->next;
        i++;
    }
    
    Node<T>* temp = currentNode->next;
    currentNode->next = new Node<T>;
    currentNode->next->data = data;
    currentNode->next->next = temp;
    currentNode->next->previous = temp->previous;
}

template <typename T>
void DoublyLinkedList<T>::remove(T index){
    if(index == 0){
        Node<T>* temp = head->next;
        delete head;
        temp->previous = nullptr;
        head = temp;
        //cout << head->data << endl;
        return;
    }
    
    Node<T>* currentNode = head;
    int i = 0;
    while(i < index - 1){
        currentNode = currentNode->next;
        i++;
    }
    
    Node<T>* temp = currentNode->next->next;
    temp->previous = currentNode;
    delete currentNode->next;
    currentNode->next = temp;
}

template <typename T>
void DoublyLinkedList<T>::pop_back(){
    Node<T>* currentNode = head;
    
    // No elements in list
    if(head == nullptr){
        return;
    }
    
    // 1 element in list
    if(currentNode->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    
    while(currentNode->next->next != nullptr){
        currentNode = currentNode->next;
    }
    
    delete currentNode->next;
    currentNode->next = nullptr;
}
template <typename T>
int DoublyLinkedList<T>::size() const{
    Node<T>* currentNode = head;
    int size = 0;
    
    if(currentNode == nullptr){
        return size;
    }

    while(currentNode != nullptr){
        currentNode = currentNode->next;
        size++;
    } 
    
    return size;
}

template <typename T>
void DoublyLinkedList<T>::print(){
    Node<T>* currentNode = head;
    
    if(currentNode == nullptr){
        return;
    }
    int i = 0;
    while(currentNode != nullptr){
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
        i++;
    }
}

template <typename T>
void DoublyLinkedList<T>::reverse_print(){
    Node<T>* currentNode = head;
    
    //cout << "Foward Print: " << endl;
    while(currentNode != nullptr){
        //cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
    
    currentNode = tail;
    
    cout << "Reverse Print:" << endl;
    while(currentNode != nullptr){
        cout << currentNode->data << endl;
        currentNode = currentNode->previous;
        
    }
}

void int_test(){
    DoublyLinkedList<int> dll;
    
    dll.push_back(1); 
    dll.push_back(2);
    dll.push_back(3);
    
    DoublyLinkedList<int> dllCopy = dll; // 1, 2, 3
    cout << "Copy: " << endl;
    dllCopy.print();
    dllCopy.push_back(4); // 1, 2, 3, 4
    dllCopy.remove(0); // 1, 3, 4
    dllCopy.remove(0);  // 3, 4
    dllCopy.insert(5, 1); // 3, 5, 4
    
    cout << "updated copy:" << endl;
    dllCopy.print();
    
    cout << "Original:" << endl;
    dll.print(); // 1, 2, 3
    
    cout << "Copy:" << endl;
    dllCopy.print(); //1, 3, 4
    
    cout << "original = Copy " << endl;
    cout << "original:" << endl;
    dll = dllCopy;
    
    dll.print(); // 1, 3, 4
    
    dll.reverse_print();
}
/*
void char_test(){
    DoublyLinkedList<string> dll;
    
    dll.push_back("'B"); 
    dll.push_back("C");
    dll.push_back("D");
    
    DoublyLinkedList<string> dllCopy = dll; // B, C, D
    cout << "Copy: " << endl;
    dllCopy.print();
    dllCopy.push_back("E"); // B, C, D, E
    dllCopy.remove(0); // C, D, E
    dllCopy.remove(0);  // D, E
    dllCopy.insert("A", 1); // D, A, E
    
    cout << "updated copy:" << endl;
    dllCopy.print();
    
    cout << "Original:" << endl;
    dll.print(); // B, C, D
    
    cout << "Copy:" << endl;
    dllCopy.print(); //D, A, E
    
    cout << "original = Copy " << endl;
    cout << "original:" << endl;
    dll = dllCopy;
    
    dll.print(); // D, A, E
    
    dll.reverse_print();
}
*/

