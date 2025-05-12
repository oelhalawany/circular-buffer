#include <optional>

namespace circular_buffer{

class CircularBuffer {

private:
        
    int* buffer_;
    int size_;
    int writeIdx_;
    int readIdx_;
    int elementsCount_;
    bool overwriteAllowed_;

public:

    CircularBuffer(int size);
    CircularBuffer(int size, bool overwriteAllowed);
    ~CircularBuffer();

    void push(int value);
    std::optional<int> pop();
    bool isFull();
    bool isEmpty();
    void printBuffer();
    void setOverwriteAllowed(bool overwriteAllowed) { overwriteAllowed_ = overwriteAllowed; }
    bool isOverwriteAllowed() { return overwriteAllowed_; }
    int getSize() { return size_; }
    int getElementsCount() { return elementsCount_; }
};

} //end of namespace circular_buffer