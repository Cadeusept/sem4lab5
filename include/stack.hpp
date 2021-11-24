// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <algorithm>


auto example() -> void;

template <typename T>
class Stack
{
public:
    Stack(const Stack&) = delete; //non-copyable
    Stack& operator=(const Stack&) = delete;

    Stack(Stack&&) = default; //moveable

    Stack(){
        current = new StackElement;
        current->prev = nullptr;
    }

    void push(T&& value) {
        auto old_el = current;
        current->prev = old_el;
        current->value = std::move(value);
    };

    void push(const T& value) {
        auto old_el = current;
        current = new StackElement();
        current->prev = old_el;
        current->value = value;
    };

    T pop() {
        if (current->prev != nullptr) {
            auto tmp = current;
            current = current->prev;
            T val = tmp->value;
            delete tmp;
            return val;
        } else
            return NULL;
    };

    const T& head() const{
        return current->value;
    };

private:
    struct StackElement{
        StackElement* prev;
        T value;
        StackElement() {
        }
    } *current;
};

#endif // INCLUDE_STACK_HPP_
