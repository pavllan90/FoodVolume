#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "energeticvolume.h"
#include <iostream>
class Node
{
public:
    Node();
    Node(Node *a);
    EnergeticVolume data;
    float key;
    Node *parent, *left, *right;
    bool red;
    bool isLeaf;
    Node* grandparent();
    Node* uncle();
    Node* sibling();
};

#endif // NODE_H
