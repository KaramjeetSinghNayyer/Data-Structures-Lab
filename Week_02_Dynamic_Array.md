# Dynamic Array ADT (ANSI C)

This document defines the interface for a **Dynamic Array Abstract Data
Type (ADT)** to be implemented in ANSI C.

------------------------------------------------------------------------

# Data Structure

``` c
typedef structDynamic Array ADT (ANSI C)

This document defines the interface for a Dynamic Array Abstract DataType (ADT) to be implemented in ANSI C.

Data Structure

typedef struct
{
    int *arr;
    int size;
    int capacity;
} DynamicArray;

1. Creation & Memory Management

1. createArray(int initialCapacity)

Prototype

DynamicArray* createArray(int initialCapacity);

Description: Allocates memory for a new dynamic array andinitializes its members.

Parameters - initialCapacity -- Initial storage capacity.

Returns - Pointer to the created DynamicArray. - NULL if allocation fails.

2. destroyArray(DynamicArray *da)

void destroyArray(DynamicArray *da);

Releases all memory allocated for the dynamic array.

Parameters - da -- Pointer to the dynamic array.

Returns - void

3. clear(DynamicArray *da)

void clear(DynamicArray *da);

Removes all elements while retaining the allocated memory.

2. Capacity Management

4. resize(DynamicArray *da, int newCapacity)

int resize(DynamicArray *da, int newCapacity);

Changes the array capacity.

Parameters - da -- Dynamic array. - newCapacity -- Desiredcapacity.

Returns - 1 on success. - 0 on failure.

5. reserve(DynamicArray *da, int capacity)

int reserve(DynamicArray *da, int capacity);

Ensures that the array has at least the specified capacity.

6. shrinkToFit(DynamicArray *da)

int shrinkToFit(DynamicArray *da);

Shrinks the allocated capacity to match the current size.

3. Status Functions

7. isEmpty(DynamicArray *da)

int isEmpty(DynamicArray *da);

Returns 1 if the array is empty, otherwise 0.

8. isFull(DynamicArray *da)

int isFull(DynamicArray *da);

Returns 1 if the array has reached its capacity.

9. getSize(DynamicArray *da)

int getSize(DynamicArray *da);

Returns the current number of stored elements.

10. getCapacity(DynamicArray *da)

int getCapacity(DynamicArray *da);

Returns the current allocated capacity.

4. Element Access

int get(DynamicArray *da, int index); --- Returns the element atthe specified index.

int set(DynamicArray *da, int index, int value); --- Updates thevalue stored at the specified index.

int front(DynamicArray *da); --- Returns the first element.

int back(DynamicArray *da); --- Returns the last element.

int* data(DynamicArray *da); --- Returns the pointer to the internal array.

5. Insertion Operations

int pushBack(DynamicArray *da, int value); --- Inserts an elementat the end of the array.

int pushFront(DynamicArray *da, int value); --- Inserts an elementat the beginning.

int insertAt(DynamicArray *da, int index, int value); --- Insertsan element at the specified index.

int insertSorted(DynamicArray *da, int value); --- Inserts anelement while maintaining sorted order.

6. Deletion Operations

int popBack(DynamicArray *da); --- Removes and returns the lastelement.

int popFront(DynamicArray *da); --- Removes and returns the firstelement.

int eraseAt(DynamicArray *da, int index); --- Deletes the elementat the given index.

int eraseRange(DynamicArray *da, int start, int end); --- Deletes a range of elements.

int removeValue(DynamicArray *da, int value); --- Removes thefirst occurrence of a value.

int removeAll(DynamicArray *da, int value); --- Removes everyoccurrence of a value.

7. Searching

int linearSearch(DynamicArray *da, int value); --- Performs linearsearch.

int binarySearch(DynamicArray *da, int value); --- Performs binarysearch on a sorted array.

int contains(DynamicArray *da, int value); --- Checks whether avalue exists.

int countOccurrences(DynamicArray *da, int value); --- Counts theoccurrences of a value.

8. Traversal

void display(DynamicArray *da); --- Displays all elements.

void printReverse(DynamicArray *da); --- Displays elements inreverse order.

9. Utility Operations

void reverse(DynamicArray *da);

void rotateLeft(DynamicArray *da, int positions);

void rotateRight(DynamicArray *da, int positions);

DynamicArray* copy(DynamicArray *da);

int compare(DynamicArray *a, DynamicArray *b);

int concatenate(DynamicArray *dest, DynamicArray *src);

DynamicArray* merge(DynamicArray *a, DynamicArray *b);

void unique(DynamicArray *da);

10. Sorting

void sortAscending(DynamicArray *da);

void sortDescending(DynamicArray *da);

int isSorted(DynamicArray *da);

11. Mathematical Operations

int max(DynamicArray *da);

int min(DynamicArray *da);

long long sum(DynamicArray *da);

double average(DynamicArray *da);

12. Validation & Debugging

int validateIndex(DynamicArray *da, int index);

void printInfo(DynamicArray *da);Dynamic Array ADT (ANSI C)

This document defines the interface for a Dynamic Array Abstract DataType (ADT) to be implemented in ANSI C.

Data Structure

typedef struct
{
    int *arr;
    int size;
    int capacity;
} DynamicArray;

1. Creation & Memory Management

1. createArray(int initialCapacity)

Prototype

DynamicArray* createArray(int initialCapacity);

Description: Allocates memory for a new dynamic array andinitializes its members.

Parameters - initialCapacity -- Initial storage capacity.

Returns - Pointer to the created DynamicArray. - NULL if allocation fails.

2. destroyArray(DynamicArray *da)

void destroyArray(DynamicArray *da);

Releases all memory allocated for the dynamic array.

Parameters - da -- Pointer to the dynamic array.

Returns - void

3. clear(DynamicArray *da)

void clear(DynamicArray *da);

Removes all elements while retaining the allocated memory.

2. Capacity Management

4. resize(DynamicArray *da, int newCapacity)

int resize(DynamicArray *da, int newCapacity);

Changes the array capacity.

Parameters - da -- Dynamic array. - newCapacity -- Desiredcapacity.

Returns - 1 on success. - 0 on failure.

5. reserve(DynamicArray *da, int capacity)

int reserve(DynamicArray *da, int capacity);

Ensures that the array has at least the specified capacity.

6. shrinkToFit(DynamicArray *da)

int shrinkToFit(DynamicArray *da);

Shrinks the allocated capacity to match the current size.

3. Status Functions

7. isEmpty(DynamicArray *da)

int isEmpty(DynamicArray *da);

Returns 1 if the array is empty, otherwise 0.

8. isFull(DynamicArray *da)

int isFull(DynamicArray *da);

Returns 1 if the array has reached its capacity.

9. getSize(DynamicArray *da)

int getSize(DynamicArray *da);

Returns the current number of stored elements.

10. getCapacity(DynamicArray *da)

int getCapacity(DynamicArray *da);

Returns the current allocated capacity.

4. Element Access

int get(DynamicArray *da, int index); --- Returns the element atthe specified index.

int set(DynamicArray *da, int index, int value); --- Updates thevalue stored at the specified index.

int front(DynamicArray *da); --- Returns the first element.

int back(DynamicArray *da); --- Returns the last element.

int* data(DynamicArray *da); --- Returns the pointer to the internal array.

5. Insertion Operations

int pushBack(DynamicArray *da, int value); --- Inserts an elementat the end of the array.

int pushFront(DynamicArray *da, int value); --- Inserts an elementat the beginning.

int insertAt(DynamicArray *da, int index, int value); --- Insertsan element at the specified index.

int insertSorted(DynamicArray *da, int value); --- Inserts anelement while maintaining sorted order.

6. Deletion Operations

int popBack(DynamicArray *da); --- Removes and returns the lastelement.

int popFront(DynamicArray *da); --- Removes and returns the firstelement.

int eraseAt(DynamicArray *da, int index); --- Deletes the elementat the given index.

int eraseRange(DynamicArray *da, int start, int end); --- Deletes a range of elements.

int removeValue(DynamicArray *da, int value); --- Removes thefirst occurrence of a value.

int removeAll(DynamicArray *da, int value); --- Removes everyoccurrence of a value.

7. Searching

int linearSearch(DynamicArray *da, int value); --- Performs linearsearch.

int binarySearch(DynamicArray *da, int value); --- Performs binarysearch on a sorted array.

int contains(DynamicArray *da, int value); --- Checks whether avalue exists.

int countOccurrences(DynamicArray *da, int value); --- Counts theoccurrences of a value.

8. Traversal

void display(DynamicArray *da); --- Displays all elements.

void printReverse(DynamicArray *da); --- Displays elements inreverse order.

9. Utility Operations

void reverse(DynamicArray *da);

void rotateLeft(DynamicArray *da, int positions);

void rotateRight(DynamicArray *da, int positions);

DynamicArray* copy(DynamicArray *da);

int compare(DynamicArray *a, DynamicArray *b);

int concatenate(DynamicArray *dest, DynamicArray *src);

DynamicArray* merge(DynamicArray *a, DynamicArray *b);

void unique(DynamicArray *da);

10. Sorting

void sortAscending(DynamicArray *da);

void sortDescending(DynamicArray *da);

int isSorted(DynamicArray *da);

11. Mathematical Operations

int max(DynamicArray *da);

int min(DynamicArray *da);

long long sum(DynamicArray *da);

double average(DynamicArray *da);

12. Validation & Debugging

int validateIndex(DynamicArray *da, int index);

void printInfo(DynamicArray *da);
{
    int *arr;
    int size;
    int capacity;
} DynamicArray;
```

------------------------------------------------------------------------

# 1. Creation & Memory Management

## 1. `createArray(int initialCapacity)`

``` c
DynamicArray* createArray(int initialCapacity);
```

**Description:** Allocates memory for a new dynamic array and
initializes its members.

**Parameters** - `initialCapacity` -- Initial storage capacity.

**Returns** - Pointer to the created `DynamicArray`. - `NULL` if
allocation fails.

------------------------------------------------------------------------

## 2. `destroyArray(DynamicArray *da)`

``` c
void destroyArray(DynamicArray *da);
```

Releases all memory allocated for the dynamic array.

**Parameters** - `da` -- Pointer to the dynamic array.

**Returns** - `void`

------------------------------------------------------------------------

## 3. `clear(DynamicArray *da)`

``` c
void clear(DynamicArray *da);
```

Removes all elements while retaining the allocated memory.

------------------------------------------------------------------------

# 2. Capacity Management

## 4. `resize(DynamicArray *da, int newCapacity)`

``` c
int resize(DynamicArray *da, int newCapacity);
```

Changes the array capacity.

**Parameters** - `da` - `newCapacity`

**Returns** - `1` on success. - `0` on failure.

## 5. `reserve(DynamicArray *da, int capacity)`

``` c
int reserve(DynamicArray *da, int capacity);
```

Ensures that the array has at least the specified capacity.

## 6. `shrinkToFit(DynamicArray *da)`

``` c
int shrinkToFit(DynamicArray *da);
```

Shrinks the allocated capacity to match the current size.

------------------------------------------------------------------------

# 3. Status Functions

-   `int isEmpty(DynamicArray *da);` --- Returns `1` if the array is
    empty, otherwise `0`.
-   `int isFull(DynamicArray *da);` --- Returns `1` if the array has
    reached its capacity.
-   `int getSize(DynamicArray *da);` --- Returns the current number of
    stored elements.
-   `int getCapacity(DynamicArray *da);` --- Returns the current
    allocated capacity.

------------------------------------------------------------------------

# 4. Element Access

-   `int get(DynamicArray *da, int index);` --- Returns the element at
    the specified index.
-   `int set(DynamicArray *da, int index, int value);` --- Updates the
    value stored at the specified index.
-   `int front(DynamicArray *da);` --- Returns the first element.
-   `int back(DynamicArray *da);` --- Returns the last element.
-   `int* data(DynamicArray *da);` --- Returns the pointer to the
    internal array.

------------------------------------------------------------------------

# 5. Insertion Operations

-   `int pushBack(DynamicArray *da, int value);`
-   `int pushFront(DynamicArray *da, int value);`
-   `int insertAt(DynamicArray *da, int index, int value);`
-   `int insertSorted(DynamicArray *da, int value);`

------------------------------------------------------------------------

# 6. Deletion Operations

-   `int popBack(DynamicArray *da);`
-   `int popFront(DynamicArray *da);`
-   `int eraseAt(DynamicArray *da, int index);`
-   `int eraseRange(DynamicArray *da, int start, int end);`
-   `int removeValue(DynamicArray *da, int value);`
-   `int removeAll(DynamicArray *da, int value);`

------------------------------------------------------------------------

# 7. Searching

-   `int linearSearch(DynamicArray *da, int value);`
-   `int binarySearch(DynamicArray *da, int value);`
-   `int contains(DynamicArray *da, int value);`
-   `int countOccurrences(DynamicArray *da, int value);`

------------------------------------------------------------------------

# 8. Traversal

-   `void display(DynamicArray *da);`
-   `void printReverse(DynamicArray *da);`

------------------------------------------------------------------------

# 9. Utility Operations

-   `void reverse(DynamicArray *da);`
-   `void rotateLeft(DynamicArray *da, int positions);`
-   `void rotateRight(DynamicArray *da, int positions);`
-   `DynamicArray* copy(DynamicArray *da);`
-   `int compare(DynamicArray *a, DynamicArray *b);`
-   `int concatenate(DynamicArray *dest, DynamicArray *src);`
-   `DynamicArray* merge(DynamicArray *a, DynamicArray *b);`
-   `void unique(DynamicArray *da);`

------------------------------------------------------------------------

# 10. Sorting

-   `void sortAscending(DynamicArray *da);`
-   `void sortDescending(DynamicArray *da);`
-   `int isSorted(DynamicArray *da);`

------------------------------------------------------------------------

# 11. Mathematical Operations

-   `int max(DynamicArray *da);`
-   `int min(DynamicArray *da);`
-   `long long sum(DynamicArray *da);`
-   `double average(DynamicArray *da);`

------------------------------------------------------------------------

# 12. Validation & Debugging

-   `int validateIndex(DynamicArray *da, int index);`
-   `void printInfo(DynamicArray *da);`
