static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T* arr = start;
    int low = 0;
    int high = end-start-1;
    int i=low, j = high+1;
    int pivot = arr[low];
    do{
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i > j) break;
        swap(arr[i],arr[j]);
    }while(i <= j);
    if(i<=j){
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    cout << j << " ";
    return start+j;
}

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if(start < end){
        T* pivot = Partition(start,end);
        QuickSort(start,pivot);
        QuickSort(pivot+1,end);
    }
}

/////////////////////////////////////////////////////////////
  static void merge(T* left, T* middle, T* right) {
        int n1 = middle - left + 1; // Size of the left half
        int n2 = right - middle;    // Size of the right half

        T* leftArray = new T[n1];
        T* rightArray = new T[n2];

        for (int i = 0; i < n1; i++)
            leftArray[i] = left[i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = middle[1 + j];

        int i = 0, j = 0;
        T* k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                *k = leftArray[i];
                i++;
            } else {
                *k = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            *k = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            *k = rightArray[j];
            j++;
            k++;
        }

        Sorting::printArray(left, right);

        delete[] leftArray;
        delete[] rightArray;
    }
 static void mergeSort(T* start, T* end) {
        if (start < end) {
            T* middle = start + (end - start) / 2;

            mergeSort(start, middle);
            mergeSort(middle + 1, end);

            merge(start, middle, end);
        }
    }
	
/////////////////////////////////////////////////////////////
// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* mergedHead = nullptr;

    if (l1->val <= l2->val) {
        mergedHead = l1;
        mergedHead->next = mergeLists(l1->next, l2);
    } else {
        mergedHead = l2;
        mergedHead->next = mergeLists(l1, l2->next);
    }

    return mergedHead;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    // Base case: if the list is empty or has one element
    if (!head || !head->next) return head;

    // Step 1: Split the list into two halves
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = nullptr; // Split the list into two halves

    // Step 2: Recursively sort each half
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(mid);

    // Step 3: Merge the sorted halves
    return mergeLists(left, right);
}

//////////////////////////////////


static void merge(T* start, T* middle, T* end) {
        int left_size = middle - start;
        int right_size = end - middle;

        // Create temporary arrays to hold the left and right subarrays
        T* left = new T[left_size];
        T* right = new T[right_size];

        for (int i = 0; i < left_size; i++) left[i] = start[i];
        for (int i = 0; i < right_size; i++) right[i] = middle[i];

        int i = 0, j = 0, k = 0;

        // Merge the temporary arrays back into the original array
        while (i < left_size && j < right_size) {
            if (left[i] <= right[j]) {
                start[k++] = left[i++];
            } else {
                start[k++] = right[j++];
            }
        }

        // Copy any remaining elements of left[]
        while (i < left_size) start[k++] = left[i++];

        // Copy any remaining elements of right[]
        while (j < right_size) start[k++] = right[j++];

        // Free memory of temporary arrays
        delete[] left;
        delete[] right;
    }
static void InsertionSort(T* start, T* end) {
        for (T* i = start + 1; i < end; ++i) {
            T key = *i;
            T* j = i - 1;

            // Move elements that are greater than key to one position ahead
            while (j >= start && *j > key) {
                *(j + 1) = *j;
                j--;
            }
            *(j + 1) = key;
        }
    }

 static void TimSort(T* start, T* end, int min_size) {
        int size = end - start;

        // Sort individual subarrays of size min_size
        for (int i = 0; i < size; i += min_size) {
            T* sub_end = (i + min_size < size) ? start + i + min_size : end;
            InsertionSort(start + i, sub_end);
        }
        cout << "Insertion Sort: ";
        printArray(start, end);
        int counter = 1;
        // Merge sorted subarrays using the merge function
        for (int curr_size = min_size; curr_size < size; curr_size *= 2) {
            for (int left_start = 0; left_start < size; left_start += 2 * curr_size) {
                T* left = start + left_start;
                T* mid = (left_start + curr_size < size) ? left + curr_size : end;
                T* right = (left_start + 2 * curr_size < size) ? left + 2 * curr_size : end;

                if (mid < right) {
                    merge(left, mid, right);
                }
                cout << "Merge " << counter++ << ": ";
                printArray(start, end);

            }
        }
    }
	
	
//////////////////////////

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
// Sort rooms and people to use the two-pointer approach
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    
    int i = 0, j = 0, count = 0;
    int m = rooms.size(), n = people.size();
    
    // Use two pointers to try to match people to rooms
    while (i < m && j < n) {
        if (rooms[i] >= people[j] - k && rooms[i] <= people[j] + k) {
            // Room is within acceptable range for this person
            count++;
            i++;
            j++;
        } else if (rooms[i] < people[j] - k) {
            // Room is too small for the current person, try next room
            i++;
        } else {
            // Room is too large for the current person, try next person
            j++;
        }
    }
    
    return count;
}

/////////////////////////////

string minDiffPairs(int* arr, int n) {
    if (n < 2) {
        return "";
    }

    // Sort the array
    std::sort(arr, arr + n);

    // Initialize the minimum difference to a large value
    int min_diff = std::abs(arr[1] - arr[0]);
    int count = 0;
    int pairs[100][2]; // Assuming the array won't have more than 100 pairs

    // Iterate through the array to find the minimum difference
    for (int i = 0; i < n - 1; ++i) {
        int diff = std::abs(arr[i + 1] - arr[i]);
        if (diff < min_diff) {
            min_diff = diff;
            count = 0;
            pairs[count][0] = arr[i];
            pairs[count][1] = arr[i + 1];
            count++;
        } else if (diff == min_diff) {
            pairs[count][0] = arr[i];
            pairs[count][1] = arr[i + 1];
            count++;
        }
    }

    // Convert pairs to a string
    std::ostringstream oss;
    for (int i = 0; i < count; ++i) {
        oss << "(" << pairs[i][0] << ", " << pairs[i][1] << ")";
        if (i < count - 1)
            oss << ", ";
    }
    return oss.str();
}
/////////////////////////////

void sortByFrequency(int arr[], int n) {
    // Step 1: Find unique elements and their frequencies
    int unique[n]; // To store unique elements
    int freq[n];   // To store frequencies of unique elements
    int uniqueCount = 0;

    // Count frequencies of each element
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == unique[j]) {
                freq[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            unique[uniqueCount] = arr[i];
            freq[uniqueCount] = 1; // Initialize frequency to 1
            uniqueCount++;
        }
    }

    // Step 2: Sort unique elements based on their frequencies
    // Using a simple bubble sort for demonstration
    for (int i = 0; i < uniqueCount - 1; ++i) {
        for (int j = 0; j < uniqueCount - i - 1; ++j) {
            if (freq[j] < freq[j + 1]) {
                // Swap frequencies
                std::swap(freq[j], freq[j + 1]);
                // Swap corresponding unique elements
                std::swap(unique[j], unique[j + 1]);
            }
        }
    }

    // Step 3: Create a new array based on sorted frequencies
    int output[n];
    int index = 0;

    // Fill the output array based on the sorted unique elements and their frequencies
    for (int i = 0; i < uniqueCount; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            output[index++] = unique[i];
        }
    }

    // Step 4: Copy the output back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}
