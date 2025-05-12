#include <gtest/gtest.h>
#include "CircularBuffer.hpp"

using namespace circular_buffer;

TEST(CircularBufferTest, PushPopSingleValue)
{
    CircularBuffer buffer(3);

    EXPECT_TRUE(buffer.isEmpty());
    buffer.push(42);
    EXPECT_FALSE(buffer.isEmpty());
    auto value = buffer.pop();
    EXPECT_TRUE(value.has_value());
    EXPECT_EQ(value.value(), 42);
    EXPECT_TRUE(buffer.isEmpty());
}

TEST(CircularBufferTest, PushUntilFull)
{
    CircularBuffer buffer(2);

    buffer.push(1);
    buffer.push(2);
    EXPECT_TRUE(buffer.isFull());

    // Try pushing to a full buffer (should not insert if overwrite is not allowed)
    buffer.push(3);  // Will just print message, not crash
    EXPECT_EQ(buffer.pop().value(), 1);
    EXPECT_EQ(buffer.pop().value(), 2);
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, PopFromEmptyReturnsNullopt)
{
    CircularBuffer buffer(2);
    auto value = buffer.pop();
    EXPECT_FALSE(value.has_value());  // Nothing to pop
}

TEST(CircularBufferTest, WrapAroundBehavior)
{
    CircularBuffer buffer(2);

    buffer.push(5);
    buffer.push(6);
    EXPECT_EQ(buffer.pop().value(), 5);

    buffer.push(7); // Should wrap around
    EXPECT_EQ(buffer.pop().value(), 6);
    EXPECT_EQ(buffer.pop().value(), 7);
}

TEST(CircularBufferTest, OverwriteAllowedBehavior)
{
    CircularBuffer buffer(3);
    buffer.setOverwriteAllowed(true);

    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    EXPECT_TRUE(buffer.isFull());

    // Push more elements, overwriting the oldest ones
    buffer.push(4); // Overwrites 1
    buffer.push(5); // Overwrites 2

    EXPECT_EQ(buffer.pop().value(), 3); // Oldest remaining element
    EXPECT_EQ(buffer.pop().value(), 4);
    EXPECT_EQ(buffer.pop().value(), 5);
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, OverwriteNotAllowedBehavior)
{
    CircularBuffer buffer(3);
    buffer.setOverwriteAllowed(false);

    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    EXPECT_TRUE(buffer.isFull());

    // Try pushing more elements, should not overwrite
    buffer.push(4); // Should not overwrite
    buffer.push(5); // Should not overwrite

    EXPECT_EQ(buffer.pop().value(), 1); // Oldest element
    EXPECT_EQ(buffer.pop().value(), 2);
    EXPECT_EQ(buffer.pop().value(), 3);
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, EdgeCasesWithOverwrite)
{
    CircularBuffer buffer(1); // Buffer of size 1
    buffer.setOverwriteAllowed(true);

    buffer.push(10);
    EXPECT_EQ(buffer.pop().value(), 10);

    buffer.push(20);
    buffer.push(30); // Overwrites 20
    EXPECT_EQ(buffer.pop().value(), 30); // Only 30 remains
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}
TEST(CircularBufferTest, ConstructorWithOverwriteAllowedTrue)
{
    CircularBuffer buffer(3, true); // Overwrite allowed directly in constructor

    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    EXPECT_TRUE(buffer.isFull());

    // Push more elements, overwriting the oldest ones
    buffer.push(4); // Overwrites 1
    buffer.push(5); // Overwrites 2

    EXPECT_EQ(buffer.pop().value(), 3); // Oldest remaining element
    EXPECT_EQ(buffer.pop().value(), 4);
    EXPECT_EQ(buffer.pop().value(), 5);
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, ConstructorWithOverwriteAllowedFalse)
{
    CircularBuffer buffer(3, false); // Overwrite not allowed directly in constructor

    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    EXPECT_TRUE(buffer.isFull());

    // Try pushing more elements, should not overwrite
    buffer.push(4); // Should not overwrite
    buffer.push(5); // Should not overwrite

    EXPECT_EQ(buffer.pop().value(), 1); // Oldest element
    EXPECT_EQ(buffer.pop().value(), 2);
    EXPECT_EQ(buffer.pop().value(), 3);
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, ConstructorWithOverwriteAllowedEdgeCase)
{
    CircularBuffer buffer(1, true); // Buffer of size 1 with overwrite allowed

    buffer.push(10);
    EXPECT_EQ(buffer.pop().value(), 10);

    buffer.push(20);
    buffer.push(30); // Overwrites 20
    EXPECT_EQ(buffer.pop().value(), 30); // Only 30 remains
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}

TEST(CircularBufferTest, ConstructorWithOverwriteAllowedFalseEdgeCase)
{
    CircularBuffer buffer(1, false); // Buffer of size 1 with overwrite not allowed

    buffer.push(10);
    EXPECT_EQ(buffer.pop().value(), 10);

    buffer.push(20);
    buffer.push(30); // Should not overwrite 20
    EXPECT_EQ(buffer.pop().value(), 20); // Only 20 remains
    EXPECT_FALSE(buffer.pop().has_value()); // Buffer is now empty
}
