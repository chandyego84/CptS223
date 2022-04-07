#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <unordered_map>

using namespace std;

/*
- Should work for both string and integer elements 
- Disjoint sets consist of tree node structures that store the element, 
a pointer to their parent node, and an integer rank
- Nodes with a null parent pointer are the roots of the disjoint set trees
- All of the nodes are stored in a C++ STL unordered_map, whcih maps the element to 
a pointer to its node
*/
template <typename T>
class DisjointSet {
    private:
        struct node {
            T element;
            node* parent;
            int rank;
        };

        unordered_map<T, node*> nodes_map;

    public:
        DisjointSet();
        ~DisjointSet();

        void insert(T x);

        void unionSets(T x, T y);

        T find(T x);

        void print();
};

/*Constructor*/
template <typename T>
DisjointSet<T>::DisjointSet() {
    // Nothing to do here
};

/*Destructor:
- deletes all the nodes stored in the disjoint sets
- clears unordered_map
*/
template <typename T>
DisjointSet<T>::~DisjointSet() {
    for (auto it = nodes_map.begin(); it != nodes_map.end(); ++it) {
        delete it->second;
    }

    nodes_map.clear();
};

/*Insert:
- creates a new disjoint set tree with only one node whose element is x,
- parent pointer is null
- rank is 0
- node is added to the map (e.g., map[x] = pointer to node)
*/
template <typename T>
void DisjointSet<T>::insert(T x) {
    node* new_node = new node;
    new_node->element = x;
    new_node-> parent = nullptr;
    new_node->rank = 0;
    nodes_map[x] = new_node; 
};

/*UnionSets:
- Performs union-by-rank
- Should not assume that x and y are roots
- Should perform a find(x) and find(y) on the two given elements to retrieve representative root nodes
*/
template <typename T>
void DisjointSet<T>::unionSets(T x, T y) {
    T x_root = find(x);
    T y_root = find(y);

    if (x_root == y_root) {
        // same set
        return;
    }

    else if (nodes_map[y_root]->rank > nodes_map[x_root]->rank) {
        // y root is deeper
        nodes_map[x_root]->parent = nodes_map[y_root]; // make y root the new root of both
    }

    else {
        if (nodes_map[x_root]->rank == nodes_map[y_root]->rank) {
            // same depth
            nodes_map[x_root]->rank++; // update height if same depth
        }
        nodes_map[y_root]->parent = nodes_map[x_root]; // make x root the new root of both
    }
};

/*Find:
- Starts by looking up x's node using the unordered_map
- Follows the parent pointers to find representative root node
- Returns the element of the root node
- Performs path compression by changing root pointers rather than array indices
*/
template <typename T>
T DisjointSet<T>::find(T x) {
    if (nodes_map[x]->parent == nullptr) {
        // reached parent node
        return x;
    }
    else {
        // find parent node
        T parent_element = find(nodes_map[x]->parent->element);
        // change parent pointer to point to parent node (path compression)
        nodes_map[x]->parent = nodes_map[parent_element];
        
        return parent_element;
    }
};

/*Print:
- Iterates through the unordered_map printing each element, its rank, and its parent (or NULL if 
parent pointer is null)
*/
template <typename T> 
void DisjointSet<T>::print() {
    for (auto it = nodes_map.begin(); it != nodes_map.end(); ++it) {
        cout << it->first << " (" << it->second->rank << ") -> ";
        if (it->second->parent != nullptr) {
            cout << it->second->parent->element;
        }
        else {
            cout << "NULL";
        }
        cout << endl;
    }
};

#endif