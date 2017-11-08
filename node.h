#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "volume.h"
#include <iostream>
class Node
{
public:
    Node();
    Node(Node *a);
    Volume *data;
    float key;
    Node *parent, *left, *right;
    bool red;
    bool isLeaf;
    Node* grandparent();
    Node* uncle();
    Node* sibling();
};

#endif // NODE_H
