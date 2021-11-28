// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <stack.hpp>
#include <stdexcept>

TEST(Equality, constructor) {
    Stack<int> stack;
    EXPECT_EQ(bool(stack.head()), false);
}
