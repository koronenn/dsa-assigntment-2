//Arvin Akbari PROG72370
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//declaring the node struct
typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
}Node;

//creating prototypes for all binary search tree functions
Node* newNode(char data);

Node* insert(Node* root, char data);

Node* search(Node* root, char data);

int countNodes(Node* root);

int treeHeight(Node* root);

void inOrderTraversal(Node* root);

void freeTree(Node* root);