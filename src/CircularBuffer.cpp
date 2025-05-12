#include <iostream>
#include "CircularBuffer.hpp"

using namespace std;

namespace circular_buffer{

    CircularBuffer::CircularBuffer(int size)
    {
        size_ = size;
        buffer_ = new int[size_](); // init all buffer elements to zero 
        writeIdx_ = 0;
        readIdx_ = 0;
        elementsCount_ = 0;
        overwriteAllowed_ = false;
        cout<<"Buffer created with size "<<size_<<endl;
    }

    CircularBuffer::CircularBuffer(int size, bool overwriteAllowed)
    {
        size_ = size;
        buffer_ = new int[size_];
        writeIdx_ = 0;
        readIdx_ = 0;
        elementsCount_ = 0;
        overwriteAllowed_ = overwriteAllowed;
        cout<<"Buffer created with size "<<size_<<endl;
    }

    CircularBuffer::~CircularBuffer()
    {
        delete[] buffer_;
        cout<<"Buffer deleted!"<<endl;
    }

    void CircularBuffer::printBuffer()
    {
        for(int i=0; i<size_; i++)
        {
            cout<<buffer_[i]<<" ";
        }
        cout<<endl;
    }

    void CircularBuffer::push(int value)
    {
        if(!isOverwriteAllowed() && elementsCount_>=size_)
        {
            cout<<"Buffer is full!"<<endl;
            return;
        }

        if(isFull() && isOverwriteAllowed())
        {
            cout<<"Buffer is full! Overwriting the oldest element."<<endl;
            readIdx_ = (readIdx_+1) % size_;
            elementsCount_--;
        }

        buffer_[writeIdx_] = value;
        writeIdx_ = (writeIdx_+1) % size_;
        elementsCount_++;
    }

    std::optional<int> CircularBuffer::pop()
    {
        if(elementsCount_ == 0)
        {
            cout<<"Buffer is empty!"<<endl;
            return std::nullopt;
        }

        int ret = buffer_[readIdx_];
        readIdx_ = (readIdx_+1) % size_;
        elementsCount_--;
        return ret;
    }

    bool CircularBuffer::isFull()
    {
        return (elementsCount_== size_);
    }


    bool CircularBuffer::isEmpty()
    {
        return (elementsCount_ == 0);
    }

}//end of name space circular_buffer
