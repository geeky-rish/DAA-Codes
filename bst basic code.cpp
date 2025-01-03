#include<iostream>
#include<cstdlib>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree TREE;

class binarysearchtree
{
public:
    TREE* insert_into_bst(TREE*, int);
    void inorder(TREE*);
    void preorder(TREE*);
    void postorder(TREE*);
    TREE* delete_from_bst(TREE*, int);
    int indegree(TREE*, TREE*);
    int outdegree(TREE*);
    TREE* treesearch();
    int countnodes(TREE*);
    int countedges(TREE*);
};

//INSERTION
TREE* binarysearchtree::insert_into_bst(TREE* root, int data)
{
    TREE* newnode = new TREE(); // Use 'new' in C++
    if (newnode == nullptr) // Check if memory allocation was successful
    {
        cout << "Memory allocation failed" << endl;
        return root;
    }

    newnode->data = data; // Initialize new node
    newnode->left = nullptr;
    newnode->right = nullptr;

    if (root == nullptr) // If the tree is empty, the new node becomes the root
    {
        root = newnode;
        cout << "Root node inserted into the tree" << endl;
        return root;
    }

    TREE* currnode = root; // Traverse the tree to find the correct insertion spot
    TREE* parent = nullptr;

    while (currnode != nullptr)
    {
        parent = currnode;
        if (newnode->data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }

    if (newnode->data < parent->data) // Insert node as the left or right child of parent
        parent->left = newnode;
    else
        parent->right = newnode;

    cout << "Node inserted successfully into the tree" << endl;
    return root;
}

// INORDER = LEFT ROOT RIGHT
void binarysearchtree::inorder(TREE* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

// PREORDER = ROOT LEFT RIGHT
void binarysearchtree::preorder(TREE* root)
{
    if (root != nullptr)
    {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER = LEFT RIGHT ROOT
void binarysearchtree::postorder(TREE* root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}

// DELETION FROM BST
TREE* binarysearchtree::delete_from_bst(TREE* root, int data)
{
    TREE* currnode = root;
    TREE* parent = nullptr;
    TREE* successor = nullptr;
    TREE* p = nullptr;

    if (root == nullptr) // Check if the tree is empty
    {
        cout << "Tree is empty" << endl;
        return root;
    }

    while (currnode != nullptr && currnode->data != data) // Traverse to find the node to delete
    {
        parent = currnode;
        if (data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }

    if (currnode == nullptr) // Data not found in the tree
    {
        cout << "Item not found" << endl;
        return root;
    }

    if (currnode->left == nullptr) // Node with no left subtree
        p = currnode->right;
    else if (currnode->right == nullptr) // Node with no right subtree
        p = currnode->left;
    else // Node with both left and right subtrees (find inorder successor)
    {
        successor = currnode->right;
        while (successor->left != nullptr)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    if (currnode == parent->left)
        parent->left = p;
    else
        parent->right = p;

    delete currnode; // Use delete instead of free for C++
    return root;
}

// OUT-DEGREE OF A NODE
int binarysearchtree::outdegree(TREE* node)
{
    if (node == nullptr)
        return -1; // If node is null, out-degree doesn't exist

    int count = 0;
    if (node->left != nullptr) count++;
    if (node->right != nullptr) count++;

    return count;
}

// IN-DEGREE OF A NODE (0 for root, 1 for all others)
int binarysearchtree::indegree(TREE* node, TREE* root)
{
    if (node == root) // Root has no parent, so in-degree is 0
        return 0;
    return 1; // All other nodes have in-degree of 1
}

int binarysearchtree::countnodes(TREE* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countnodes(root->left) + countnodes(root->right);
    }
}

int binarysearchtree::countedges(TREE* root) {
    int nodes = countnodes(root);
    if (nodes == 0) {
        return 0; // If there are no nodes, there are no edges
    } else {
        return nodes - 1; // Number of edges is nodes - 1
    }
}

int main()
{
    binarysearchtree bst;
    TREE* root = nullptr;
    int choice = 0;
    int data = 0;

    while (1)
    {
        cout << "MENU\n";
        cout << "1 - Insert into BST\n";
        cout << "2 - Inorder traversal\n";
        cout << "3 - Preorder traversal\n";
        cout << "4 - Postorder traversal\n";
        cout << "5 - Delete from BST\n";
        cout << "6 - In-degree of root\n";
        cout << "7 - Out-degree of root\n";
        cout << "8 - Number of edges in the tree\n";
        cout << "Any other option to exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the item to insert: ";
            cin >> data;
            root = bst.insert_into_bst(root, data);
            break;

        case 2:
            if (root == nullptr)
                cout << "Tree is empty\n";
            else
            {
                cout << "Inorder traversal is:\n";
                bst.inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == nullptr)
                cout << "Tree is empty\n";
            else
            {
                cout << "Preorder traversal is:\n";
                bst.preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == nullptr)
                cout << "Tree is empty\n";
            else
            {
                cout << "Postorder traversal is:\n";
                bst.postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "Enter the item to delete: ";
            cin >> data;
            root = bst.delete_from_bst(root, data);
            break;

        case 6:
            cout << "In-degree of root: " << bst.indegree(root, root) << endl;
            break;

        case 7:
            cout << "Out-degree of root: " << bst.outdegree(root) << endl;
            break;
        case 8:
            cout << "Total number of edges: " << bst.countedges(root) << endl;
            break;
        case 9:
            cout << "Total number of nodes: " << bst.countnodes(root) << endl;
            break;
        case 15:
            cout << "Address of the root node: " << &root << endl;
            break;
        default:
            cout << "Exiting program\n";
            exit(0);
        }
    }
    return 0;
}
