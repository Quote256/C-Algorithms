#include <iostream>

using namespace std;

class NodeTree
{
    friend class BTree;

private:
    int _key;
    int _height;

    NodeTree *left;
    NodeTree *right;

public:
    NodeTree(int key, NodeTree *leftNode = nullptr, NodeTree *rightNode = nullptr)
    {
        _key = key;
        left = leftNode;
        right = rightNode;
        _height = 0;
    }
};

class BTree
{
private:
    NodeTree *root_;

    NodeTree *maxNode(NodeTree *newNode)
    {
        if (newNode->right == nullptr)
            return newNode;
        else
            return maxNode(newNode->right);
    }

    //These are the rotations for the AVL Tree
    NodeTree *rotateLeft(NodeTree *x)
    {
        NodeTree *new_x = x->right;
        x->right = new_x->left;
        new_x->left = x;

        x->_height = max(subHeight(x->left), subHeight(x->right));
        new_x->_height = max(subHeight(new_x->left), subHeight(new_x->right));

        return new_x;
    }

    NodeTree *rotateRight(NodeTree *t)
    {
        NodeTree *new_t = t->left;
        t->left = new_t->right;
        new_t->right = t;

        t->_height = max(subHeight(t->left), subHeight(t->right));
        new_t->_height = max(subHeight(new_t->left), subHeight(new_t->right));

        return new_t;
    }

    NodeTree *doubleRotateRight(NodeTree *y)
    {
        y->left = rotateRight(y->left);
        return rotateRight(y);
    }

    NodeTree *doubleRotateLeft(NodeTree *z)
    {
        z->right = rotateRight(z->right);
        return rotateRight(z);
    }

    //
    int subHeight(NodeTree *node)
    {
        return (node != nullptr) ? node->_height + 1 : 0;
    }

    NodeTree *_insert(int key, NodeTree *n)
    {

        if (n == nullptr)
        {
            return n = new NodeTree(key);
        }
        else if (key < n->_key)
        {
            n->left = _insert(key, n->left);
        }
        else if (key > n->_key)
        {
            n->right = _insert(key, n->right);
        }
        else if (n->_key == key)
            return n;

        int leftHeight = subHeight(n->left);
        int rightHeight = subHeight(n->right);
        int treeBalance = leftHeight - rightHeight;

        if (treeBalance > 1)
        {
            if (key < n->left->_key)
            {
                return n = rotateRight(n);
            }
            else
            {
                n->left = rotateLeft(n->left);
                return n = rotateRight(n);
            }
        }
        else if (treeBalance < -1)
        {
            if (key < n->right->_key)
            {
                n->right = rotateRight(n->right);
                return n = rotateLeft(n);
            }
            else
            {
                return n = rotateLeft(n);
            }
        }

        return n;
    }

    //EXTRA CREDIT
    NodeTree *_delete(int key, NodeTree *d)
    {
        //Defines the height of the left nodes and the right nodes
        int leftHeight = subHeight(d->left);
        int rightHeight = subHeight(d->right);

        //determines whether the tree is balanced or not.
        int treeBalance = leftHeight - rightHeight;

        if (d == nullptr)
        {
            return nullptr;
        }
        else if (key > d->_key)
        {
            d->right = _delete(key, d->right);
        }
        else if (key < d->_key)
        {
            d->left = _delete(key, d->left);
        }
        else
        {
            if (d->left == nullptr && d->right == nullptr)
            {
                delete d;
                return nullptr;
            }
            else if (d->left != nullptr && d->right == nullptr)
            {
                NodeTree *sub_left_tree = d->left;
                delete d;
                return sub_left_tree;
            }
            else if (d->left == nullptr && d->right != nullptr)
            {
                NodeTree *sub_right_tree = d->right;
                delete d;
                return sub_right_tree;
            }
            else
            {
                NodeTree *maxLeftNode = maxNode(d->left);
                d->_key = maxLeftNode->_key;
                d->left = _delete(maxLeftNode->_key, d->left);
            }
        }

        d->_height = max(leftHeight, rightHeight);

        if (treeBalance > 1)
        {
            if (subHeight(d->left->left) > subHeight(d->left->right))
            {
                return d = rotateRight(d);
            }
            else
            {
                d->left = rotateLeft(d->left);
                return d = rotateRight(d);
            }
        }
        else if (treeBalance < -1)
        {
            if (subHeight(d->right->left) > subHeight(d->right->right))
            {
                d->right = rotateRight(d->right);
                return d = rotateLeft(d);
            }
            else
            {
                return d = rotateLeft(d);
            }
        }

        return d;
    }

public:
    BTree()
    {
        root_ = nullptr;
    }

    void insert(int key)
    {
        root_ = _insert(key, root_);
    }

    void remove(int key)
    {
        root_ = _delete(key, root_);
    }
};

int main()
{
    BTree avltree;

    //Insert nodes into the binary tree
    avltree.insert(7);
    avltree.insert(11);
    avltree.insert(20);
    avltree.insert(4);
    avltree.insert(100);
    avltree.insert(31);
    avltree.insert(82);
    avltree.insert(15);

    //Delete some nodes
    avltree.remove(20);
    avltree.remove(4);
    avltree.remove(100);
    avltree.remove(82);

    return 0;
}