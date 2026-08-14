# Dynamic Queue ADT (ANSI C)

This document defines the interface for a Dynamic Queue Abstract Data Type (ADT) implemented using a dynamically allocated circular array.

---

# Data Structure

```c
typedef struct
{
    int *arr;          // Pointer to dynamically allocated array
    int front;         // Index of the front element
    int rear;          // Index of the last element
    int size;          // Current number of elements
    int capacity;      // Allocated capacity
} DynamicQueue;
```

---

# 1. Creation & Memory Management

## 1. `createQueue(int initialCapacity)`

```c
DynamicQueue* createQueue(int initialCapacity);
```

Allocates memory for a new queue and initializes all data members.

**Parameters**
- `initialCapacity` – Initial storage capacity.

**Returns**
- Pointer to the newly created queue.
- `NULL` if memory allocation fails.

---

## 2. `initializeQueue(DynamicQueue *queue, int initialCapacity)`

```c
int initializeQueue(DynamicQueue *queue, int initialCapacity);
```

Initializes an already existing queue structure.

**Returns**
- `1` on success.
- `0` on failure.

---

## 3. `destroyQueue(DynamicQueue *queue)`

```c
void destroyQueue(DynamicQueue *queue);
```

Releases all dynamically allocated memory associated with the queue.

---

## 4. `clearQueue(DynamicQueue *queue)`

```c
void clearQueue(DynamicQueue *queue);
```

Removes all elements without releasing allocated memory.

---

# 2. Capacity Management

## 5. `resizeQueue(DynamicQueue *queue, int newCapacity)`

```c
int resizeQueue(DynamicQueue *queue, int newCapacity);
```

Changes the queue capacity while preserving element order.

---

## 6. `reserveCapacity(DynamicQueue *queue, int capacity)`

```c
int reserveCapacity(DynamicQueue *queue, int capacity);
```

Ensures that the queue has at least the specified capacity.

---

## 7. `shrinkToFit(DynamicQueue *queue)`

```c
int shrinkToFit(DynamicQueue *queue);
```

Reduces capacity to match the current number of stored elements.

---

# 3. Queue Status Functions

## 8. `isEmpty(DynamicQueue *queue)`

```c
int isEmpty(DynamicQueue *queue);
```

Checks whether the queue is empty.

Returns:
- `1` → Empty
- `0` → Not Empty

---

## 9. `isFull(DynamicQueue *queue)`

```c
int isFull(DynamicQueue *queue);
```

Checks whether the queue has reached its current capacity.

---

## 10. `getSize(DynamicQueue *queue)`

```c
int getSize(DynamicQueue *queue);
```

Returns the current number of stored elements.

---

## 11. `getCapacity(DynamicQueue *queue)`

```c
int getCapacity(DynamicQueue *queue);
```

Returns the allocated capacity.

---

# 4. Core Queue Operations

## 12. `enqueue(DynamicQueue *queue, int value)`

```c
int enqueue(DynamicQueue *queue, int value);
```

Inserts an element at the rear of the queue.

Automatically resizes the queue if it becomes full.

Returns:
- `1` → Success
- `0` → Failure

---

## 13. `dequeue(DynamicQueue *queue)`

```c
int dequeue(DynamicQueue *queue);
```

Removes and returns the front element.

Returns an error value if the queue is empty.

---

## 14. `front(DynamicQueue *queue)`

```c
int front(DynamicQueue *queue);
```

Returns the front element without removing it.

---

## 15. `rear(DynamicQueue *queue)`

```c
int rear(DynamicQueue *queue);
```

Returns the last element without removing it.

---

# 5. Traversal

## 16. `displayQueue(DynamicQueue *queue)`

```c
void displayQueue(DynamicQueue *queue);
```

Displays the queue from front to rear.

---

## 17. `displayReverse(DynamicQueue *queue)`

```c
void displayReverse(DynamicQueue *queue);
```

Displays the queue from rear to front.

---

# 6. Searching

## 18. `linearSearch(DynamicQueue *queue, int value)`

```c
int linearSearch(DynamicQueue *queue, int value);
```

Performs linear search on the queue.

Returns:
- Index relative to the front.
- `-1` if not found.

---

## 19. `contains(DynamicQueue *queue, int value)`

```c
int contains(DynamicQueue *queue, int value);
```

Checks whether a value exists in the queue.

Returns:
- `1` → Present
- `0` → Absent

---

## 20. `countOccurrences(DynamicQueue *queue, int value)`

```c
int countOccurrences(DynamicQueue *queue, int value);
```

Counts the number of occurrences of a value.

---

# 7. Utility Operations

## 21. `copyQueue(DynamicQueue *queue)`

```c
DynamicQueue* copyQueue(DynamicQueue *queue);
```

Creates a deep copy of the queue.

---

## 22. `compareQueues(DynamicQueue *a, DynamicQueue *b)`

```c
int compareQueues(DynamicQueue *a, DynamicQueue *b);
```

Checks whether two queues contain identical elements in the same order.

---

## 23. `swapQueues(DynamicQueue *a, DynamicQueue *b)`

```c
void swapQueues(DynamicQueue *a, DynamicQueue *b);
```

Exchanges the contents of two queues.

---

## 24. `reverseQueue(DynamicQueue *queue)`

```c
void reverseQueue(DynamicQueue *queue);
```

Reverses the order of elements in the queue.

---

## 25. `mergeQueues(DynamicQueue *a, DynamicQueue *b)`

```c
DynamicQueue* mergeQueues(DynamicQueue *a, DynamicQueue *b);
```

Creates a new queue containing the elements of both queues.

---

# 8. Mathematical Operations

## 26. `max(DynamicQueue *queue)`

```c
int max(DynamicQueue *queue);
```

Returns the maximum element.

---

## 27. `min(DynamicQueue *queue)`

```c
int min(DynamicQueue *queue);
```

Returns the minimum element.

---

## 28. `sum(DynamicQueue *queue)`

```c
long long sum(DynamicQueue *queue);
```

Returns the sum of all elements.

---

## 29. `average(DynamicQueue *queue)`

```c
double average(DynamicQueue *queue);
```

Returns the arithmetic mean.

---

# 9. Validation & Debugging

## 30. `validateQueue(DynamicQueue *queue)`

```c
int validateQueue(DynamicQueue *queue);
```

Checks whether the internal state of the queue is valid.

Verifies:
- `size >= 0`
- `capacity > 0`
- `front` and `rear` indices are within bounds
- Internal pointer is valid

---

## 31. `printInfo(DynamicQueue *queue)`

```c
void printInfo(DynamicQueue *queue);
```

Displays diagnostic information such as:
- Current size
- Capacity
- Front index
- Rear index
- Memory usage
- Load factor

---

# 10. Optional Advanced Operations

## 32. `rotateLeft(DynamicQueue *queue, int positions)`

Rotates the queue towards the front.

---

## 33. `rotateRight(DynamicQueue *queue, int positions)`

Rotates the queue towards the rear.

---

## 34. `moveFront(DynamicQueue *source, DynamicQueue *destination)`

Removes the front element from one queue and enqueues it into another.

---

## 35. `trimUnusedMemory(DynamicQueue *queue)`

Shrinks unused allocated memory.

---

## 36. `unique(DynamicQueue *queue)`

Removes duplicate elements while preserving queue order.

---

