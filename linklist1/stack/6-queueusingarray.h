template <typename T>

class queueusingarray
{
    T *data;
    int nextindex;
    int frontindex;
    int size;
    int capacity;
public:
    queueusingarray(int s)
    {
        data = new T[s];
        nextindex = 0;
        frontindex = -1;
        size = 0;
        capacity = s;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "queue is full:" << endl;
            return;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        if (frontindex == -1)
        {
            frontindex = 0;
        }
        size++;
    }
    T dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        T ans = data[frontindex];
        frontindex = (frontindex + 1) % capacity;
        size--;
        return ans;
    }
    T front()
    {
        return data[frontindex];
    }
};