#pragma once
#ifndef BI_TREE_HPP
#define BI_TREE_HPP

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *left = nullptr;
    Node *right = nullptr;
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root = nullptr;

public:
    ~BinaryTree();

    void insert(T);
    void remove(T data);
    void display(Node<T> *root);
    void display() { display(root); }
    void search(T data);

    Node<T> *getRoot() { return root; }
};

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    Node<T> *current = root;
    Node<T> *parent = nullptr;

    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            parent = current;
            current = current->right;
            delete parent;
        }
        else
        {
            Node<T> *successor = current->left;
            Node<T> *successorParent = current;

            while (successor->right != nullptr)
            {
                successorParent = successor;
                successor = successor->right;
            }

            if (successorParent != current)
            {
                successorParent->right = successor->left;
                successor->left = current->left;
            }

            parent = current;
            current = current->right;
            successor->right = current;
            current = successor;
            delete parent;
        }
    }
}

template <typename T>
void BinaryTree<T>::insert(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node<T> *current = root;
        Node<T> *parent = nullptr;

        while (true)
        {
            parent = current;

            if (data < current->data)
            {
                current = current->left;
                if (current == nullptr)
                {
                    parent->left = newNode;
                    break;
                }
            }
            else
            {
                current = current->right;
                if (current == nullptr)
                {
                    parent->right = newNode;
                    break;
                }
            }
        }
    }
}

template <typename T>
void BinaryTree<T>::remove(T data)
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    Node<T> *current = root;
    Node<T> *parent = root;
    bool isLeft = true;

    while (current->data != data)
    {
        parent = current;
        if (data < current->data)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }

        if (current == nullptr)
        {
            std::cout << "Data not found" << std::endl;
            return;
        }
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (current == root)
        {
            root = nullptr;
        }
        else if (isLeft)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }
    else if (current->right == nullptr)
    {
        if (current == root)
        {
            root = current->left;
        }
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }
    else if (current->left == nullptr)
    {
        if (current == root)
        {
            root = current->right;
        }
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }
    else
    {
        Node<T> *successor = current->right;
        Node<T> *successorParent = current;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }

        successorParent->left = successor->right;
        successor->left = current->left;
        successor->right = current->right;
    }

    delete current;
}

template <typename T>
void BinaryTree<T>::display(Node<T> *root)
{
    if (root != nullptr)
    {
        display(root->left);
        std::cout << root->data << " ";
        display(root->right);
    }
}

template <typename T>
void BinaryTree<T>::search(T data)
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    Node<T> *current = root;

    while (current->data != data)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current == nullptr)
        {
            std::cout << "Data not found" << std::endl;
            return;
        }
    }

    std::cout << "Data found" << std::endl;
}

#endif // BI_TREE_HPP
