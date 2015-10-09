/*
 * Name: Put your name(s) here
 */
#ifndef GVSU_CS263_SINGLE_LINKED_LIST
#define GVSU_CS263_SINGLE_LINKED_LIST

#include <iostream>

using namespace std;

/* The following single_linked_list class shall be implemented WITHOUT
 * using any of the C++ data structures (std::vector, std::list, std::map,
 * ...)
 *
 * This assignment is primarily a reinforcement of writing recursive
 * functions to manipulate a recursive data structure.
 */

template<typename E>
class single_linked_list {
private:
    /* a struct is a class whose members are all public */
    struct Node;

    Node *head;
public:
    /* the following public functions are NOT RECURSIVE, but they will
     * invoke the recursive counterpart */

    /* Complete each of the following public function */

    /* constructor */
    single_linked_list() {
        head = nullptr;
    }

    /* destructor */
    ~single_linked_list() {
        /* call a RECURSIVE private function for removing
         * all the nodes
         */
        _destructor(head);
    }

    unsigned long size() const {
        return _size(head);
    }

    void print(ostream &destination) const {
        /* start printing recursively from the head pointer */
        /* TODO: add a line that calls the recursive function */
        _print(head, destination);
    }

    bool is_contained(const E &x) const {
        return _is_contained(head, x);
    }

    void addItem(const E &x) {
        /* TODO: complete this method by calling your recursive PRIVATE function
         */
        _addItem(head, x);
    }

    void remove(const E &x) {
        /* TODO: complete this method by calling your recursive PRIVATE function
         */
        _remove(head, x);
    }

    void print_reverse(ostream &destination) {
        /* TODO: Question 3.29 complete this method by using a NON-RECURSIVE
         * technique
         */
    }

private:
    /* the following private functions are RECURSIVE */
    unsigned long _size(Node *from) const {
        if (from != nullptr) {
            int size_after_me = _size(from->next);
            return 1 + size_after_me;
        }
        else
            return 0;
    }

    void _print(Node *from, ostream &out) const {
        if (from != nullptr) {
            out << from->data << " ";
            _print(from->next, out);
        }
    }

    bool _is_contained(Node *from, const E &val) const {
        if (from != nullptr) {
            if (from->data == val) {
                return true;
            }
            else {
                _is_contained(from->next, val);
            }
        }
        return false;
    }

    void _addItem(Node *from, const E &newVal) {

        Node *temp = new Node();
        temp->data = newVal;

        Node *&temp2 = head;
        if (temp2 != nullptr) {
            if (temp2->next == nullptr) {
                temp2->next = temp;
                return;
            }
            _addItem(temp2->next, newVal);
        }
        else {
            temp2 = temp;
            return;
        }


//        Node *temp = new Node();
//        temp->data = newVal;
//        if(from->next == nullptr) {
//            from = temp;
//            return;
//        }
////        if(from->next == nullptr) {
////            from->next = temp;
////            return;
////        }
//        _addItem(from->next, newVal);
//        delete temp;
    }

    void _remove(Node *from, const E &val) {
        if (from == nullptr) {
            return;
        }
//        if(from->next == nullptr){
//            return;
//        }
        if (from->next->data == val) {
            Node *temp = head->next->next;
            cout << from->next->data << endl;
            delete from->next;
            from->next = temp;
            return;
        }
        _remove(head->next, val);

    }

    void _destructor(Node *from) {
//        Node *temp = from;
//        if (head == nullptr) {
//            return;
//        }
//        else {
//            from = from->next;
//            _destructor(from);
//            delete temp;
//        }
    }

    /* TODO Add more private recursive functions here */

};

#include "gvsu_node.hpp"

#endif
