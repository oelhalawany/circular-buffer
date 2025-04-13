#include <iostream>
#include <CircularBuffer.hpp>

using namespace std;
using namespace circular_buffer;

int main() {
    
    CircularBuffer cb(5);
    cout<<"Empty? "<<cb.isEmpty()<<endl;
    cb.printBuffer();
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cout<<"Full? "<<cb.isFull()<<endl;
    cout<<"Empty? "<<cb.isEmpty()<<endl;
    cb.printBuffer();
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"popped -> "<<cb.pop()<<endl;
    cout<<"Empty? "<<cb.isEmpty()<<endl;

    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    cout<<"Full? "<<cb.isFull()<<endl;
    cb.push(6);

    return 0;
}
