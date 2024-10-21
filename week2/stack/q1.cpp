void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(0, item);
}

T pop() {
    // TODO: Remove an element on top of the stack
    T it = list.removeAt(0);
    return it;
}

T top() {
    // TODO: Get value of the element on top of the stack
    T it = list.get(0);
    return it;
}

bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return list.size();
}

void clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}