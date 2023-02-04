#include <iostream>
using namespace std;

void merge(int *nums, int p, int q, int r) {
    // determine length of 2 subarrays
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2]; // initialize left and right subarray
    
    // store corresponding values to subarrays
    for (int i = 0; i < n1; i++)
        L[i] = nums[p + i];
    
    for (int j = 0; j < n2; j++)
        R[j] = nums[q + j + 1];
    
    // initialize indices
    int i = 0, j = 0;
    
    // for every element in array[p..r]
    for (int k = p; k <= r; k++) {
        // if all elements in 2nd subarray is inserted or
        // if current element in first subarray is less than current element in second subarray
        if (j == n2 || (L[i] <= R[j] && i < n1)) {
            nums[k] = L[i]; // set the current element of first subarray to current element of original array
            i++; // move to next element in first subarray
        }
        // if there are still elements in 2nd subarray
        // and current element at second subarray is less than current element in first subarray
        else if (i == n1 || j < n2) {
            nums[k] = R[j]; // // set the current element of second subarray to current element of original array
            j++; // move to next element in second subarray
        }
    }
    //}
}
void mergeSort(int *nums, int p, int r) {
    if (p < r) { // n != 1
        int q = (p + r) / 2; // get midpoint
        mergeSort(nums, p, q); // sort first half recursively
        mergeSort(nums, q + 1, r); //sort second half recursively
        merge(nums, p, q, r); // merge
    } // n == 1, done.
}

int main() {
  int n = 6;
  int nums[n];
  
  cout << "Unsorted List: ";
  for (int i = 0; i < n; i++)
    cin >> nums[i];
   
  mergeSort(nums, 0, n - 1);

  cout << "Sorted List: ";
  for (int num: nums)
    cout << num << " ";
    
  return 0;
}

