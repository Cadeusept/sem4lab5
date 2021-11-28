// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <stack.hpp>
#include <stdexcept>

class NonCopyAssignable {
public:
    int a;
    float b;

    NonCopyAssignable() = default;

    NonCopyAssignable(int val1, float val2) {
        a = val1;
        b = val2;
    }

    NonCopyAssignable& operator=(const NonCopyAssignable&) = delete;
};

TEST(Equality_n_Throw, All_Checks) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    EXPECT_EQ(stack.head(),5);
    stack.pop();
    EXPECT_EQ(stack.head(),4);

    Stack<NonCopyAssignable> stack1;
    stack1.push_emplace(1, 5.0);
    stack1.push_emplace(2, 10.0);
    stack1.pop();
    EXPECT_EQ(stack1.head().a,1);
    EXPECT_EQ(stack1.head().b,5.0);

    EXPECT_THROW(stack1.push(NonCopyAssignable(2,10.0)),
                 std::logic_error);
    EXPECT_THROW(stack.push_emplace(1),
                 std::logic_error);
}
