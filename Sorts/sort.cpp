#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
// #define vi vector<int>
#define endl '\n'


// Display Array
void displayArr(int n, vector<int> &arr) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
} 

// This function is used to find the pivot in Quick Sort
int findPivot(vector<int> &arr, int low, int high) {
    int left = low;
    int right = high;
    int pivot = arr[low];
    while (left < right) {
        while(arr[left] <= pivot && left <= high - 1) {
            left++;
        }

        while(arr[right] >= pivot && right >= low + 1) {
            right--;
        }

        if(left < right) {
            swap(arr[left],arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}
// quick sort
void quickSorting(vector<int> &arr, int low, int high) {
    if(low < high) {
        int partitionIndex = findPivot(arr,low,high);
        quickSorting(arr,low,partitionIndex-1);
        quickSorting(arr,partitionIndex+1,high);
    }

}
// quick sort
void quickSort() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &ele : arr) {
        cin >> ele;
    }


    quickSorting(arr,0,n-1);

    // display array
    displayArr(n,arr);
}
// merge 2 sorted array
void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high) {
        if(arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }


    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }


    while (right <= high) 
    {
        temp.push_back(arr[right]);
        right++;
    }
    

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    
}
// merge sort
void mergeSorting(vector<int> &arr, int low, int high) {
    if(low >= high) return;

    // calculate mid
    int mid = low + (high - low) / 2;
    mergeSorting(arr,low,mid);
    mergeSorting(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &ele : arr) {
        cin >> ele;
    }


    mergeSorting(arr,0,n-1);

    // display array
    displayArr(n,arr);

}

// insertion sort
void insertionSort() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &ele : arr) {
        cin >> ele;
    }

    for(int i = 1; i <= n-1; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
       
    }
    // display array
    displayArr(n,arr);
}
// selection sort
void selectionSort() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &ele : arr) {
        cin >> ele;
    }

    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

     // display array
    displayArr(n,arr);

}
// bubble sort
void bubbleSort() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &ele : arr) {
        cin >> ele;
    }

    // swap adj elements
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j+1] < arr[j]) {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }    
    // display array
    displayArr(n,arr);
    
}

int main() {
    fastio;

    // ✅ Local file I/O for practice (ignored by online judges)
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t; // Uncomment if your problem has multiple test cases
    while (t--) {
        // bubbleSort();
        // selectionSort();
        // insertionSort();
        // mergeSort();
        // quickSort();
    }

    return 0;
}
