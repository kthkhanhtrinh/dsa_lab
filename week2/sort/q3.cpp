// TODO: Write your code here

static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // TODO
    T* left = start + segment_idx;
  
    while(left <= end - cur_segment_total){
        T* tmp = start + segment_idx;
     
        while(tmp <= end - cur_segment_total - 1){
            if(* tmp > * (tmp + cur_segment_total)) swap(*tmp,* (tmp + cur_segment_total));
            tmp += cur_segment_total;
             
        }
        left += cur_segment_total;
       
    }
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    for(int i = num_phases-1; i >= 0; i--){
        for(int j = 0; j < num_segment_list[i];j ++ ){            
            sortSegment(start, end,j , num_segment_list[i]);
          
        }
        cout << num_segment_list[i] << " segments: ";
        // T* tmp = start;
        Sorting<T>::printArray(start,end);
    }
}