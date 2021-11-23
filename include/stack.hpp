// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

auto example() -> void;

template <typename T>
class Stack
{
public:
    void push(T&& value);

    void push(const T& value) {
        auto old_el = current;
        current = new StackElement();
        current->prev=old_el;
        current->value=value;
    };

    void pop() {
        if (current->prev != nullptr) {
            auto tmp=current;
            current=current->prev;
            delete tmp;
        }
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
