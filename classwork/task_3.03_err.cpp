#include <iostream>

int main() {

}

class List {
  public:
    struct Node{
      int value = 0;
      Node* next = nullptr;
    };

    void push(int value) {
      Node* new_node = new Node();
      new_node->value = value;
      new_node->next = nullptr;
      if (head) {
        head = new Node{value, nullptr};
      }
      Node* node_ptr = head;
      while (node_ptr->next) {
        node_ptr = node_ptr->next;
      }
      node_ptr->next = new_node;
    }

    void pop() {

    }

  private:
    Node* head = nullptr;


};
