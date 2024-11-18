//HEAP
template<class T>
int Heap<T>::size(){
    return count;
    
}

template<class T>
bool Heap<T>::isEmpty(){
    return count == 0;
    
}

template<class T>
T Heap<T>::peek(){
    if (isEmpty())
        return -1;
        
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i = 0; i < count; i++)
        if(elements[i] == item)
            return true;
    
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(isEmpty())
        return false;
    elements[0] = elements[count - 1];
    count--;

    reheapDown(0);

    return true; 
}
/////////////////////////////////////////////////
template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
    elements[count] = item;
    
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity <= capacity) {
        return;
    }

    int newCapacity = max(capacity * 2, minCapacity);

    T* newElements = new T[newCapacity];

    for (int i = 0; i < count; ++i) {
        newElements[i] = elements[i];
    }

    delete[] elements;
    elements = newElements;

    capacity = newCapacity;
}

template<class T>
void Heap<T>::reheapUp(int position){
    int parent = (position - 1) / 2; 

    while (position > 0 && elements[position] > elements[parent]) {
        swap(elements[position], elements[parent]);

        position = parent;
        parent = (position - 1) / 2;
    }
}
/////////////////////////////////////////////////
void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int largest = index;              
    int leftChild = 2 * index + 1;     
    int rightChild = 2 * index + 2;     

    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largest]) {
        largest = leftChild;
    }

    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(maxHeap[index], maxHeap[largest]); 
        reheapDown(maxHeap, numberOfElements, largest); 
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    int parent = (index - 1) / 2; 

    while (index > 0 && maxHeap[index] > maxHeap[parent]) {
        swap(maxHeap[index], maxHeap[parent]); 
        index = parent;                        
        parent = (index - 1) / 2;              
    }
}
/////////////////////////////////////////////////
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++)
        if(elements[i] == item)
            return i;
    
    return -1;
    
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if(index == -1)
        return;
    
    elements[index] = elements[count - 1];
    count--; 

    reheapDown(index);
    reheapUp(index);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] elements;         
    elements = new T[capacity];  
    count = 0;       
}
/////////////////////////////////////////////////
static void heapSort(T* start, T* end) {
    int size = end - start;

    for (int i = (size / 2) - 1; i >= 0; --i) {
        heapify(start, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        swap(start[0], start[i]);

        heapify(start, i, 0);
    }

    Sorting<T>::printArray(start, end);
}

static void heapify(T* array, int size, int index) {
    int largest = index;         
    int leftChild = 2 * index + 1; 
    int rightChild = 2 * index + 2; 

    if (leftChild < size && array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(array[index], array[largest]); 
        heapify(array, size, largest);
    }
}

/////////////////////////////////////////////////
int leastAfter(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());

    for (int i = 0; i < k; ++i) {
        int smallest = minHeap.top();  
        minHeap.pop(); 
        minHeap.push(smallest * 2);   
    }

    return minHeap.top(); 
}
/////////////////////////////////////////////////
#include <queue>

struct PrintRequest {
    int priority;    
    string fileName; 
    int id;          

    bool operator<(const PrintRequest& other) const {
        if (priority == other.priority) {
            return id > other.id; 
        }
        return priority < other.priority; 
    }
};

class PrinterQueue {
private:
    priority_queue<PrintRequest> requestQueue;
    int requestCounter = 0;                  

public:
    void addNewRequest(int priority, string fileName) {
        requestQueue.push({priority, fileName, requestCounter++});
    }

    void print() {
        if (requestQueue.empty()) {
            cout << "No file to print" << endl;
            return;
        }

        PrintRequest nextRequest = requestQueue.top();
        requestQueue.pop();

        cout << nextRequest.fileName << endl;
    }
};
/////////////////////////////////////////////////

/////////////////////////////////////////////////
