#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

//Constructor
template <typename T>
Stack<T>::Stack() {}

//Destructor
template <typename T>
Stack<T>::~Stack() {}

template <typename T>
bool Stack<T>::empty() const {return std::vector<T>::empty(); }
//check whether its empty or not

template <typename T>
size_t Stack<T>::size() const { return std::vector<T>::size(); }
//return num of items
//dont do return this->size().. which would call size onece more..

template <typename T>
void Stack<T>::push(const T& item) { std::vector<T>::push_back(item); }
//push item at the top

template <typename T>
void Stack<T>::pop()
{
    if(std::vector<T>::empty()) throw std::underflow_error("Stack is empty");

    std::vector<T>::pop_back();
}
//del top item

template <typename T>
const T& Stack<T>::top() const
{
    if(std::vector<T>::empty()) throw std::underflow_error("Stack is empty");

    return std::vector<T>::back();
}
//return top item


#endif