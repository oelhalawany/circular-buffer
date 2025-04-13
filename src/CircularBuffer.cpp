#include <iostream>
#include "CircularBuffer.hpp"

using namespace std;

namespace circular_buffer{

    CircularBuffer::CircularBuffer(int size)
    {
        size_ = size;
        buffer_ = new int[size_];
    }

    CircularBuffer::~CircularBuffer()
    {
        delete[] buffer_;
    }

    void CircularBuffer::printBuffer()
    {
        for(int i=0; i<size_; i++)
        {
            cout<<buffer_[i]<<" ";
        }
        cout<<endl;
    }


}//end of name space circular_buffer
