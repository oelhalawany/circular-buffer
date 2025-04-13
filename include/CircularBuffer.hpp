namespace circular_buffer{

class CircularBuffer {

private:
        
    int* buffer_;
    int size_;
    int writeIdx_;
    int readIdx_;
    int elementsCount_;

public:

    CircularBuffer(int size);
    ~CircularBuffer();

    void push(int value);
    int pop();
    bool isFull();
    bool isEmpty();
    void printBuffer();
};

} //end of namespace circular_buffer