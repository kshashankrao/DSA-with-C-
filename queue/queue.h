template <typename t>
class Queue
{
public:
    Queue(int size);
    ~Queue();
    void push(t element);
    t pop();
    t peek();

private:
    int capacity;
    int rear;
    int front;
    int current_size;
    t* data;

};