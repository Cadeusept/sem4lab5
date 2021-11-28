// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <algorithm>
#include


int empty();

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
        if constexpr (std::is_copy_assignable<T>::value) {
            current->value = T();
        }
    }

    ~Stack(){
        while (current->prev != nullptr){
            auto tmp = current;
            current = current->prev;
            delete tmp;
        }
        delete current;
    }

    void push(T&& value) {
        auto old_el = current;
        current = new StackElement();
        current->prev = old_el;
        current->value = std::move(value);
    }

    void push(const T& value) {
        if constexpr (std::is_copy_assignable<T>::value) {
            auto old_el = current;
            current = new StackElement();
            current->prev = old_el;
            current->value = value;
        } else
            throw std::logic_error("Cannot assign, try to use push_emplace()");
    }

    template <typename ...Args>
    void push_emplace(const Args&&... values) {
        if constexpr (!std::is_copy_assignable<T>::value) {
            current = new StackElement(current, values...);
        } else
            throw std::logic_error("Can assign, try to use push()");
    }

    void pop() {
        if (current->prev != nullptr) {
	    auto temp = current;
	    current = current->prev;
	    delete temp;
	}
    }

    const T& head() const{
        return current->value;
    }

private:
    struct StackElement{
        StackElement* prev;
        T value;

        template <typename ...Args>
        StackElement(StackElement* a,Args&& ...values):
                     prev(a), value(values...) {}

        StackElement() {}
    } *current;
};

#endif // INCLUDE_STACK_HPP_
