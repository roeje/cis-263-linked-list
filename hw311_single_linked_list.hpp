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

template <typename E>
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
    }

    unsigned long size() const {
        return _size(head);
    }

    void print (ostream& destination) const {
        /* start printing recursively from the head pointer */
        /* TODO: add a line that calls the recursive function */
    }

    bool is_contained (const E& x) const {
        return _is_contained (head, x);
    }

    void addItem (const E& x) {
        /* TODO: complete this method by calling your recursive PRIVATE function
         */
    }

    void remove (const E& x) {
        /* TODO: complete this method by calling your recursive PRIVATE function
         */
    }

    void print_reverse (ostream& destination) {
        /* TODO: Question 3.29 complete this method by using a NON-RECURSIVE
         * technique
         */
    }

private:
    /* the following private functions are RECURSIVE */
    unsigned long _size (Node *from) const {
        if (from != nullptr) {
            int size_after_me = _size(from->next);
            return 1 + size_after_me;
        }
        else
            return 0;
    }

    void _print (Node *from, ostream& out) const {
        if (from != nullptr) {
            out << from->data << " ";
            _print (from->next, out);
        }
    }

    bool _is_contained (Node *from, const E& val) const {
        /* TODO Complete the code here */
        return false;
    }

    /* TODO Add more private recursive functions here */

};

#include "gvsu_node.hpp"

#endif
