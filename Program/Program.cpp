﻿#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * left;
    Node * right; 
};

Node * CreateNode(int data, Node * left, Node * right)
{
    Node * newNode = new Node();

    newNode->data = data;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

void Preorder(Node * root)
{
    if (root != nullptr)
    {
        cout << "Pre : " << root->data << endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(Node * root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << "Ino : " << root->data << endl;
        Inorder(root->right);
    }
}

void Postorder(Node* root)
{
    if (root != nullptr)
    {
       
        Postorder(root->left);
        Postorder(root->right);
        cout << "Pos : " << root->data << endl;
    }
}


int main()
{
        Node* node5 = CreateNode(5, nullptr , nullptr);
        Node* node4 = CreateNode(4, nullptr , nullptr);
        Node* node3 = CreateNode(3, nullptr , nullptr);
        Node* node2 = CreateNode(2, node4 , node5);
        Node* node1 = CreateNode(1, node2 , node3);

        // 전위 순회
        Preorder(node1);

        // 중위 순회
        Inorder(node1);

        // 후위 순회
        Postorder(node1);

    return 0;
}