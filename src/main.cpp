#include <iostream>
#include <CircularBuffer.hpp>

using namespace circular_buffer;

int main() {
    
    CircularBuffer cb(5);
    cb.printBuffer();

    return 0;
}
