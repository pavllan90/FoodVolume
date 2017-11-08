#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "energeticvolume.h"
#include "complex.h"
#include <QFile>
#include <cstddef>
#include <QString>

class Tree
{
public:
    Tree();
    Tree(const Tree &a);
    void show();
    int size();
    bool isEmpty();
    void keyDelete(float _key);
    void keyInsert(Volume *_data);
    void save(QString file_name);
    void load(QString file_name);
    Volume* closestByVolume(float vol);
    Volume* keySearch(float _key);
    Node* root;
private:
    Node* nodeSearch(Node* _root, float _key);
    void showNode(Node *_root);
    void rotateLeft(Node* n);
    void rotateRight(Node* n);
    void firstDelete(Node *n);
    void firstInsert(Node* n);
    void secondDelete(Node *n);
    void secondInsert(Node* n);
    void thirdDelete(Node *n);
    void thirdInsert(Node* n);
    void forthDelete(Node *n);
    void forthInsert(Node* n);
    void fifthDelete(Node *n);
    void fifthInsert(Node* n);
    void sixDelete(Node *n);
    Node* nextNode(Node* n);
    int treeSize;
    Volume* recursive(float vol, Node* _root);
};

#endif // TREE_H
