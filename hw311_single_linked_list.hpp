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
        for(int i = _size(head); i > 0; i--) {
            int j = 1;
            Node *temp = head;
            while(j < i) {
                if (temp->next == nullptr) {
                    break;
                }
                else {
                    temp = temp->next;
                }
                j++;
            }
            destination << temp->data << " ";
        }
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

        if (head == NULL) {
            head = new Node;
            head->data = newVal;
            head->next = NULL;
            return;
        }
        else {
            if (from->next != NULL) {
                _addItem(from->next, newVal);
            }
            else {
                from->next = new Node;
                from->next->data = newVal;
                from->next->next = NULL;
            }
        }


//        Node *temp = new Node();
//        temp->data = newVal;
//        temp->next = NULL;
//
//        Node *&temp2 = head;
//        if (temp2 != nullptr) {
//            if (temp2->next == nullptr) {
//                temp2->next = temp;
//                return;
//            }
//            _addItem(temp2->next, newVal);
//        }
//        else {
//            temp2 = temp;
//            return;
//        }


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

    void _remove(Node* &from, const E& val) {
        if (from == NULL) {
            return;
        }

        //head case
        if (from->data == val && from == head) {
            Node *temp = from;
            head = head->next;
            delete temp;
            return;
        }

        //middle case
        if (from->next && from->next->data == val) {
            Node *temp = from->next;
            from->next = temp->next;

            delete temp;
            return;
        }
        _remove(from->next, val);
    }

    void _destructor(Node *&from) {
        if (from == nullptr) {
            return;
        }
        Node *temp = from;
        from = from->next;
        delete temp;
        _destructor(from);
    }

    /* TODO Add more private recursive functions here */

    void main() {
        single_linked_list<string> names;
        vector<string> planets{"Mars", "Venus", "Uranus", "Saturn",
                               "Jupiter", "Earth"};

        for (auto p : planets) {
            names.addItem(p);
        }

        REQUIRE (names.size() == planets.size());
        for (auto p : planets) {
            REQUIRE (names.is_contained(p));
            REQUIRE_FALSE (names.is_contained("X" + p));
        }

        for (auto p : planets) {
            cout << p << endl;
            names.remove(p);
            REQUIRE_FALSE (names.is_contained(p));
        }

    }

};

#include "gvsu_node.hpp"

#endif
