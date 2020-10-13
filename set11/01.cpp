#include <iostream>

using std::cout;    using std::endl;
using std::cin;

/* basic structure to store elements of a tree */
struct Node {
    int val;        // contains the value
    Node *left;     // pointer to the left child
    Node *right;    // pointer to the right child
};

/* class Tree */
class BinaryTree {

    public:
        BinaryTree();
        ~BinaryTree();

        void fibonacci(int n);
        int size();
        int depth();
        int leafs();
        void print();
    
    private:
        Node *root;             // Pointer to the root of the tree
        Node *aux(int n);
        int size(Node *node);
        int depth(Node *node);
        int leafs(Node *node);
        void print(Node *leaf);
};

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    /* empty */
}


void BinaryTree::fibonacci(int n)
{
    root = new Node;

    if (n <= 1) {
        root->val = 1;
        root->left = NULL;
        root->right = NULL;
    } else {
        root->left = aux(n - 1);
        root->right = aux(n - 2);
        root->val = root->left->val + root->right->val;
    }
}

Node *BinaryTree::aux(int n)
{
    Node *node = new Node();
    
    if (n <= 1) {
        node->val = 1;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    node->left = aux(n - 1);
    node->right = aux(n - 2);
    node->val = node->left->val + node->right->val;
    return node;
}

int BinaryTree::size()
{
    if (root == NULL)
        return 0;
    
    return 1 + size(root->left) + size(root->right);
}

int BinaryTree::size(Node *node)
{
    if (node != NULL)
        return 1 + size(node->left) + size(node->right);
    else
        return 0;
}

int BinaryTree::depth()
{
    if (root == NULL)
        return 0;
    else {
        int left_depth =  depth(root->left);
        int right_depth = depth(root->right);

        if (left_depth > right_depth)
            return left_depth + 1;
        else 
            return right_depth + 1;
    }
}

int BinaryTree::depth(Node *node)
{   if (node == NULL)
        return 0;
    else {
        int left_depth =  depth(node->left);
        int right_depth = depth(node->right);

        if (left_depth > right_depth)
            return left_depth + 1;
        else
            return right_depth + 1;
    }
}

int BinaryTree::leafs()
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leafs(root->left) + leafs(root->right);
}

int BinaryTree::leafs(Node *node)
{
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return leafs(node->left) + leafs(node->right);
}

void BinaryTree::print()
{
    print(root);
    cout << endl;
}

void BinaryTree::print(Node *node)
{
    if (node != NULL) {
        cout << node->val << " ";
        print(node->left);
        print(node->right);
    }
}

int main(void)
{
    int n;
    BinaryTree bt;

    cin >> n;
    bt.fibonacci(n);
    
    cout << "Call tree in pre-order: "; 
    bt.print();
    cout << "Call tree size: " << bt.size() << endl;
    cout << "Call tree depth: " << bt.depth() << endl;
    cout << "Call tree leafs: " << bt.leafs() << endl;

    return 0;
}