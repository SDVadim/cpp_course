#include <iostream>

class List {
  public:

    struct Node {
      int value;
      Node* next_node;
    };

    bool empty() {
      return first_node == nullptr;
    }

    void show() {
      Node* current_node = first_node;
      while (current_node) {
        std::cout << current_node->value << " -> ";
        current_node = current_node->next_node;
      }
      std::cout << "null\n";
    }

    void push_front(int a) {
        Node* new_node = new Node{a, first_node};
        first_node = new_node;
        if (last_node == nullptr) {
            last_node = new_node;
        }
    }

    void push_back(int a) {
      Node* new_node = new Node{a, nullptr};
      if (last_node == nullptr) {
        last_node = new_node;
        first_node = new_node;
        return;
      }
      last_node->next_node = new_node;
      last_node = new_node;
    }

    int pop_first() {
      if (empty()) {
        std::cout << "В списке нету элементов \n";
        return 0;
      }
      Node* old_first_node = first_node;
      first_node = first_node->next_node;
      int value = old_first_node->value;
      delete old_first_node;
      return value;
    }

    int getMid() {
      Node* fl1 = first_node;
      Node* fl2 = first_node;
      while (fl2->next_node) {
        fl2 = fl2->next_node;
        if(fl2->next_node) {
          fl2 = fl2->next_node;
        }
        fl1 = fl1->next_node;
      }
      return fl1->value;
    }

    int pop_last() {
      if (empty()) {
        std::cout << "В списке нету элементов \n";
        return 0;
      }
      Node* old_last_node = last_node;
      Node* current_node = first_node;
      if (current_node == last_node) {
        int value = current_node->value;
        delete current_node;
        first_node = nullptr;
        last_node = nullptr;
        return value;
      }
      while (current_node->next_node != last_node) {
        current_node = current_node->next_node;
      }
      int value = last_node->value;
      current_node->next_node = nullptr;
      last_node = current_node;
      delete old_last_node;
      return value;
    }


  public:
    Node* first_node = nullptr;
    Node* last_node = nullptr;
};

int main() {
  List list = List();
  list.push_front(10);
  list.push_front(11);
  list.push_back(12);
  std::cout << list.getMid() << '\n';
  list.pop_first();
  list.pop_last();
  list.show();
  std::cout << list.empty();
}