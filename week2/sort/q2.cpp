template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T* result = start;
    while(start != end - 1){
        T* min = start;
        T* tmp = start + 1;
        while(tmp != end){
            if(*tmp < * min){
                min = tmp;
            }
            tmp++;
        }
        swap(*start, *min);
        Sorting<T>::printArray(result,end);
        start++;
       
    }
}