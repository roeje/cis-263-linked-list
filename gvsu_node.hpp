//
// Created by Hans Dulimarta on 10/4/15.
//

#include "gvsu_alloc.hpp"

template<typename E>
struct single_linked_list<E>::Node {
    E data;
    Node *next;

    void* operator new(size_t s) {
        return GVSU_Allocator<E>::allocate(s);
    }
    void operator delete(void *ptr) {
        GVSU_Allocator<E>::deallocate(static_cast<E*>(ptr));
    }
};
