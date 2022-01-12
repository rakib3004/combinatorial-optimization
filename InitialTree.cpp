#include<bits/stdc++.h>
using namespace std;
#define DEPTH 3


class Node{

    bool internalNode;
    int *keyValue;
    int blockSize;
    Node** pointer;

    friend class BplusTree;



public:
    Node();

};


class BplusTree{

Node* root;

void insertInternal(int, Node*, Node*);

Node* findParent(Node*, Node*);

public:
    BplusTree();
    void search(int);
    void insert(int);
    void display(Node*);

    Node* getRoot();
    

};
//okay not okay
Node::Node(){

    keyValue = new int[DEPTH];
    pointer = new Node* [DEPTH+1];
}



int main(){



    return 0;
}