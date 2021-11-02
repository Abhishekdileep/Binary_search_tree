#ifndef BST_H
#define BST_H
#include <iostream>
template<typename t >
class node_t{
    public : 
        t val;
        node_t *left ; 
        node_t *right ;
};
template <typename t >
class BST
{
    private :     
    node_t<t>* head ;
    public :
    //Canonical Form 
    BST();
    /*
        Empty constructor that shall create head with value 0;
    */
    BST(t val);
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
    void insert_node(t key);
    /*
        Insert a node to the left or right of the closest node according to the key ; 
    */
    int delete_node(t key);
    int delete_node__(t key  ,node_t<t>*pntr_head);
    node_t<t>* succession__( node_t<t>*pntr_head);
    /*
        delete the node and put the closest successor to that value ! 
        If node not found return -1;

        Succesion will be choosing the next largest value to the key 
        value that is being deleted 
    */
    node_t<t>* search_node(t key);
    /*
        search the node to find the key , return NULL if the value isn't found 
    */
    node_t<t>* floor(t key);
    /*
        search and find the closest node to the key given 
    */
};
#include "BST.hxx"
#endif