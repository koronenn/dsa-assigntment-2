//Arvin Akbari PROG72370
#include "dst.h"

//newNode function that takes a char, creates the new node and returns it
Node* newNode(char data)
{
    //allocating space for a new node of size node
    Node* node = (Node*)malloc(sizeof(Node));
    //check to see if malloc failed, if fails return null to stop function execution
    if (node == NULL)
    {
        return node;
    }
    //setting the nodes data to be the same data passed to the function
    node->data = data;
    //setting the new nodes left and right pointers to null and returning the new node
    node->left = NULL;
    node->right = NULL;
    return node;
}

//insert funcction that takes the trees root node and a new data variable then creates a new node and adds to the tree
Node* insert(Node* root, char data)
{
    //checking to see if the root is null, if so create the new node and return it
    if (root == NULL)
    {
        return newNode(data);
    }
    //check to see if the given character is higher or lower than the current roots data
    //if so call insert function to the roots left node
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    //otherwise call insert recursively to the roots right node
    else
    {
        root->right = insert(root->right, data);
    }


    return root;
}

//search function that takes a root and a char data and returns the root that has the same data
Node* search(Node* root, char data)
{
    //check to see if root is null or if data is the same, if so return the current root
    if (root == NULL || root->data == data)
    {
        return root;
    }

    //check to see if the roots data is less than the passed data, if so recusively call search the roots right node
    if (root->data < data)
    {
        return search(root->right, data);
    }
    //otherwise call search to the roots left nodes
    return search(root->left, data);
}

//count nodes function that takes the root of the tree
int countNodes(Node* root)
{
    //checking to see if the current root is null, if so return 0
    if (root == NULL)
    {
        return 0;
    }

    //otherwise recursively call countNodes for both right and left nods and add 1
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//treeHeight function that finds the trees maximum height, taking the trees root
int treeHeight(Node* root)
{
    //checking to see if the current root is null, if so return 0
    if (root == NULL)
    {
        return 0;
    }

    //setting ints for left and right trees heights, creating recursive calls for both left and right nodes
    int leftTreeHeight = treeHeight(root->left);
    int rightTreeHeight = treeHeight(root->right);

    //check to see if the left trees height is greater than or equal to the right trees, if so return the left trees height +1
    if (leftTreeHeight >= rightTreeHeight)
    {
        return leftTreeHeight + 1;
    }
    //else return right trees height + 1
    else
    {
        return rightTreeHeight + 1;
    }
}

//inOrderTraversal function that traverses the whole tree in order, taking the trees root
void inOrderTraversal(Node* root)
{
    //if statement allowing the function to operate so long as the root is not null
    if (root != NULL)
    {
        //first traversing the left side of the tree
        inOrderTraversal(root->left);
        //after left side traversal complete printing the data in the centre node
        printf("%c ", root->data);
        //then traversing the right side of the tree
        inOrderTraversal(root->right); 
        return;
    }
    
    return;
}

//free tree function that takes the root of the tree
void freeTree(Node* root)
{
    //check to see if the tree is null, if so return
    if (root == NULL)
    {
        return;
    }
    //recursively calling freeTree on first the left side of the root and then the right side
    freeTree(root->left);
    freeTree(root->right);

    //free the current root
    free(root);
}