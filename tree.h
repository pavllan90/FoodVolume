#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "energeticvolume.h"
#include <QFile>
#include <cstddef>

class Tree
{
public:
    Tree();
    Tree(const Tree &a);
    Node* getRoot();
    Tree find(QString s_name);
    void show(Node *_root = 0);
    int size();
    bool isEmpty();
    void keyDelete(int _key);
    Node *keySearch(Node* _root, int _key);
    void keyInsert(int _key, EnergeticVolume _data);
    void save(QString file_name);
    void load(QString file_name);
    Tree closest(float vol);
private:
    Node* root;
    void rotate_left(Node* n);
    void rotate_right(Node* n);
    void deleteOne(Node *n);
    void del1(Node *n);
    void del2(Node *n);
    void del3(Node *n);
    void del4(Node *n);
    void del5(Node *n);
    void del6(Node *n);
    void ins1(Node* n);
    void ins2(Node* n);
    void ins3(Node* n);
    void ins4(Node* n);
    void ins5(Node* n);
    void insert(EnergeticVolume a, int _key);
    Node* getNext(Node* n);
    int tree_size;
    void minimum(float vol, int *min, Node* _root);
    void recursive(int min, float vol, Tree *result, Node* _root);
};

#endif // TREE_H
