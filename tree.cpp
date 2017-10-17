#include "tree.h"
#include <stdio.h>
#include <QDebug>
#include <math.h>

Tree::Tree()
{
    tree_size = 0;
    root = NULL;
}

Tree::Tree(const Tree &a)
{
    tree_size = 0;
    root = NULL;
    Node* temp = a.root;
    while(temp->left&&!temp->left->is_Leaf) temp = temp->left;
    while(temp&&!temp->is_Leaf)
    {
        keyInsert(temp->key, temp->data);
        temp = getNext(temp);
    }
}

Tree Tree::closest(float vol)
{
    Tree* result = new Tree;
    int min = root->data.countVolume();
    minimum(vol, &min, root);
    recursive(min, vol, result, root);
    return *result;

}

void Tree::minimum(float vol, int *min, Node* _root)
{
    if(!_root->is_Leaf)
    {
        if(abs(_root->data.countVolume()-vol)<*min) *min = abs(_root->data.countVolume()-vol);
        minimum(vol, min, _root->left);
        minimum(vol, min, _root->right);
    }
}

void Tree::recursive(int min, float vol, Tree *result, Node *_root)
{
    if(!_root->is_Leaf)
    {
        if(abs(_root->data.countVolume()-vol)==min) result->keyInsert(_root->key, _root->data);
        recursive(min, vol, result, _root->left);
        recursive(min, vol, result, _root->right);
    }
}

void Tree::save(QString file_name)
{
    Node* temp = root;
    QFile file;
    file.setFileName(file_name);
    file.open(QIODevice::WriteOnly);
    QDataStream stream (&file);
    while(!temp->left->is_Leaf)
    {
        temp=temp->left;
    }
    while(temp)
    {
        stream<<QString::number(temp->key)<<temp->data.getName()
             <<QString::number(temp->data.getWeight())
             <<QString::number(temp->data.getFat())
             <<QString::number(temp->data.getProteins())
             <<QString::number(temp->data.getCarbonhydrates())
             <<QString::number(temp->data.getAcids())
             <<QString::number(temp->data.getFfibers());
        temp=getNext(temp);
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
        QString _key;
        stream>>_key>>_name>>_weight>>_fat>>_proteins>>_carbonhydrates>>_acids>>_ffibers;
        EnergeticVolume temp (_name, _weight,
                              _fat, _proteins,
                              _carbonhydrates,
                              _acids, _ffibers);
        keyInsert(_key.toInt(), temp);
    }
    file.close();
}

void Tree::keyDelete(int _key)
{
    Node* delNode =NULL;
    delNode = keySearch(root, _key);
    if(delNode)deleteOne(delNode);
    else std::cout<<"No key"<<std::endl;
}

Node* Tree::keySearch(Node *_root, int _key)
{
    if(_root&&!_root->is_Leaf)
    {
        if(_root->key==_key) return _root;
        else
        {
            if(_key<_root->key) return keySearch(_root->left, _key);
            else return keySearch(_root->right, _key);
            return NULL;
        }
    }
    else return NULL;
}

void Tree::show(Node *_root)
{
    if(_root == 0) _root = root;
    if(_root)
    {
        if(!_root->is_Leaf){
        show(_root->left);
        _root->data.show();
        show(_root->right);
        }
    }
}

int Tree::size()
{
    return tree_size;
}

bool Tree::isEmpty()
{
    if(root) return false;
    else return true;
}

Node* Tree::getNext(Node *n)
{
    Node* next = n;
    if(!n->right->is_Leaf)
    {
        next = next->right;
        while(!next->left->is_Leaf) next = next->left;
        return next;
    }
    else if(n->parent->left==n) return next->parent;
    else if(n->parent->parent&&n->parent->parent->left==n->parent) return next->parent;
    else return NULL;
}

void Tree::deleteOne(Node *n)
{
    Node* temp;
    if(!n->right->is_Leaf)
    {
        temp = n->right;
        while(!temp->left->is_Leaf) temp=temp->left;
        n->data = temp->data;
        n->key = temp->key;
    }
    else if(!n->left->is_Leaf)
        {
            temp = n->left;
            while(!temp->right->is_Leaf) temp = temp->right;
            n->data = temp->data;
            n->key = temp->key;
        }
        else temp = n;
    Node* child = temp->right->is_Leaf ? temp->left : temp->right;
    child->parent = temp->parent;
    if(temp->parent)
    {
        if(temp->parent->left == temp) temp->parent->left = child;
        else temp->parent->right = child;
    }
    temp->parent =NULL;
    if (temp->red == 0) {
            if (child->red ==1)
                child->red = 0;
            else
                del1(child);
    }
    root = child;
    while(root->parent) root = root->parent;
    tree_size-=1;
    delete temp;
}

void Tree::del1(Node* n)
{
    if(n->parent)
    {
        del2(n);
    }
}

void Tree::del2(Node* n)
{
    Node *s = n->sibling();
    if(s->red==1)
    {
        n->parent->red = 1;
        s->red = 0;
        if(n == n->parent->left)
        {
            rotate_left(n->parent);
        }
        else
        {
            rotate_right(n->parent);
        }
    }

    del3(n);
}

void Tree::del3(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==0&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        del1(n->parent);
    }
    else del4(n);
}

Node* Tree::getRoot()
{
    return root;
}

void Tree::del4(Node* n)
{
    Node* s = n->sibling();
    if(n->parent->red==1&&s->red==0&&s->left->red==0&&s->right->red==0)
    {
        s->red=1;
        n->parent->red=0;
    }
    else del5(n);
}

void Tree::del5(Node* n)
{
    Node *s = n->sibling();

        if  (s->red==0) {
            if ((n == n->parent->left) &&
                (s->right->red==0) &&
                (s->left->red==1)) {
                s->red==1;
                s->left->red==0;
                rotate_right(s);
            } else if ((n == n->parent->right) &&
                       (s->left->red==0) &&
                       (s->right->red==1)) {
                s->red==1;
                s->right->red == 0;
                rotate_left(s);
            }
        }
        del6(n);
}

void Tree::del6(Node* n)
{
    Node *s = n->sibling();

        s->red = n->parent->red;
        n->parent->red=0;

        if (n == n->parent->left) {
            s->right->red=0;
            rotate_left(n->parent);
        } else {
            s->left->red=0;
            rotate_right(n->parent);
        }
}

void Tree::insert(EnergeticVolume a, int _key)
{
    Node* temp = new Node;
    temp->data=a;
    temp->key = _key;
    if(!root) root = temp ,ins1(root);
    else
    {
        Node* r = root;
        bool f = true;
        while(!(r->left->is_Leaf&&r->right->is_Leaf)&&f)
        {
            if(r->key>=temp->key)
            {
                if(!r->left->is_Leaf)
                    r=r->left;
                else
                    f = false;
            }
            else
            {
                if(!r->right->is_Leaf)
                    r=r->right;
                else f = false;
            }
        }
        temp->parent=r;
        if(temp->key>=r->key) r->right = temp;
        else r->left = temp;
        ins1(temp);
    }
    while(root->parent) root = root->parent;
    tree_size+=1;
}

void Tree::keyInsert(int _key, EnergeticVolume _data)
{
    Node* nex = keySearch(root, _key);
    if(!nex)
        insert (_data, _key);
}

void Tree::ins1(Node* n)
{
    if(n->parent == NULL)
    {
        n->red=0;
    }
    else ins2(n);
}

void Tree::ins2(Node* n)
{
    if(n->parent->red == 1 )
    {
        ins3(n);
    }
}

void Tree::ins3(Node* n)
{
    Node *u = n->uncle(), *g = n->grandparent();
    if(u&&u->red==1)
    {
        n->parent->red = 0;
        u->red = 0;
        g->red = 1;
        ins1(g);
    }
    else
    {
        ins4(n);
    }
}

void Tree::ins4(Node* n)
{
    Node *g = n->grandparent();
    if(n == n->parent->right && n->parent==g->left)
    {
        rotate_left(n->parent);
        n = n->left;
    }
    else if(n == n->parent->left && n->parent==g->right)
    {
        rotate_right(n->parent);
        n = n->right;
    }
    ins5(n);
}

void Tree::ins5(Node* n)
{
    Node *g = n->grandparent();
    n->parent->red = 0;
    g->red = 1;
    if(n==n->parent->left&&n->parent == g->left)
    {
        rotate_right(g);
    }
    else
    {
        rotate_left(g);
    }
}

void Tree::rotate_right(Node* n)
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

void Tree::rotate_left(Node* n)
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
