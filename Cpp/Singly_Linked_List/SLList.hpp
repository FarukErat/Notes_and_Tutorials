#pragma once
#ifndef SLL_HPP
#define SLL_HPP

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
class SLL
{
private:
    Node<T> *head = nullptr;
    int size = 0;

public:
    int getSize() const { return size; }

    void add(T data);
    void remove(int index);
    void insert(T data, int index);

    T pop();

    T &operator[](int index);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const SLL<U> &list);
};

template <typename T>
void SLL<T>::add(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
void SLL<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr)
    {
        if (currentIndex == index)
        {
            if (previous != nullptr)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
        currentIndex++;
    }
}

template <typename T>
void SLL<T>::insert(T data, int index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node<T> *current = head;
        int currentIndex = 0;
        while (current != nullptr)
        {
            if (currentIndex == index - 1)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
            currentIndex++;
        }
    }
    size++;
}

template <typename T>
T SLL<T>::pop()
{
    if (size == 0)
    {
        throw std::out_of_range("List is empty");
    }
    Node<T> *current = head;
    head = head->next;
    T data = current->data;
    delete current;
    size--;
    return data;
}

template <typename T>
T &SLL<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    int currentIndex = 0;

    while (current != nullptr)
    {
        if (currentIndex == index)
        {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const SLL<U> &list)
{
    Node<U> *current = list.head;
    while (current != nullptr)
    {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

#endif // SLL_HPP
