/*
 * Jesse Roe, Tyler Paquet, Brandon Attala
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
    /* constructor */
    single_linked_list() {
        head = nullptr;
    }

    /* destructor */
    ~single_linked_list() {
        _destructor(head);
    }

    unsigned long size() const {
        return _size(head);
    }

    void print(ostream &destination) const {
        _print(head, destination);
    }

    bool is_contained(const E &x) const {
        return _is_contained(head, x);
    }

    void addItem(const E &x) {
        _addItem(head, x);
    }

    void remove(const E &x) {
        _removeItem(head, x);
    }

    void print_reverse(ostream &destination) {
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
                return _is_contained(from->next, val);
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
    }

    void _removeItem(Node* &from, const E& val) {
        if (from == NULL) {
            delete head;
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
        _removeItem(from->next, val);
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
};

#include "gvsu_node.hpp"

#endif
