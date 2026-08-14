#include<stdio.h>

//defining the structure for dynamic queue
typedef struct
{
    int *arr;          // Pointer to dynamically allocated array
    int front;         // Index of the front element
    int rear;          // Index of the last element
    int size;          // Current number of elements
    int capacity;      // Allocated capacity
} DynamicQueue;

//method for the creation of a dynamic queue with initial capacity       
//returns a pointer to the created queue and NULL if memory allocation fails
DynamicQueue* createQueue(int initialCapacity){
    DynamicQueue* queue = (DynamicQueue*)malloc(sizeof(DynamicQueue));
    if (queue == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }
    queue->arr = (int*)malloc(initialCapacity * sizeof(int));
    if (queue->arr == NULL) {
        free(queue);
        return NULL; // Return NULL if memory allocation fails for the array
    }
    queue->front = -1;    
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = initialCapacity;
    return queue;
}

//method to destroy the dynamic queue and free the allocated memory
void destroyQueue(DynamicQueue *queue){
    free(queue->arr);
    free(queue);
}

//method to clear the queue, this deletes all the elements in the queue and resets the front and rear to -1, but keeps the allocated memory for future use
void clearQueue(DynamicQueue *queue){ 
    queue->front = -1; // Reset the front index to -1, effectively clearing the queue
    queue->rear = -1; // Reset the rear index to -1, effectively clearing the queue
    queue->size = 0; // Reset the size to 0
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

//method to deep clean the queue , it deallocates the memory of the queue and resets the front and rear to -1 
void deepCleanQueue(DynamicQueue *queue){
    free(queue->arr); // Free the memory allocated for the queue's array
    queue->arr = NULL; // Set the array pointer to NULL to avoid dangling pointer
    queue->front = -1;   // Reset the front index to -1
    queue->rear = -1;   // Reset the rear index to -1
    queue->capacity = 0; // Reset the capacity to 0
    queue->size = 0; // Reset the size to 0
}

//method to resize the queue to a new capacity, returns 1 on success, -1 on failure and 0 if the new capacity is less than or equal to the current capacity
int resizeQueue(DynamicQueue *queue, int newCapacity){
    if (newCapacity <= queue->capacity) {
        return 0; // No need to resize if the new capacity is less than or equal to current capacity
    }
    int *temp = (int*)realloc(queue->arr, newCapacity * sizeof(int));
    if (temp == NULL) {
        return -1; // Return -1 if memory allocation fails
    }
    queue->arr = temp;
    queue->capacity = newCapacity;
    return 1; // Return 1 on success
}

//method to shrink the size of the queue to the current capacity, freeing any unused memory, returns 1 on success, -1 on failure and 0 if the size is equal to the capacity
int shrinkToFitQueue(DynamicQueue *queue){
    if (queue->front + 1 < queue->capacity) {
        return resizeQueue(queue, queue->front + 1);
    }
    return 0; // No need to shrink if the size is equal to the capacity 
}

//method to check if the given queue is empty or not 
//returns 1 if the queue is empty and 0 if the queue is full
int isEmptyQueue(DynamicQueue *queue){
    return queue->front == -1;
}

//method to check if the the queue is full or not
int isFullQueue(DynamicQueue *queue){
    return queue->front == queue->capacity - 1;
}

//method to get the current size of the queue
int getSizeQueue(DynamicQueue *queue){
    return queue->size;
}

//method to get the current capacity of the queue
int getCapacityQueue(DynamicQueue *queue){
    return queue->capacity;
}   


// method to enqueue an element at the rear of the queue, returns 1 on success and 0 on failure
int enqueueQueue(DynamicQueue *queue, int value){
    if (isFullQueue(queue)) {
        int result = resizeQueue(queue, queue->capacity * 2); // Double the capacity
        if (result == -1) {
            return -1; // Return -1 if memory allocation fails
        }
    }
    queue->arr[++queue->rear] = value;
    queue->size++;
    return 0; // Return 0 on success
}

// method to dequeue an element from the front of the queue, returns the dequeued element or -1 if the queue is empty
int dequeueQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        return -1; // Return -1 if the queue is empty
    }
    int value = queue->arr[queue->front];
    queue->front++;
    queue->size--;
    return value; // Return the dequeued element
}

// method to peek at the front element of the queue without removing it, returns the front element or -1 if the queue is empty
int frontQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        return -1; // Return -1 if the queue is empty
    }
    return queue->arr[queue->front];
}

// method to peek at the rear element of the queue without removing it, returns the rear element or -1 if the queue is empty
int rearQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        return -1; // Return -1 if the queue is empty
    }
    return queue->arr[queue->rear];
}   

//method to display the queue contents from front to rear without deleting the elements
void displayQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dynamic Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

//method to display the queue contents from rear to front without deleting the elements
void displayReverseQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dynamic Queue: ");
    for (int i = queue->rear; i >= queue->front; i--) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

//method to compare two dynamic queues for equality
//returns 1 if they are equal and 0 otherwise
int compareQueues(DynamicQueue *a, DynamicQueue *b){
    if (a->size != b->size) {
        return 0; // Queues are not equal if their sizes differ
    }
    for (int i = 0; i <= a->rear; i++) {
        if (a->arr[i] != b->arr[i]) {
            return 0; // Queues are not equal if any element differs
        }
    }
    return 1; // Queues are equal
}   

//method to make a deep copy of the queue and return a pointer to the new queue
DynamicQueue* copyQueue(DynamicQueue *queue){
    DynamicQueue* newQueue = createQueue(queue->capacity);
    if (newQueue == NULL) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i <= queue->rear; i++) {
        newQueue->arr[i] = queue->arr[i];
    }
    return newQueue;
}

//method to swap the contents of two queues
void swapQueues(DynamicQueue *a, DynamicQueue *b){
    DynamicQueue temp = *a;
    *a = *b;
    *b = temp;
}


// method to reverse the order of all elements in the queue
void reverseQueue(DynamicQueue *queue){
    for (int i = 0; i < queue->front; i++) {
        int temp = queue->arr[i];
        queue->arr[i] = queue->arr[queue->front - i];
        queue->arr[queue->front - i] = temp;
    }
}

// method to rotate the queue towards the front by the specified number of positions
void rotateLeftQueue(DynamicQueue *queue, int positions){
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }
    positions = positions % queue->size; // Handle cases where positions > size
    if (positions == 0) {
        return; // No rotation needed
    }

    // Create a temporary array to hold the rotated elements
    int *temp = (int*)malloc(queue->size * sizeof(int));
    for (int i = 0; i < queue->size; i++) {
        temp[i] = queue->arr[(i + positions) % queue->size];
    }

    // Copy the rotated elements back to the original array
    for (int i = 0; i < queue->size; i++) {
        queue->arr[i] = temp[i];
    }

    free(temp); // Free the temporary array
}


// method to rotate the queue towards the rear by the specified number of positions
void rotateRightQueue(DynamicQueue *queue, int positions){
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }
    positions = positions % queue->size; // Handle cases where positions > size
    if (positions == 0) {
        return; // No rotation needed
    }

    // Create a temporary array to hold the rotated elements
    int *temp = (int*)malloc(queue->size * sizeof(int));
    for (int i = 0; i < queue->size; i++) {
        temp[i] = queue->arr[(i - positions + queue->size) % queue->size];
    }

    // Copy the rotated elements back to the original array
    for (int i = 0; i < queue->size; i++) {
        queue->arr[i] = temp[i];
    }

    free(temp); // Free the temporary array
}

// method to create a new queue by merging two existing queues while preserving order
DynamicQueue* mergeQueues(DynamicQueue *a, DynamicQueue *b){
    DynamicQueue* mergedQueue = createQueue(a->capacity + b->capacity);
    if (mergedQueue == NULL) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i <= a->rear; i++) {
        mergedQueue->arr[i] = a->arr[i];
    }
    for (int i = 0; i <= b->rear; i++) {
        mergedQueue->arr[a->rear + i + 1] = b->arr[i];
    }
    mergedQueue->size = a->size + b->size;
    return mergedQueue;
}

//method to move the front element from one queue to another
int moveFrontQueue(DynamicQueue *source, DynamicQueue *destination){
    if (isEmptyQueue(source)) {
        printf("Source queue is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    destination->arr[destination->front] = source->arr[source->front];
    destination->front++;
    destination->size++;
    return 0; // Success
}

//method to duplicate the front element of the queue
int duplicateFrontQueue(DynamicQueue *queue){
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return -1; // Return an error value or handle the error as needed
    }
    enqueueQueue(queue, queue->arr[queue->front]);
    return 0; // Success
}

//method to trim unused memory of the queue
int trimUnusedMemoryQueue(DynamicQueue *queue){
    if (queue->front + 1 < queue->capacity) {
        return resizeQueue(queue, queue->front + 1);
    }
    return 0; // No need to trim if the size is equal to the capacity
}   
