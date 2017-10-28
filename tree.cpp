#include "tree.h"
#include <stdio.h>
#include <QDebug>
#include <math.h>

Tree::Tree()
{
    treeSize = 0;
    root = NULL;
}

Tree::Tree(const Tree &a)
{
    treeSize = 0;
    root = NULL;
    Node* temp = a.root;
    while(temp->left&&!temp->left->isLeaf) temp = temp->left;
    while(temp&&!temp->isLeaf)
    {
        keyInsert(temp->data);
        temp = nextNode(temp);
    }
}

EnergeticVolume Tree::closestByVolume(float vol)
{
    return recursive(vol, root);
}

EnergeticVolume Tree::recursive(float vol, Node *_root)
{
    if(!_root->isLeaf)
    {
        float min = abs(_root->key-vol);
        if(abs(vol-_root->left->key)<min||abs(vol-_root->right->key)<min)
        {
            if(abs(vol-_root->left->key)<abs(vol-_root->right->key))
                return recursive(vol, _root->left);
            else
                return recursive(vol, _root->right);
        }
        else
        {
            Node *leftRoot = _root->left;
            Node *rightRoot = _root->right;
            while(!leftRoot->isLeaf&&!leftRoot->right->isLeaf) leftRoot = leftRoot->right;
            while(!rightRoot->isLeaf&&!rightRoot->left->isLeaf) rightRoot = rightRoot->left;
            if(!rightRoot->isLeaf&&!leftRoot->isLeaf)
            {
                if(min<abs(leftRoot->key-vol)&&min<abs(rightRoot->key-vol)) return _root->data;
                else if(abs(leftRoot->key-vol)<min&&abs(leftRoot->key-vol)<abs(rightRoot->key-vol)) return leftRoot->data;
                else return rightRoot->data;
            }
            else
            {
                if(!rightRoot->isLeaf||!leftRoot->isLeaf)
                {
                    Node* currentRoot = rightRoot->isLeaf ? leftRoot : rightRoot;
                    if(abs(currentRoot->key-vol)<min) return currentRoot->data;
                    else return _root->data;
                }
                else
                {
                    return _root->data;
                }
            }
        }
    }
}

void Tree::save(QString file_name)
{
    Node* temp = root;
    QFile file;
    file.setFileName(file_name);
    file.open(QIODevice::WriteOnly);
    QDataStream stream (&file);
    while(!temp->left->isLeaf)
    {
        temp=temp->left;
    }
    while(temp)
    {
        stream<<temp->data.getName()
             <<QString::number(temp->data.getWeight())
             <<QString::number(temp->data.getFat())
             <<QString::number(temp->data.getProteins())
             <<QString::number(temp->data.getCarbonhydrates())
             <<QString::number(temp->data.getAcids())
             <<QString::number(temp->data.getFfibers());
        temp=nextNode(temp);
    }
    file.close();
}

void Tree::load(QString file_name)
{
    QFile file;
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    while(!file.atEnd())
    {
        QString _name;
        QString _weight;
        QString _fat;
        QString _proteins;
        QString _carbonhydrates;
        QString _acids;
        QString _ffibers;
        stream>>_name>>_weight>>_fat>>_proteins>>_carbonhydrates>>_acids>>_ffibers;
        EnergeticVolume temp (_name, _weight,
                              _fat, _proteins,
                              _carbonhydrates,
                              _acids, _ffibers);
        keyInsert(temp);
    }
    file.close();
}

void Tree::keyDelete(float _key)
{
    Node* n =NULL;
    n = nodeSearch(root, _key);
    if(n)
    {
        Node* temp;
        if(!n->right->isLeaf)
        {
            temp = n->right;
            while(!temp->left->isLeaf) temp=temp->left;
            n->data = temp->data;
            n->key = temp->key;
        }
        else if(!n->left->isLeaf)
            {
                temp = n->left;
                while(!temp->right->isLeaf) temp = temp->right;
                n->data = temp->data;
                n->key = temp->key;
            }
            else temp = n;
        Node* child = temp->right->isLeaf ? temp->left : temp->right;
        child->parent = temp->parent;
        if(temp->parent)
        {
            if(temp->parent->left == temp) temp->parent->left = child;
            else temp->parent->right = child;
        }
        temp->parent =NULL;
        if (temp->red == 0)
        {
            if (child->red ==1)
                child->red = 0;
            else
                firstDelete(child);
        }
        root = child;
        while(root->parent) root = root->parent;
        treeSize-=1;
        delete temp;
    }
}

Node* Tree::nodeSearch(Node *_root, float _key)
{
    if(_root&&!_root->isLeaf)
    {
        if(_root->key==_key)
        {
            return _root;
        }
        else
        {
            if(_root->key>_key) return nodeSearch(_root->left, _key);
            else return nodeSearch(_root->right, _key);
            return NULL;
        }
    }
    else return NULL;
}

void Tree::show()
{
    showNode(root);
}

void Tree::showNode(Node *_root)
{
    if(_root == 0) _root = root;
    if(_root)
    {
        if(!_root->isLeaf){
        showNode(_root->left);
        _root->data.show();
        showNode(_root->right);
        }
    }
}

EnergeticVolume Tree::keySearch(float _key)
{
    Node *res = NULL;
    res = nodeSearch(root, _key);
    if(res) return res->data;
}

int Tree::size()
{
    return treeSize;
}

bool Tree::isEmpty()
{
    if(root) return false;
    else return true;
}

Node* Tree::nextNode(Node *n)
{
    Node* next = n;
    if(!n->right->isLeaf)
    {
        next = next->right;
        while(!next->left->isLeaf) next = next->left;
        return next;
    }
    else if(n->parent&&n->parent->left==n) return next->parent;
    else if(n->parent&&n->parent->parent&&n->parent->parent->left==n->parent) return next->parent->parent;
    else return NULL;
}

void Tree::firstDelete(Node* n)
{
    if(n->parent)
    {
        secondDelete(n);
    }
}

void Tree::secondDelete(Node* n)
{
    Node *s = n->sibling();
    if(s->red==1)
    {
        n->parent->red = 1;
        s->red = 0;
        if(n == n->parent->left)
        {
            rotateLeft(n->parent);
        }
        else
        {
            rotateRight(n->parent);
        }
    }

    thirdDelete(n);
}

void Tree::thirdDelete(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==0&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        firstDelete(n->parent);
    }
    else forthDelete(n);
}

void Tree::forthDelete(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==1&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        n->parent->red=0;
    }
    else fifthDelete(n);
}

void Tree::fifthDelete(Node* n)
{
    Node *s = n->sibling();

        if  (s->red==0) {
            if ((n == n->parent->left) &&
                (s->right->red==0) &&
                (s->left->red==1)) {
                s->red==1;
                s->left->red==0;
                rotateRight(s);
            } else if ((n == n->parent->right) &&
                       (s->left->red==0) &&
                       (s->right->red==1)) {
                s->red==1;
                s->right->red == 0;
                rotateLeft(s);
            }
        }
        sixDelete(n);
}

void Tree::sixDelete(Node* n)
{
    Node *s = n->sibling();

        s->red = n->parent->red;
        n->parent->red=0;

        if (n == n->parent->left) {
            s->right->red=0;
            rotateLeft(n->parent);
        } else {
            s->left->red=0;
            rotateRight(n->parent);
        }
}

void Tree::keyInsert(EnergeticVolume _data)
{
    Node* nex = nodeSearch(root, _data.countVolume());
    if(!nex)
    {
        Node* temp = new Node;
        temp->data=_data;
        temp->key = _data.countVolume();
        if(!root) root = temp , firstInsert(root);
        else
        {
            Node* r = root;
            bool f = true;
            while(!(r->left->isLeaf&&r->right->isLeaf)&&f)
            {
                if(r->key>temp->key)
                {
                    if(!r->left->isLeaf)
                        r=r->left;
                    else
                        f = false;
                }
                else
                {
                    if(!r->right->isLeaf)
                        r=r->right;
                    else f = false;
                }
            }
            temp->parent=r;
            if(temp->key>r->key) r->right = temp;
            else r->left = temp;
            firstInsert(temp);
        }
        while(root->parent) root = root->parent;
        treeSize+=1;
    }
}

void Tree::firstInsert(Node* n)
{
    if(n->parent == NULL)
    {
        n->red=0;
    }
    else secondInsert(n);
}

void Tree::secondInsert(Node* n)
{
    if(n->parent->red == 1 )
    {
        thirdInsert(n);
    }
}

void Tree::thirdInsert(Node* n)
{
    Node *u = n->uncle(), *g = n->grandparent();
    if(u&&u->red==1)
    {
        n->parent->red = 0;
        u->red = 0;
        g->red = 1;
        firstInsert(g);
    }
    else
    {
        forthInsert(n);
    }
}

void Tree::forthInsert(Node* n)
{
    Node *g = n->grandparent();
    if(n == n->parent->right && n->parent==g->left)
    {
        rotateLeft(n->parent);
        n = n->left;
    }
    else if(n == n->parent->left && n->parent==g->right)
    {
        rotateRight(n->parent);
        n = n->right;
    }
    fifthInsert(n);
}

void Tree::fifthInsert(Node* n)
{
    Node *g = n->grandparent();
    n->parent->red = 0;
    g->red = 1;
    if(n==n->parent->left&&n->parent == g->left)
    {
        rotateRight(g);
    }
    else
    {
        rotateLeft(g);
    }
}

void Tree::rotateRight(Node* n)
{
    Node* pivot = n->left;
    pivot->parent = n->parent;
    if(n->parent)
    {
        if(n->parent->left == n)
        {
            n->parent->left = pivot;
        }
        else
        {
            n->parent->right = pivot;
        }
    }
    n->left = pivot->right;
    if(pivot->right)
    {
        pivot->right->parent = n;
    }
    n->parent = pivot;
    pivot->right = n;
}

void Tree::rotateLeft(Node* n)
{
    Node* pivot = n->right;
    pivot->parent = n->parent;
    if(n->parent)
    {
        if(n->parent->left == n)
        {
            n->parent->left = pivot;
        }
        else
        {
            n->parent->right = pivot;
        }
    }
    n->right = pivot->left;
    if(pivot->left)
    {
        pivot->left->parent = n;
    }
    n->parent = pivot;
    pivot->left = n;
}
