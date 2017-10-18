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
    void show();
    int size();
    bool isEmpty();
    void keyDelete(QString _key);
    void keyInsert(EnergeticVolume _data);
    void save(QString file_name);
    void load(QString file_name);
    Tree closestByVolume(float vol);
    EnergeticVolume keySearch(QString _key);
private:
    Node* nodeSearch(Node* _root, QString _key);
    void showNode(Node *_root);
    void rotate_left(Node* n);
    void rotate_right(Node* n);
    void del1(Node *n);
    void ins1(Node* n);
    void del2(Node *n);
    void ins2(Node* n);
    void del3(Node *n);
    void ins3(Node* n);
    void del4(Node *n);
    void ins4(Node* n);
    void del5(Node *n);
    void ins5(Node* n);
    void del6(Node *n);
    Node* nextNode(Node* n);
    int tree_size;
    Node* root;
    void minimum(float vol, int *min, Node* _root);
    void recursive(int min, float vol, Tree *result, Node* _root);
    bool keysCompare(QString a, QString b);
};

#endif // TREE_H
