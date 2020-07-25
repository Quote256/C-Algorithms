#include <iostream>

using namespace std;

class AVLNode
{
    friend class AVLTree;

private:
    int key_;
    int height_;

    AVLNode *left_node_;
    AVLNode *right_node_;

public:
    AVLNode(int key, AVLNode *left_node = nullptr, AVLNode *right_node = nullptr)
    {
        key_ = key;
        left_node_ = left_node;
        right_node_ = right_node;
        height_ = 0;
    }
    ~AVLNode()
    {
    }
};
