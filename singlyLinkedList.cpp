#include <iostream>

using namespace std;

class LinkedList {
  private:
      class Node{
        public:
          int data;
          Node * next;

        Node (int d) {
          data = d;
          next = nullptr;
        }
      };
    Node * head;

    public: 

      LinkedList() {
        head = nullptr;
      }

    void append (int d);
    void addend(int d);
    void display();
    int count();
    void erase(int d);


    ~LinkedList(){
      Node * temp = head;
      while (temp != nullptr) {
        Node * nextNode = temp -> next;
        delete temp;
        temp = nextNode;
      }
    }
};

int main() {

  LinkedList list;
  list.append(10);
  list.append(20);
  list.append(30);
  list.addend(05);
  list.display();
  cout << list.count() << endl;

  cout << "After erasure" << endl;

  list.erase(5);
  list.display();
  cout << list.count() << endl;
  return 0;
}

void LinkedList::append(int d) {
  Node * temp = head;

  if (head == nullptr) {
    head = new Node(d);
  }

  else 
  {
    while (temp -> next  != nullptr) {
      temp = temp -> next;
    }
    temp -> next = new Node(d);
  }   

        return;
}
void LinkedList::display() {
  Node * temp = head;

  if (temp == nullptr) {
    cout << "List is empty" << endl;
  }

  else {
    while (temp != nullptr) {

      cout << temp -> data;
      if (temp -> next != nullptr) {
        cout << "->" ;
      }
      temp = temp -> next;
      
    }
    
  }

   cout << endl;
  delete temp;
   return;
  

}

int LinkedList::count() {

  int counter = 0;
  if (head == nullptr) {
    return 0;
  }
  else {
    Node * temp = head;
    while (temp != nullptr){
      counter ++;
      temp = temp -> next;
    }

  }
  return counter;
}

void LinkedList::addend(int d) {
  Node * newNode = new Node(d);
  newNode -> next = head;
  head = newNode;
}

void LinkedList::erase(int d) {
  if (head == nullptr) { // if list is empty
    return; // end function
  }
  
    if (head -> data == d) { // if the head node contains the target
      Node * temp = head;
      head = temp -> next; // move head forward
      delete temp; // delete the target
      return; // end function
    }

    Node * temp = head;
    while (temp != nullptr && temp -> next -> data != d) {
      temp = temp -> next; // traverse the list
    }
    
    if (temp -> next != nullptr ) { // if target value is in the middle
      Node * target = temp -> next;
      temp -> next = target -> next;
      delete target;
    }
    
  
}



