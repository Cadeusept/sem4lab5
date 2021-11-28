// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <stack.hpp>
#include <stdexcept>

TEST(Equality, Constructors_dectructors_head) {
    Stack<int> stack;
    EXPECT_EQ(bool(stack.head()),false);
    stack.Stack<int>::~Stack<int>();

    Stack<int> stack1(1);
    EXPECT_EQ(stack1.head(),1);
    stack1.Stack<int>::~Stack<int>();


    Stack<int> stack2(Stack<int>(2));
    EXPECT_EQ(stack2.head(),2);
    stack2.Stack<int>::~Stack<int>();
}

TEST(Equality, Push_pop) {
    Stack<int> stack(1);
    stack.push(2);
    EXPECT_EQ(stack.head(),2);
    stack.push(int(3));
    EXPECT_EQ(stack.head(),3);
    int i=4;
    stack.push(i);
    EXPECT_EQ(stack.head(),4);

    stack.pop();
    EXPECT_EQ(stack.head(),3);
    stack.pop();
    EXPECT_EQ(stack.head(),2);
    stack.pop();
    EXPECT_EQ(stack.head(),1);
    stack.pop();
    EXPECT_EQ(bool(stack.head()),false);
    stack.pop();
    EXPECT_EQ(bool(stack.head()),false);
}
