#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T> 
class Node{
  public:
  Node();
  ~Node();
  T data;
  Node* next;
  Node* previous;
};

template <typename T> 
class DoublyLinkedList{
  public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  DoublyLinkedList(const DoublyLinkedList& rhs);
  void operator =(const DoublyLinkedList& rhs);
  void push_back(T data);
  T& at(T index) const;
  void insert(T data, int index);
  void remove(T index);
  void pop_back();
  int size() const;
  void print();
  void reverse_print();
  
  private:
  Node<T>* head;
  Node<T>* tail;
};

void int_test();
void char_test();



#endif
