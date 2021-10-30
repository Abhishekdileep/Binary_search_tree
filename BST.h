#ifndef BST_H
#define BST_H
#include <iostream>
template <typename t , size_t N >
struct node_t{
    t val;
    node *left ; 
    node *right ;
};
// typedef struct node node_t;
template <typename t , size_t N>
class BST
{
    private : 
        node_t* head ;
    public :
    //Canonical Form 
    BST();
    /*
        Empty constructor that shall create head with value 0;
    */
    BST(int val);
    /*
        parameterized constructor that shall create head with the value val
    */
    BST(const BST &other );
    /*
        copy constructor : implementation need to be deep copy or shallow copy ? 
    */
    ~BST();
    /*
        Deallocate all the dynamic memory created in the tree 
    */

    //Interface - DS
    void insert_node(int key);
    /*
        Insert a node to the left or right of the closest node according to the key ; 
    */
    int delete_node(int key);
    /*
        delete the node and put the closest successor to that value ! 
        If node not found return -1;
    */
    node_t* search_node(int key);
    /*
        search the node to find the key , return NULL if the value isn't found 
    */
    node_t* floor(int key);
    /*
        search and find the closest node to the key given 
    */
};

#endif