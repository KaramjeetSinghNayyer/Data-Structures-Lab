#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *arr;
    int size;
    int capacity;
} DynamicArray;

//creating a dynamic array with initial capacity

DynamicArray* createArray(int initialCapacity){
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->arr = (int*)malloc(initialCapacity * sizeof(int));
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

//destroying the dynamic array and freeing memory
void destroyArray(DynamicArray *da){
    free(da->arr);
    free(da);
}

//clear the dynamic array and reset its size to 0, but keep the allocated memory for future use
void clear(DynamicArray *da){
    da->size = 0;
    // Optionally, you can also reset the capacity if needed, but here we keep it as is for future use.
}



//resize the dynamic array to a new capacity
//returns 1 on success, -1 on failure and 0 if the new capacity is less than or equal to the current capacity

int resize(DynamicArray *da, int newCapacity){
    if (newCapacity <= da->capacity) {
        return 0; // No need to resize if the new capacity is less than or equal to current capacity
    }

    int *newArr = (int*)realloc(da->arr, newCapacity * sizeof(int));
    if (newArr == NULL) {
        return -1; // Memory allocation failed
    }

    da->arr = newArr;
    da->capacity = newCapacity;
    return 1; 
}


//makes sure that the array has at least the specified capacity, resizing if necessary
int reserve(DynamicArray *da, int capacity){
    if (capacity > da->capacity) {
        return resize(da, capacity);
    }
    return 0; // No need to reserve if the requested capacity is less than or equal to current capacity
}


//Shrinks the dynamic array to fit its current size, freeing any unused memory
int shrinkToFit(DynamicArray *da){
    if (da->size < da->capacity) {
        return resize(da, da->size);
    }
    return 0; // No need to shrink if the size is equal to the capacity
}

//returns 1 if the dynamic array is empty, 0 otherwise
int isEmpty(DynamicArray *da){
    return da->size == 0;
}

//returns 1 if the dynamic array is full, 0 otherwise
int isFull(DynamicArray *da){
    return da->size == da->capacity;    
}

//returns the current size of the dynamic array
int getSize(DynamicArray *da){
    return da->size;
}

//returns the current capacity of the dynamic array
int getCapacity(DynamicArray *da){
    return da->capacity;
}   


// Returns the element at the specified index.
int get(DynamicArray *da, int index){
    
    if (index < 0 || index >= da->size) {
        printf("Index out of bounds\n");
        return -1; // Return an error value or handle the error as needed
    }
    return da->arr[index];
}

// Sets the element at the specified index to the given value.
int set(DynamicArray *da, int index, int value){
    if (index < 0 || index >= da->size) {
        printf("Index out of bounds\n");
        return -1; // Return an error value or handle the error as needed
    }
    da->arr[index] = value;
    return 0; // Success
}

// Returns the first element of the dynamic array.
int front(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    return da->arr[0];
}

// Returns the last element of the dynamic array.
int back(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    return da->arr[da->size - 1];
}   

// Returns a pointer to the underlying array of the dynamic array.
int* data(DynamicArray *da){
    return da->arr;
}

// Adds an element to the end of the dynamic array, resizing if necessary.
int pushBack(DynamicArray *da, int value){
    if (isFull(da)) {
        int result = resize(da, da->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Memory allocation failed
        }
    }
    da->arr[da->size] = value;
    da->size++;
    return 0; // Success
}

// Adds an element to the front of the dynamic array, resizing if necessary.
int pushFront(DynamicArray *da, int value){
    if (isFull(da)) {
        int result = resize(da, da->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Memory allocation failed
        }
    }
    // Shift elements to the right to make space at the front
    for (int i = da->size; i > 0; i--) {
        da->arr[i] = da->arr[i - 1];
    }
    da->arr[0] = value;
    da->size++;
    return 0; // Success
}



int insertAt(DynamicArray *da, int index, int value){
    if (index < 0 || index > da->size) {
        printf("Index out of bounds\n");
        return -1; // Return an error value or handle the error as needed
    }
    if (isFull(da)) {
        int result = resize(da, da->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Memory allocation failed
        }
    }
    // Shift elements to the right to make space at the specified index
    for (int i = da->size; i > index; i--) {
        da->arr[i] = da->arr[i - 1];
    }
    da->arr[index] = value;
    da->size++;
    return 0; // Success
}


// Inserts an element into the dynamic array while maintaining sorted order.
int insertSorted(DynamicArray *da, int value){
    // Find the correct position to insert the value to maintain sorted order
    int index = 0;
    while (index < da->size && da->arr[index] < value) {
        index++;
    }
    return insertAt(da, index, value);
}


// Removes the last element from the dynamic array, resizing if necessary.
int popBack(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    da->size--;
    return 0; // Success
}

// Removes the first element from the dynamic array, resizing if necessary.
int popFront(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    // Shift elements to the left to remove the first element
    for (int i = 0; i < da->size - 1; i++) {
        da->arr[i] = da->arr[i + 1];
    }
    da->size--;
    return 0; // Success
}

// Removes the element at the specified index from the dynamic array, resizing if necessary.
int eraseAt(DynamicArray *da, int index){
    if (index < 0 || index >= da->size) {
        printf("Index out of bounds\n");
        return -1; // Return an error value or handle the error as needed
    }
    // Shift elements to the left to remove the element at the specified index
    for (int i = index; i < da->size - 1; i++) {
        da->arr[i] = da->arr[i + 1];
    }
    da->size--;
    return 0; // Success
}

// Removes a range of elements from the dynamic array, resizing if necessary.
int eraseRange(DynamicArray *da, int start, int end){
    if (start < 0 || end >= da->size || start > end) {
        printf("Invalid range\n");
        return -1; // Return an error value or handle the error as needed
    }
    int rangeSize = end - start + 1;
    // Shift elements to the left to remove the specified range
    for (int i = start; i < da->size - rangeSize; i++) {
        da->arr[i] = da->arr[i + rangeSize];
    }
    da->size -= rangeSize;
    return 0; // Success
}


// Removes the first occurrence of the specified value from the dynamic array, resizing if necessary.
int removeValue(DynamicArray *da, int value){
    int index = -1;
    // Find the index of the value to be removed
    for (int i = 0; i < da->size; i++) {
        if (da->arr[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Value not found\n");
        return -1; // Value not found
    }
    return eraseAt(da, index); // Remove the value at the found index
}


// Searches for the specified value in the dynamic array and returns its index, or -1 if not found.
int linearSearch(DynamicArray *da, int value){
    for (int i = 0; i < da->size; i++) {
        if (da->arr[i] == value) {
            return i; // Return the index of the found value
        }
    }
    return -1; // Value not found
}


// Searches for the specified value in the dynamic array using binary search and returns its index, or -1 if not found.
int binarySearch(DynamicArray *da, int value){
    int left = 0;
    int right = da->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (da->arr[mid] == value) {
            return mid; // Value found at index mid
        } else if (da->arr[mid] < value) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Value not found
}


// Displays the elements of the dynamic array.
void display(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return;
    }
    printf("Dynamic Array: ");
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->arr[i]);
    }
    printf("\n");
}


// Displays the elements of the dynamic array in reverse order.
void printReverse(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return;
    }
    printf("Dynamic Array in Reverse: ");
    for (int i = da->size - 1; i >= 0; i--) {
        printf("%d ", da->arr[i]);
    }
    printf("\n");
}

// Reverses the elements of the dynamic array in place.
void reverse(DynamicArray *da){
    //swaping the elements using 2 pointer approach 
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return;
    }
    int start = 0;
    int end = da->size - 1;
    while (start < end) {
        // Swap elements at start and end
        int temp = da->arr[start];
        da->arr[start] = da->arr[end];
        da->arr[end] = temp;
        start++;
        end--;
    }
}

// Rotates the elements of the dynamic array to the left by the specified number of positions.
void rotateLeft(DynamicArray *da, int positions){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return;
    }
    positions = positions % da->size; // Handle cases where positions > size
    if (positions == 0) {
        return; // No rotation needed
    }

    // Create a temporary array to hold the rotated elements
    int *temp = (int*)malloc(da->size * sizeof(int));
    for (int i = 0; i < da->size; i++) {
        temp[i] = da->arr[(i + positions) % da->size];
    }

    // Copy the rotated elements back to the original array
    for (int i = 0; i < da->size; i++) {
        da->arr[i] = temp[i];
    }

    free(temp); // Free the temporary array
}


// Rotates the elements of the dynamic array to the right by the specified number of positions.
void rotateRight(DynamicArray *da, int positions){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return;
    }
    positions = positions % da->size; // Handle cases where positions > size
    if (positions == 0) {
        return; // No rotation needed
    }

    // Create a temporary array to hold the rotated elements
    int *temp = (int*)malloc(da->size * sizeof(int));
    for (int i = 0; i < da->size; i++) {
        temp[i] = da->arr[(i - positions + da->size) % da->size];
    }

    // Copy the rotated elements back to the original array
    for (int i = 0; i < da->size; i++) {
        da->arr[i] = temp[i];
    }

    free(temp); // Free the temporary array
}

// Creates a copy of the dynamic array and returns a pointer to the new array.
DynamicArray* copy(DynamicArray *da){
    DynamicArray* newArray = createArray(da->capacity);
    if (newArray == NULL) {
        return NULL; // Memory allocation failed
    }
    newArray->size = da->size;
    for (int i = 0; i < da->size; i++) {
        newArray->arr[i] = da->arr[i];
    }
    return newArray;
}


// Compares two dynamic arrays for equality. Returns 1 if they are equal, 0 otherwise.
int compare(DynamicArray *a, DynamicArray *b){
    if (a->size != b->size) {
        return 0; // Arrays are not equal if sizes differ
    }
    for (int i = 0; i < a->size; i++) {
        if (a->arr[i] != b->arr[i]) {
            return 0; // Arrays are not equal if any element differs
        }
    }
    return 1; // Arrays are equal
}


// Concatenates the elements of the source dynamic array to the destination dynamic array, resizing if necessary.
int concatenate(DynamicArray *dest, DynamicArray *src){
    if (dest->size + src->size > dest->capacity) {
        int result = resize(dest, dest->size + src->size); // Resize to accommodate new elements
        if (result == -1) {
            return -1; // Memory allocation failed
        }
    }
    for (int i = 0; i < src->size; i++) {
        dest->arr[dest->size + i] = src->arr[i];
    }
    dest->size += src->size;
    return 0; // Success
}

// Merges two dynamic arrays into a new dynamic array and returns a pointer to the merged array.
DynamicArray* merge(DynamicArray *a, DynamicArray *b){
    DynamicArray* mergedArray = createArray(a->size + b->size);
    if (mergedArray == NULL) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i < a->size; i++) {
        mergedArray->arr[i] = a->arr[i];
    }
    for (int i = 0; i < b->size; i++) {
        mergedArray->arr[a->size + i] = b->arr[i];
    }
    mergedArray->size = a->size + b->size;
    return mergedArray;
}

// Sorts the elements of the dynamic array in ascending order using bubble sort.
void sortAscending(DynamicArray *da){
    // Implementing a simple bubble sort 
    for (int i = 0; i < da->size - 1; i++) {
        for (int j = 0; j < da->size - i - 1; j++) {
            if (da->arr[j] > da->arr[j + 1]) {
                // Swap elements
                int temp = da->arr[j];
                da->arr[j] = da->arr[j + 1];
                da->arr[j + 1] = temp;
            }
        }
    }
}

// Sorts the elements of the dynamic array in descending order using bubble sort.
void sortDescending(DynamicArray *da){
    // Implementing a simple bubble sort 
    for (int i = 0; i < da->size - 1; i++) {
        for (int j = 0; j < da->size - i - 1; j++) {
            if (da->arr[j] < da->arr[j + 1]) {
                // Swap elements
                int temp = da->arr[j];
                da->arr[j] = da->arr[j + 1];
                da->arr[j + 1] = temp;
            }
        }
    }
}

int isSorted(DynamicArray *da){
    if (da->size < 2) {
        return 1; // An array with 0 or 1 element is considered sorted
    }
    int ascending = 1;
    int descending = 1;

    for (int i = 1; i < da->size; i++) {
        if (da->arr[i] < da->arr[i - 1]) {
            ascending = 0; // Not sorted in ascending order
        }
        if (da->arr[i] > da->arr[i - 1]) {
            descending = 0; // Not sorted in descending order
        }
    }

    return ascending || descending; // Return 1 if sorted in either order, otherwise return 0
}

// Returns the maximum element in the dynamic array.
int max(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    int maxValue = da->arr[0];
    for (int i = 1; i < da->size; i++) {
        if (da->arr[i] > maxValue) {
            maxValue = da->arr[i];
        }
    }
    return maxValue;
}

// Returns the minimum element in the dynamic array.
int min(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    int minValue = da->arr[0];
    for (int i = 1; i < da->size; i++) {
        if (da->arr[i] < minValue) {
            minValue = da->arr[i];
        }
    }
    return minValue;
}

// Returns the sum of all elements in the dynamic array.
long long sum(DynamicArray *da){
    
    long long total = 0;
    for (int i = 0; i < da->size; i++) {
        total += da->arr[i];
    }
    return total;
}

// Returns the average of all elements in the dynamic array.
double average(DynamicArray *da){
    if (isEmpty(da)) {
        printf("Array is empty\n");
        return 0.0; // Return an error value or handle the error as needed
    }
    long long total = sum(da);
    return (double)total / da->size;
}   


// Displays information about the dynamic array, including size, capacity, and statistics about its elements.
void printInfo(DynamicArray *da){
    printf("Dynamic Array Info:\n");
    printf("Size: %d\n", da->size);
    printf("Capacity: %d\n", da->capacity);
    if (!isEmpty(da)) {
        printf("First Element: %d\n", front(da));
        printf("Last Element: %d\n", back(da));
        printf("Maximum Element: %d\n", max(da));
        printf("Minimum Element: %d\n", min(da));
        printf("Sum of Elements: %lld\n", sum(da));
        printf("Average of Elements: %.2f\n", average(da));
    } else {
        printf("The array is empty, no elements to display.\n");
    }
}


int main(){
    DynamicArray *da = createArray(5);
    insertAt(da, 0, 10);
    insertAt(da, 1, 20);
    insertAt(da, 2, 30);
    printInfo(da);
    destroyArray(da);
    return 0;
}