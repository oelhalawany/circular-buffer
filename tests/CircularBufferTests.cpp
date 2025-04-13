#include <gtest/gtest.h>
#include "CircularBuffer.hpp"

using namespace circular_buffer;

TEST(CircularBufferTest, PushPopSingleValue)
{
    CircularBuffer buffer(3);

    EXPECT_TRUE(buffer.isEmpty());
    buffer.push(42);
    EXPECT_FALSE(buffer.isEmpty());
    EXPECT_EQ(buffer.pop(), 42);
    EXPECT_TRUE(buffer.isEmpty());
}

TEST(CircularBufferTest, PushUntilFull)
{
    CircularBuffer buffer(2);

    buffer.push(1);
    buffer.push(2);
    EXPECT_TRUE(buffer.isFull());

    // Try pushing to a full buffer (should not insert)
    buffer.push(3);  // Will just print message, not crash
    EXPECT_EQ(buffer.pop(), 1);
    EXPECT_EQ(buffer.pop(), 2);
}

TEST(CircularBufferTest, PopFromEmptyReturnsMinusOne)
{
    CircularBuffer buffer(2);
    EXPECT_EQ(buffer.pop(), -1);  // Nothing to pop
}

TEST(CircularBufferTest, WrapAroundBehavior)
{
    CircularBuffer buffer(2);

    buffer.push(5);
    buffer.push(6);
    EXPECT_EQ(buffer.pop(), 5);

    buffer.push(7); // Should wrap around
    EXPECT_EQ(buffer.pop(), 6);
    EXPECT_EQ(buffer.pop(), 7);
}
