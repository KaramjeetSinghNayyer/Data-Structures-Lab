#include<stdio.h>

//defining the structure for dynamic stack
typedef struct
{
    int *arr;           
    int top;
    int capacity;
} DynamicStack;


//method for the creation of a dynamic stack with initial capacity 
//returns a pointer to the created stack and NULL if memory allocation fails
DynamicStack* createStack(int initialCapacity){
    DynamicStack* stack = (DynamicStack*)malloc(sizeof(DynamicStack));
    if (stack == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }
    stack->arr = (int*)malloc(initialCapacity * sizeof(int));
    if (stack->arr == NULL) {
        free(stack);
        return NULL; // Return NULL if memory allocation fails for the array
    }
    stack->top = -1;    
    stack->capacity = initialCapacity;
    return stack;
}

//method to destroy the dynamic stack and free the allocated memory
void destroyStack(DynamicStack *stack){
    free(stack->arr);
    free(stack);
}


//method to clear the stack, this deletes all the elements in the stack and resets the top to -1, but keeps the allocated memory for future use
void clearStack(DynamicStack *stack){ 
    stack->top = -1; // Reset the top index to -1, effectively clearing the stack
}

//method to deep clean the stack , it deallocates the memory of the stack and resets the top to -1 

void deepCleanStack(DynamicStack *stack){
    free(stack->arr); // Free the memory allocated for the stack's array
    stack->arr = NULL; // Set the array pointer to NULL to avoid dangling pointer
    stack->top = -1;   // Reset the top index to -1
    stack->capacity = 0; // Reset the capacity to 0
}

//method to resize the stack to a new capacity, returns 1 on success, -1 on failure and 0 if the new capacity is less than or equal to the current capacity
int resizeStack(DynamicStack *stack, int newCapacity){
    if (newCapacity <= stack->capacity) {
        return 0; 
    }
    int *temp = (int*)realloc(stack->arr, newCapacity * sizeof(int));
    if (temp == NULL) {
        return -1; // Return -1 if memory allocation fails
    }
    stack->arr = temp;
    stack->capacity = newCapacity;
    return 1; // Return 1 on success
}

//method to shrink the size of the stack to the current capacity, freeing any unused memory, returns 1 on success, -1 on failure and 0 if the size is equal to the capacity
int shrinkToFitStack(DynamicStack *stack){
    if (stack->top + 1 < stack->capacity) {
        return resizeStack(stack, stack->top + 1);
    }
    return 0; // No need to shrink if the size is equal to the capacity 
}


//method to check if the given stack is empty or not 
//returns 1 if the stack is empty and 0 if the stack is full
int isEmptyStack(DynamicStack *stack){
    return stack->top == -1;
}

//method to check if the the stack is full or not
int isFullStack(DynamicStack *stack){
    return stack->top == stack->capacity - 1;
}

//method to get the current size of the stack
int getSizeStack(DynamicStack *stack){
    return stack->top + 1;
}

//method to get the current capacity of the stack
int getCapacityStack(DynamicStack *stack){
    return stack->capacity;
}


// method to push an element onto the top of the stack, returns 1 on success and 0 on failure
int pushStack(DynamicStack *stack, int value){
    if (isFullStack(stack)) {
        int result = resizeStack(stack, stack->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Return -1 if memory allocation fails
        }
    }
    stack->arr[++stack->top] = value;
    return 1; // Return 1 on success
}

// method to pop an element from the top of the stack, returns the popped element or -1 if the stack is empty
int popStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        return -1; // Return -1 if the stack is empty
    }
    return stack->arr[stack->top--];
}

// method to peek at the top element of the stack without removing it, returns the top element or -1 if the stack is empty
int peekStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        return -1; // Return -1 if the stack is empty
    }
    return stack->arr[stack->top];
}

//method to push an element onto the stack , returns 1 on sucess and 0 on failure and if the stack is full then autopmatically resizes the stack 
int pushStack(DynamicStack *stack, int value){
    if (isFullStack(stack)) {
        int result = resizeStack(stack, stack->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Return -1 if memory allocation fails
        }
    }
    stack->arr[++stack->top] = value;
    return 1; // Return 1 on success
}

//method to pop an element from the stack , returns the popped element or -1 if the stack is empty
int popStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        return -1; // Return -1 if the stack is empty
    }
    return stack->arr[stack->top--];
}


//method to display the stack contents from top to bottom without deleting the elements
void displayStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Dynamic Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

//method to display the stack contents from bottom to top without deleting the elements
void displayReverseStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Dynamic Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

//method to compare two dynamic stacks for equality
//returns 1 if they are equal and 0 otherwise
int compareStacks(DynamicStack *a, DynamicStack *b){
    if (a->top != b->top) {
        return 0; // Stacks are not equal if their sizes differ
    }
    for (int i = 0; i <= a->top; i++) {
        if (a->arr[i] != b->arr[i]) {
            return 0; // Stacks are not equal if any element differs
        }
    }
    return 1; // Stacks are equal
}


//method to make a deep copy of the stack and return a pointer to the new stack
DynamicStack* copyStack(DynamicStack *stack){
    DynamicStack* newStack = createStack(stack->capacity);
    if (newStack == NULL) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i <= stack->top; i++) {
        newStack->arr[i] = stack->arr[i];
    }
    return newStack;
}

//method to swap the contents of two stacks
void swapStacks(DynamicStack *a, DynamicStack *b){
    DynamicStack temp = *a;
    *a = *b;
    *b = temp;
}


// method to reverse the order of all elements in the stack
void reverseStack(DynamicStack *stack){
    for (int i = 0; i < stack->top; i++) {
        int temp = stack->arr[i];
        stack->arr[i] = stack->arr[stack->top - i];
        stack->arr[stack->top - i] = temp;
    }
}

//method to check if a value exists in the stack
int containsStack(DynamicStack *stack, int value){
    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i] == value) {
            return 1; // Value found
        }
    }
    return 0; // Value not found
}

//method to check if the stack contains a given value
int containsStack(DynamicStack *stack, int value){
    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i] == value) {
            return 1; // Value found
        }
    }
    return 0; // Value not found
}

//method to cont the occurances of the elements in the stack
int countOccurrencesStack(DynamicStack *stack, int value){
    int count = 0;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i] == value) {
            count++;
        }
    }
    return count;
}

//method to find the maximum element in the stack
int maxStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    int maxValue = stack->arr[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->arr[i] > maxValue) {
            maxValue = stack->arr[i];
        }
    }
    return maxValue;
}

//method to find the minimum element in the stack
int minStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    int minValue = stack->arr[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->arr[i] < minValue) {
            minValue = stack->arr[i];
        }
    }
    return minValue;
}


// method to calculate the sum of all elements in the stack
long long sumStack(DynamicStack *stack){
    long long total = 0;
    for (int i = 0; i <= stack->top; i++) {
        total += stack->arr[i];
    }
    return total;
}

// method to calculate the average of all elements in the stack
double averageStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return 0.0; // Return an error value or handle the error as needed
    }
    long long total = sumStack(stack);
    return (double)total / stack->top;
}


//method to validate the internal consistency of the stack
int validateStack(DynamicStack *stack){
    if (stack->top < -1 || stack->top >= stack->capacity) {
        printf("Invalid stack state\n");
        return 0; // Invalid stack state
    }
    if (stack->arr == NULL) {
        printf("Invalid stack state\n");
        return 0; // Invalid stack state
    }
    if (stack->capacity <= 0) {
        printf("Invalid stack state\n");
        return 0; // Invalid stack state
    }
    return 1; // Valid stack state
}

//method to print diagnostic information about the stack
void printInfoStack(DynamicStack *stack){
    printf("Dynamic Stack Info:\n");
    printf("Size: %d\n", stack->top + 1);
    printf("Capacity: %d\n", stack->capacity);
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Top Index: %d\n", stack->top);
        printf("Memory Usage: %d bytes\n", sizeof(DynamicStack) + stack->capacity * sizeof(int));
        printf("Load Factor: %.2f\n", (double)stack->top / stack->capacity);
    }
}

//merges two dynamic stacks into a new stack and returns a pointer to the merged stack
DynamicStack* mergeStacks(DynamicStack *a, DynamicStack *b){
    DynamicStack* mergedStack = createStack(a->capacity + b->capacity);
    if (mergedStack == NULL) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i <= a->top; i++) {
        mergedStack->arr[i] = a->arr[i];
    }
    for (int i = 0; i <= b->top; i++) {
        mergedStack->arr[a->top + i + 1] = b->arr[i];
    }
    mergedStack->top = a->top + b->top;
    return mergedStack;
}

//method to move the top element from one stack to another
int moveTopStack(DynamicStack *source, DynamicStack *destination){
    if (isEmptyStack(source)) {
        printf("Source stack is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    destination->arr[destination->top] = source->arr[source->top];
    destination->top++;
    return 0; // Success
}

//method to duplicate the top element of the stack
int duplicateTopStack(DynamicStack *stack){
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    pushStack(stack, stack->arr[stack->top]);
    return 0; // Success
}

//method to trim unused memory of the stack
int trimUnusedMemoryStack(DynamicStack *stack){
    if (stack->top + 1 < stack->capacity) {
        return resizeStack(stack, stack->top + 1);
    }
    return 0; // No need to trim if the size is equal to the capacity
}