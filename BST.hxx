#include <iostream>
#include <stdio.h>
#include "BST.h"
 
template <typename t >
BST<t>::BST()
:head(nullptr)
{}
 
template <typename t >
BST<t>::BST(t val)
:head( (node_t<t> *)malloc(sizeof(node_t<t>)) )
{
    this->head->left = nullptr;
    this->head->right = nullptr;
    this->head->val = val;
}
 
template <typename t >
BST<t>::~BST()
{
    delete this->head;
}
 
template <typename t > 
void BST<t>::insert_node(t key)
{
    node_t<t>* temp = head ;
    node_t<t>* prev = head ;
    while( temp != nullptr )
    {
        if( temp->val < key)
        {
            std::cout<<"right ";
            prev = temp;
            temp =  temp->right;
         
        }
        else if( temp->val > key )
        {
            std::cout<<"left ";
            prev =temp;
            temp =  temp->left;
        }
    }
    temp = (node_t<t> *)malloc(sizeof(node_t<t>) ) ;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->val = key;
    if( prev->val < key )
    {
         prev->right = temp ; 
    }
    else
    {
        prev->left = temp;
    }
}




template <typename t > 
int BST<t>::delete_node(t key)
{
    return delete_node__( key , this->head );
}

template <typename t>
int BST<t>::delete_node__(t key , node_t<t> *pntr_head)
{
    if(pntr_head->val == key )
    {
       node_t<t>* temp = succession__( pntr_head->right );
        if(pntr_head != temp ){
           pntr_head->val = temp->val;
        }
        delete temp;
        return 0 ; 
    }
    else if(pntr_head->val < key )
    {
        delete_node__( key , pntr_head->left);
    }
    else 
    {
        if(pntr_head == nullptr)
            return -1;
        delete_node__(key , pntr_head->right);
    }
}

template <typename t > 
node_t<t>* BST<t>::succession__( node_t<t>*pntr_head)
{
    if( pntr_head->right != nullptr && pntr_head->left != nullptr )
        return pntr_head;
    else 
        return succession__(pntr_head->left);
}