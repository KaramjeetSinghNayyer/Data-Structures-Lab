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




