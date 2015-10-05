//
//  gvsu_alloc.hpp
//  CS263-HW3
//
//  Created by Hans Dulimarta (Fall 2014)
//

#ifndef CS263_gvsu_alloc_hpp
#define CS263_gvsu_alloc_hpp

#include <iostream>
#include <map>




template<class T>
class GVSU_Allocator {
private:
    static int alloc_count, dealloc_count;
    static std::map<T*,unsigned long> alloc_map;

public:

    /* Handle memory allocation, keep track of memory address and size
       in a map */
    static T* allocate(size_t num, const void* hint = 0) {
        alloc_count++;
        /* determine the required number of bytes */
        unsigned long size = num * sizeof(T);
        
        /* use the "global" new to allocate the storage */
        T* address = static_cast<T*>(::operator new(size));
        
        /* record this request in the map */
        alloc_map[address] = size;
        return address;
    }
    
    /* handle memory deallocation */
    static void deallocate (T* ptr) {
        dealloc_count++;
        
        /* remove the record from the map */
        alloc_map.erase(ptr);
        
        /* use the "global" delete to deallocate */
        ::operator delete(ptr);
    }

    static void report (const string& tname, ostream& out) {
        out << "Allocation summary of " << tname << " data" << endl;
        out << "Allocation count " << alloc_count << endl;
        out << "Deallocation count " << dealloc_count << endl;
        int bytes = 0;
        
        /* Print unallocated memory segments */
        for (auto it = alloc_map.begin(); it != alloc_map.end(); ++it) {
            out << dec << setw(5) << it->second << " bytes at " << hex << it->first << endl;
            bytes += it->second;
        }
        out << "Total amount of memory leak " << dec << bytes << " bytes" << endl;
    }
    
    static pair<int,int> allocation_status() {
        return make_pair(alloc_count, dealloc_count);
    }
};

template <typename E>
int GVSU_Allocator<E>::alloc_count = 0;

template<typename E>
int GVSU_Allocator<E>::dealloc_count = 0;

template <typename E>
map<E*,unsigned long> GVSU_Allocator<E>::alloc_map;

#endif
