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
        if(elementsCount_>=size_)
        {
            cout<<"Buffer is full!"<<endl;
            return;
        }

        buffer_[writeIdx_] = value;
        writeIdx_ = (writeIdx_+1) % size_;
        elementsCount_++;
    }

    int CircularBuffer::pop()
    {
        if(elementsCount_ == 0)
        {
            cout<<"Buffer is empty!"<<endl;
            return -1;
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
