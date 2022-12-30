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
    bool boundCheck(int index);

public:
    SLL(){};
    SLL(std::initializer_list<T> const l);
    ~SLL();

    int getSize() const { return size; }

    void add(T data);
    void append(T data);
    void remove(int index);
    void insert(T data, int index);

    T pop();

    T &operator[](int index);

    void operator=(SLL<T> &list);
    void operator=(std::initializer_list<T> const l);

    void operator+=(T data);
    void operator+=(SLL<T> &list);
    void operator+=(std::initializer_list<T> const l);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const SLL<U> &list);
    template <typename U>
    friend std::istream &operator>>(std::istream &is, SLL<U> &list);
};

template <typename T>
bool SLL<T>::boundCheck(int index)
{
    Node<T> *iter = head;
    for (int i = 0; i < index; i++)
    {
        if (iter == NULL)
        {
            return false;
        }
        iter = iter->next;
    }
    return true;
}

template <typename T>
SLL<T>::SLL(std::initializer_list<T> const l)
{
    for (auto &i : l)
    {
        append(i);
    }
}

template <typename T>
SLL<T>::~SLL()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

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
void SLL<T>::append(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node<T> *iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
        }
        iter->next = newNode;
    }
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

template <typename T>
void SLL<T>::operator=(SLL<T> &list)
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
    Node<T> *current = list.head;
    while (current != nullptr)
    {
        append(current->data);
        current = current->next;
    }
}

template <typename T>
void SLL<T>::operator=(std::initializer_list<T> const l)
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
    for (auto &i : l)
    {
        append(i);
    }
}

template <typename T>
void SLL<T>::operator+=(T data)
{
    append(data);
}

template <typename T>
void SLL<T>::operator+=(SLL<T> &list)
{
    Node<T> *current = list.head;
    while (current != nullptr)
    {
        append(current->data);
        current = current->next;
    }
}

template <typename T>
void SLL<T>::operator+=(std::initializer_list<T> const l)
{
    for (auto &i : l)
    {
        append(i);
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

template <typename T>
std::istream &operator>>(std::istream &is, SLL<T> &list)
{
    T data;
    is >> data;
    list.append(data);
    return is;
}

#endif // SLL_HPP
