
# Dynamic Stack ADT (ANSI C)

## Data Structure

```c
typedef struct
{
    int *arr;        // Pointer to dynamically allocated memory
    int top;         // Index of the topmost element (-1 when empty)
    int capacity;    // Current allocated capacity
} DynamicStack;
```
## Note: Design choice involves implemeting *arr to avoid object reallocation at runtime.
---

# 1. Creation & Memory Management

---

## 1. createStack()

### Prototype

```c
DynamicStack* createStack(int initialCapacity);
```

### Description

Allocates memory for a new dynamic stack and initializes all members.

### Parameters

* `initialCapacity` – Initial storage capacity.

### Returns

* Pointer to newly created stack.
* `NULL` if allocation fails.

---

## 2. initializeStack()

### Prototype

```c
int initializeStack(DynamicStack *stack, int initialCapacity);
```

### Description

Initializes an already declared stack structure.

### Parameters

* Pointer to stack.
* Initial capacity.

### Returns

* `1` → Success
* `0` → Failure

---

## 3. destroyStack()

### Prototype

```c
void destroyStack(DynamicStack *stack);
```

### Description

Frees all allocated memory associated with the stack.

### Parameters

* Pointer to stack.

### Returns

* Nothing.

---

## 4. clearStack()

### Prototype

```c
void clearStack(DynamicStack *stack);
```

### Description

Removes every element without releasing allocated memory.

### Returns

* Nothing.

---

# 2. Capacity Management

---

## 5. resizeStack()

### Prototype

```c
int resizeStack(DynamicStack *stack, int newCapacity);
```

### Description

Changes the storage capacity of the stack.

Usually called automatically whenever the stack becomes full.

### Parameters

* Pointer to stack.
* New capacity.

### Returns

* `1` → Success
* `0` → Failure

---

## 6. reserveCapacity()

### Prototype

```c
int reserveCapacity(DynamicStack *stack, int capacity);
```

### Description

Pre-allocates memory for future push operations.

---

## 7. shrinkToFit()

### Prototype

```c
int shrinkToFit(DynamicStack *stack);
```

### Description

Shrinks allocated memory so that

```
capacity == size
```

---

# 3. Stack Status Functions

---

## 8. isEmpty()

### Prototype

```c
int isEmpty(DynamicStack *stack);
```

### Description

Checks whether the stack contains no elements.

### Returns

* `1`
* `0`

---

## 9. isFull()

### Prototype

```c
int isFull(DynamicStack *stack);
```

### Description

Checks whether the stack has reached its current capacity.

---

## 10. getSize()

### Prototype

```c
int getSize(DynamicStack *stack);
```

### Description

Returns number of stored elements.

---

## 11. getCapacity()

### Prototype

```c
int getCapacity(DynamicStack *stack);
```

### Description

Returns allocated capacity.

---

# 4. Core Stack Operations

---

## 12. push()

### Prototype

```c
int push(DynamicStack *stack, int value);
```

### Description

Pushes a new element onto the top of the stack.

If the stack is full, automatically resizes it.

### Parameters

* Pointer to stack.
* Value to insert.

### Returns

* `1`
* `0`

---

## 13. pop()

### Prototype

```c
int pop(DynamicStack *stack);
```

### Description

Removes and returns the top element.

### Returns

* Removed value.
* Error value if empty.

---

## 14. peek()

### Prototype

```c
int peek(DynamicStack *stack);
```

### Description

Returns the top element without removing it.


# 5. Traversal

---

## 15. display()

### Prototype

```c
void display(DynamicStack *stack);
```

### Description

Displays stack contents from top to bottom.

---

## 16. displayReverse()

### Prototype

```c
void displayReverse(DynamicStack *stack);
```

### Description

Displays stack from bottom to top.

---

# 6. Utility Operations

---

## 17. copyStack()

### Prototype

```c
DynamicStack* copyStack(DynamicStack *stack);
```

### Description

Creates a deep copy of the stack.

---

## 18. compareStacks()

### Prototype

```c
int compareStacks(DynamicStack *a, DynamicStack *b);
```

### Description

Checks whether two stacks are identical.

---

## 19. swapStacks()

### Prototype

```c
void swapStacks(DynamicStack *a, DynamicStack *b);
```

### Description

Exchanges the contents of two stacks.

---

## 20. reverseStack()

### Prototype

```c
void reverseStack(DynamicStack *stack);
```

### Description

Reverses the order of all elements.

---

# 7. Searching

---

## 21. search()

### Prototype

```c
int search(DynamicStack *stack, int value);
```

### Description

Searches for a value from the top of the stack.

### Returns

* Position from top.
* `-1` if absent.

---

## 22. contains()

### Prototype

```c
int contains(DynamicStack *stack, int value);
```

### Description

Checks if an element exists.

---

## 23. countOccurrences()

### Prototype

```c
int countOccurrences(DynamicStack *stack, int value);
```

### Description

Counts occurrences of a value.

---

# 8. Mathematical Operations

---

## 24. max()

### Prototype

```c
int max(DynamicStack *stack);
```

Returns largest element.

---

## 25. min()

### Prototype

```c
int min(DynamicStack *stack);
```

Returns smallest element.

---

## 26. sum()

### Prototype

```c
long long sum(DynamicStack *stack);
```

Returns sum of all elements.

---

## 27. average()

### Prototype

```c
double average(DynamicStack *stack);
```

Returns arithmetic mean.

---

# 9. Validation & Debugging

---

## 28. validateStack()

### Prototype

```c
int validateStack(DynamicStack *stack);
```

### Description

Verifies the internal consistency of the stack.

Checks that:

* `top >= -1`
* `top < capacity`
* Pointer is valid
* Capacity is positive

---

## 29. printInfo()

### Prototype

```c
void printInfo(DynamicStack *stack);
```

### Description

Prints diagnostic information, including:

* Current size
* Capacity
* Top index
* Memory usage
* Load factor

---

# 30. Optional Advanced Operations



---

## 31. mergeStacks()

```c
DynamicStack* mergeStacks(DynamicStack *a, DynamicStack *b);
```

Creates a new stack by combining two existing stacks while preserving order.

---

## 32. moveTop()

```c
int moveTop(DynamicStack *source, DynamicStack *destination);
```

Removes the top element from one stack and pushes it onto another.

---

## 33. duplicateTop()

```c
int duplicateTop(DynamicStack *stack);
```

Duplicates the current top element.

Example:

```
Before:
10
20
30

After:
10
20
30
30
```

---

## 34. swapTop()

```c
int swapTop(DynamicStack *stack);
```

Swaps the top two elements.

---

## 35. rotateTop()

```c
int rotateTop(DynamicStack *stack, int k);
```

Rotates the top `k` elements of the stack.

---

## 36. trimUnusedMemory()

```c
int trimUnusedMemory(DynamicStack *stack);
```

Shrinks unused allocated memory when the stack has many free slots.

