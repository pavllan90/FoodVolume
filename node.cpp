#include "node.h"

using namespace std;

Node::Node()
{
    parent = NULL;
    left = new Node(this);
    right = new Node (this);
    isLeaf = false;
    red = 1;
    key = 0.1;
}

Node::Node(Node *a)
{
    parent = a;
    left = right = NULL;
    red = 0;
    isLeaf = true;
    key = 0.1;
}

Node* Node::grandparent()
{
    if(this&&this->parent)
    {
        return this->parent->parent;
    }
    else return NULL;
}

Node* Node::uncle()
{
    Node* g;
    if(g = this->grandparent())
    {
        if(this->parent==g->left) return g->right;
        else return g->left;
    }
    else return NULL;
}

Node* Node::sibling()
{
    if(this->parent->left==this) return this->parent->right;
    else return this->parent->left;
}
