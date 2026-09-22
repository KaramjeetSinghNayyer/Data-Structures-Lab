
## 1. Purpose

This document specifies a complete set of functions for implementing a **dynamic singly linked list** in ANSI C.

The specification is intentionally implementation-oriented: each function defines its purpose, expected inputs/outputs, required behavior, important edge cases, and expected complexity.

The implementation should use dynamically allocated nodes and must correctly release memory with `free()`.

---

## 2. Core Data Structure

Use the following node representation:

```c
struct Node {
    int data;
    struct Node *next;
};
```

The list is represented by:

```c
struct Node *head;
```

An empty list is represented by:

```c
head == NULL
```

### Recommended conventions

1. **Positions are 1-based.**
   - Position 1 means the first node.
   - Position `n` means the nth node.
2. Invalid positions must never cause undefined behavior.
3. Functions that modify `head` must receive either:
   - `struct Node **head`, or
   - return the updated head and have the caller assign it.
4. For consistency, this specification recommends:
   ```c
   void insertAtBeginning(struct Node **head, int data);
   ```
   and similar pointer-to-pointer signatures for operations that may change the head.
5. Functions returning a node should return `struct Node *`.
6. Functions that return success/failure should use `int`:
   - `1` = success/true
   - `0` = failure/false
7. Search functions should normally return `-1` when a requested position does not exist.
8. `malloc()` failure must be handled safely.
9. Every node allocated with `malloc()` must eventually be released with `free()`.
10. Never dereference `NULL`.
11. Never access a node after it has been freed.
12. Do not use C++ features, STL containers, or C99-only language features.

> **Note:** `malloc()` and `free()` are part of the C standard library. If the professor literally prohibits every standard library header, confirm the exact restriction. A dynamically allocated linked list normally requires `<stdlib.h>` for `malloc()` and `free()`.

---

# 3. Basic List Operations

## 3.1 `createNode`

### Suggested signature

```c
struct Node *createNode(int data);
```

### Purpose

Dynamically allocate and initialize one new node.

### Input

- `data` — integer value to store.

### Output

- Pointer to the newly allocated node.
- `NULL` if memory allocation fails.

### Required behavior

The returned node must have:

```text
node->data = data
node->next = NULL
```

### Complexity

- Time: `O(1)`
- Extra space: `O(1)` per node

---

## 3.2 `initializeList`

### Suggested signature

```c
void initializeList(struct Node **head);
```

### Purpose

Initialize a list to the empty state.

### Required behavior

Set:

```c
*head = NULL;
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

---

## 3.3 `isEmpty`

### Suggested signature

```c
int isEmpty(struct Node *head);
```

### Purpose

Determine whether the list contains zero nodes.

### Output

- `1` if empty.
- `0` otherwise.

### Complexity

- Time: `O(1)`
- Space: `O(1)`

---

## 3.4 `clearList`

### Suggested signature

```c
void clearList(struct Node **head);
```

### Purpose

Delete every node and release all dynamically allocated memory.

### Required behavior

After execution:

```c
*head == NULL
```

### Edge cases

Must correctly handle:

- Empty list.
- One-node list.
- Multi-node list.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary space.

---

# 4. Traversal Operations

## 4.1 `displayList`

### Suggested signature

```c
void displayList(struct Node *head);
```

### Purpose

Traverse the list from beginning to end and display every value.

### Example

```text
10 -> 20 -> 30 -> NULL
```

### Edge case

For an empty list, print an appropriate message such as:

```text
List is empty.
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 4.2 `displayReverse`

### Suggested signature

```c
void displayReverse(struct Node *head);
```

### Purpose

Display values from last node to first without modifying the list.

### Constraint

The list itself must remain unchanged.

### Recommended approach

Recursion is acceptable.

### Complexity

- Time: `O(n)`
- Auxiliary space: `O(n)` if recursion is used.

---

## 4.3 `countNodes`

### Suggested signature

```c
int countNodes(struct Node *head);
```

### Purpose

Return the number of nodes.

### Output

Returns `0` for an empty list.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 4.4 `getLastNode`

### Suggested signature

```c
struct Node *getLastNode(struct Node *head);
```

### Purpose

Return a pointer to the last node.

### Output

- Pointer to last node.
- `NULL` if list is empty.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 5. Insertion Operations

## 5.1 `insertAtBeginning`

### Suggested signature

```c
int insertAtBeginning(struct Node **head, int data);
```

### Purpose

Insert a new node before the current head.

### Example

```text
Before: 20 -> 30 -> NULL
Insert: 10

After:  10 -> 20 -> 30 -> NULL
```

### Output

- `1` on successful insertion.
- `0` if allocation fails.

### Complexity

- Time: `O(1)`
- Space: `O(1)` auxiliary.

---

## 5.2 `insertAtEnd`

### Suggested signature

```c
int insertAtEnd(struct Node **head, int data);
```

### Purpose

Append a node after the current last node.

### Edge cases

- Empty list: inserted node becomes head.
- Non-empty list: traverse to last node.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

## 5.3 `insertAtPosition`

### Suggested signature

```c
int insertAtPosition(struct Node **head, int data, int position);
```

### Purpose

Insert a new node at a specified 1-based position.

### Valid positions

For a list containing `n` nodes:

```text
1 through n+1
```

### Edge cases

- Position 1 -> insertion at beginning.
- Position `n+1` -> insertion at end.
- Empty list only accepts position 1.
- Any position <= 0 is invalid.
- Any position > `n+1` is invalid.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

## 5.4 `insertBeforeValue`

### Suggested signature

```c
int insertBeforeValue(struct Node **head, int data, int key);
```

### Purpose

Insert `data` immediately before the **first occurrence** of `key`.

### Example

```text
10 -> 20 -> 40
insert 30 before 40

10 -> 20 -> 30 -> 40
```

### Edge cases

- `key` at head -> new node becomes head.
- `key` absent -> no insertion.
- Empty list -> no insertion.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

## 5.5 `insertAfterValue`

### Suggested signature

```c
int insertAfterValue(struct Node **head, int data, int key);
```

### Purpose

Insert `data` immediately after the **first occurrence** of `key`.

### Edge cases

- Key is last node -> new node becomes last.
- Key absent -> no insertion.
- Empty list -> no insertion.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

## 5.6 `insertBeforeNode`

### Suggested signature

```c
int insertBeforeNode(struct Node **head, struct Node *target, int data);
```

### Purpose

Insert a new node immediately before the node whose address is `target`.

### Important requirement

The target must belong to the supplied list.

### Edge cases

- `target == NULL` -> failure.
- Target is head -> update head.
- Target absent from list -> failure.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

## 5.7 `insertAfterNode`

### Suggested signature

```c
int insertAfterNode(struct Node *target, int data);
```

### Purpose

Insert a new node immediately after `target`.

### Edge case

`target == NULL` -> failure.

### Complexity

- Time: `O(1)`
- Space: `O(1)` auxiliary.

---

## 5.8 `insertSorted`

### Suggested signature

```c
int insertSorted(struct Node **head, int data);
```

### Purpose

Insert `data` into an already ascending-sorted list while preserving ascending order.

### Example

```text
10 -> 20 -> 40
insert 30

10 -> 20 -> 30 -> 40
```

### Duplicate policy

Duplicates are allowed unless the caller specifies otherwise.

For ascending order, equal values may be inserted after existing equal values.

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary.

---

# 6. Deletion Operations

## 6.1 `deleteFromBeginning`

### Suggested signature

```c
int deleteFromBeginning(struct Node **head);
```

### Purpose

Remove the first node and release its memory.

### Output

- `1` if deletion occurred.
- `0` if list was empty.

### Complexity

- Time: `O(1)`
- Space: `O(1)`

---

## 6.2 `deleteFromEnd`

### Suggested signature

```c
int deleteFromEnd(struct Node **head);
```

### Purpose

Remove the final node and release its memory.

### Edge cases

- Empty list.
- One-node list.
- Multi-node list.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.3 `deleteAtPosition`

### Suggested signature

```c
int deleteAtPosition(struct Node **head, int position);
```

### Purpose

Delete the node at a specified 1-based position.

### Valid positions

For `n > 0`:

```text
1 through n
```

### Edge cases

Must correctly delete:

- Head.
- Tail.
- Middle node.
- Only node.

Invalid positions must not modify the list.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.4 `deleteByValue`

### Suggested signature

```c
int deleteByValue(struct Node **head, int key);
```

### Purpose

Delete the **first occurrence** of `key`.

### Duplicate policy

Only one node is deleted.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.5 `deleteAllOccurrences`

### Suggested signature

```c
int deleteAllOccurrences(struct Node **head, int key);
```

### Purpose

Delete every node whose `data == key`.

### Output

Recommended:

- Number of deleted nodes.

### Example

```text
10 -> 20 -> 20 -> 30
delete 20

10 -> 30
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.6 `deleteBeforeValue`

### Suggested signature

```c
int deleteBeforeValue(struct Node **head, int key);
```

### Purpose

Delete the node immediately before the first occurrence of `key`.

### Edge cases

- Key is head -> nothing to delete.
- Key is second node -> delete head.
- Key absent -> failure.
- Empty list -> failure.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.7 `deleteAfterValue`

### Suggested signature

```c
int deleteAfterValue(struct Node **head, int key);
```

### Purpose

Delete the node immediately after the first occurrence of `key`.

### Edge cases

- Key is last node -> failure.
- Key absent -> failure.
- Empty list -> failure.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 6.8 `deleteNode`

### Suggested signature

```c
int deleteNode(struct Node **head, struct Node *target);
```

### Purpose

Delete a specific node identified by its pointer.

### Important requirement

The function must verify that `target` belongs to the list before unlinking it.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 7. Searching Operations

## 7.1 `search`

### Suggested signature

```c
struct Node *search(struct Node *head, int key);
```

### Purpose

Return a pointer to the first node containing `key`.

### Output

- Pointer to first matching node.
- `NULL` if not found.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 7.2 `searchAll`

### Suggested signature

```c
void searchAll(struct Node *head, int key);
```

### Purpose

Traverse the complete list and report every position containing `key`.

### Example

```text
List: 10 -> 20 -> 30 -> 20
Key: 20

Positions: 2, 4
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` excluding output.

---

## 7.3 `contains`

### Suggested signature

```c
int contains(struct Node *head, int key);
```

### Purpose

Determine whether `key` exists.

### Output

- `1` if present.
- `0` otherwise.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 7.4 `findPosition`

### Suggested signature

```c
int findPosition(struct Node *head, int key);
```

### Purpose

Return the 1-based position of the first occurrence.

### Output

- Position if found.
- `-1` if not found.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 7.5 `countOccurrences`

### Suggested signature

```c
int countOccurrences(struct Node *head, int key);
```

### Purpose

Count the number of nodes whose value equals `key`.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 8. Access and Update Operations

## 8.1 `getNodeAtPosition`

### Suggested signature

```c
struct Node *getNodeAtPosition(struct Node *head, int position);
```

### Purpose

Return the node at the given 1-based position.

### Output

- Node pointer if valid.
- `NULL` otherwise.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 8.2 `getValueAtPosition`

### Suggested signature

```c
int getValueAtPosition(struct Node *head, int position, int *value);
```

### Purpose

Retrieve the value at a specified position.

### Recommended result convention

- Return `1` on success and store the value in `*value`.
- Return `0` for invalid position.

This avoids ambiguity if the stored value itself can be negative or zero.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 8.3 `updateAtPosition`

### Suggested signature

```c
int updateAtPosition(struct Node *head, int position, int newData);
```

### Purpose

Replace the data at a specified position.

### Important

Only node data changes. Node links must remain unchanged.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 8.4 `updateFirstOccurrence`

### Suggested signature

```c
int updateFirstOccurrence(struct Node *head, int oldValue, int newValue);
```

### Purpose

Replace the data in the first node containing `oldValue`.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 8.5 `updateAllOccurrences`

### Suggested signature

```c
int updateAllOccurrences(struct Node *head, int oldValue, int newValue);
```

### Purpose

Replace every occurrence of `oldValue`.

### Output

Recommended: number of nodes updated.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 9. Mathematical / Statistical Operations

## 9.1 `findMaximum`

### Suggested signature

```c
int findMaximum(struct Node *head, int *maximum);
```

### Purpose

Find the largest value.

### Empty-list behavior

Return `0` and do not attempt to dereference an invalid node.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 9.2 `findMinimum`

### Suggested signature

```c
int findMinimum(struct Node *head, int *minimum);
```

### Purpose

Find the smallest value.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 9.3 `calculateSum`

### Suggested signature

```c
long calculateSum(struct Node *head);
```

### Purpose

Return the sum of all node values.

### Empty-list behavior

Return `0`.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 9.4 `calculateAverage`

### Suggested signature

```c
int calculateAverage(struct Node *head, double *average);
```

### Purpose

Calculate the arithmetic mean.

### Empty-list behavior

Return `0` and do not divide by zero.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 9.5 `findSecondLargest`

### Suggested signature

```c
int findSecondLargest(struct Node *head, int *result);
```

### Purpose

Find the second-largest **distinct** value.

### Invalid case

If fewer than two distinct values exist, return failure.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 9.6 `findSecondSmallest`

### Suggested signature

```c
int findSecondSmallest(struct Node *head, int *result);
```

### Purpose

Find the second-smallest distinct value.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 10. Reversal Operations

## 10.1 `reverseIterative`

### Suggested signature

```c
void reverseIterative(struct Node **head);
```

### Purpose

Reverse the list using pointer manipulation.

### Example

```text
1 -> 2 -> 3 -> 4

4 -> 3 -> 2 -> 1
```

### Recommended variables

```text
prev
current
next
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 10.2 `reverseRecursive`

### Suggested signature

```c
void reverseRecursive(struct Node **head);
```

### Purpose

Reverse the list recursively.

### Complexity

- Time: `O(n)`
- Auxiliary space: `O(n)` due to recursion.

---

## 10.3 `reverseInGroups`

### Suggested signature

```c
void reverseInGroups(struct Node **head, int k);
```

### Purpose

Reverse nodes in consecutive groups of `k`.

### Example

```text
1 -> 2 -> 3 -> 4 -> 5 -> 6
k = 2

2 -> 1 -> 4 -> 3 -> 6 -> 5
```

### Edge cases

- `k <= 1` -> list unchanged.
- `k > n` -> define policy. Recommended: reverse the entire list if the remaining group contains fewer than `k`, or document another consistent policy.

### Complexity

- Time: `O(n)`
- Auxiliary space: `O(n)` if recursive.

---

# 11. Sorting Operations

## 11.1 `sortAscending`

### Suggested signature

```c
void sortAscending(struct Node **head);
```

### Purpose

Sort node values in non-decreasing order.

### Recommended algorithm

Merge sort is preferred for linked lists.

### Complexity

- Time: `O(n log n)`
- Auxiliary space: `O(log n)` for recursive merge sort, depending on implementation.

---

## 11.2 `sortDescending`

### Suggested signature

```c
void sortDescending(struct Node **head);
```

### Purpose

Sort node values in non-increasing order.

### Complexity

- Time: `O(n log n)` with merge sort.
- Auxiliary space: `O(log n)` recursively.

---

# 12. Duplicate Handling

## 12.1 `removeDuplicates`

### Suggested signature

```c
int removeDuplicates(struct Node **head);
```

### Purpose

Remove duplicate values from an unsorted list while retaining the first occurrence.

### Example

```text
10 -> 20 -> 10 -> 30 -> 20

10 -> 20 -> 30
```

### Constraint

Do not require an auxiliary hash table.

### Expected simple complexity

- Time: `O(n^2)`
- Space: `O(1)`

---

## 12.2 `removeConsecutiveDuplicates`

### Suggested signature

```c
int removeConsecutiveDuplicates(struct Node *head);
```

### Purpose

Remove only adjacent duplicate values.

### Example

```text
10 -> 10 -> 20 -> 20 -> 30

10 -> 20 -> 30
```

Non-adjacent duplicates remain.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 13. Position-Based Operations

## 13.1 `getMiddleNode`

### Suggested signature

```c
struct Node *getMiddleNode(struct Node *head);
```

### Purpose

Return the middle node.

### Required convention for even-length lists

For an even number of nodes, return the **second middle**.

Example:

```text
1 -> 2 -> 3 -> 4
```

Return node `3`.

### Recommended technique

Slow/fast pointers.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 13.2 `getNthNodeFromBeginning`

### Suggested signature

```c
struct Node *getNthNodeFromBeginning(struct Node *head, int n);
```

### Purpose

Return the nth node from the beginning.

### Convention

`n = 1` means head.

### Invalid input

`n <= 0` or `n > length` -> `NULL`.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 13.3 `getNthNodeFromEnd`

### Suggested signature

```c
struct Node *getNthNodeFromEnd(struct Node *head, int n);
```

### Purpose

Return the nth node from the end.

### Convention

For:

```text
1 -> 2 -> 3 -> 4 -> 5
```

`n = 1` returns `5`.

`n = 2` returns `4`.

### Recommended technique

Two-pointer method.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 14. List Manipulation

## 14.1 `copyList`

### Suggested signature

```c
struct Node *copyList(struct Node *head);
```

### Purpose

Create a completely independent deep copy.

### Critical requirement

The copied nodes must have different addresses from the original nodes.

### Example

```text
Original: 10 -> 20 -> 30
Copy:     10 -> 20 -> 30
```

Changing one list must not modify the other.

### Complexity

- Time: `O(n)`
- Space: `O(n)`

---

## 14.2 `concatenateList`

### Suggested signature

```c
int concatenateList(struct Node **head1, struct Node *head2);
```

### Purpose

Append list 2 after list 1.

### Ownership policy

Recommended policy:

- Reuse list 2's existing nodes.
- Do not copy list 2.
- After concatenation, `head1` owns the combined chain.
- The caller must not separately free `head2` as an independent list.

### Complexity

- Time: `O(n)` for list 1.
- Space: `O(1)`.

---

## 14.3 `mergeSortedLists`

### Suggested signature

```c
struct Node *mergeSortedLists(struct Node *head1, struct Node *head2);
```

### Purpose

Merge two ascending sorted lists into one ascending sorted list.

### Ownership policy

Recommended:

- Reuse existing nodes.
- Do not allocate duplicate nodes.
- The original list heads should no longer be treated as independent lists after merging.

### Complexity

- Time: `O(n + m)`
- Space: `O(1)` auxiliary.

---

## 14.4 `splitList`

### Suggested signature

```c
void splitList(struct Node *head, struct Node **first, struct Node **second);
```

### Purpose

Split one list into two approximately equal lists.

### Required convention

For an odd number of nodes, the first list should contain one more node.

Example:

```text
1 -> 2 -> 3 -> 4 -> 5

first:  1 -> 2 -> 3
second: 4 -> 5
```

### Recommended technique

Slow/fast pointers.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 15. Comparison and Property Operations

## 15.1 `compareLists`

### Suggested signature

```c
int compareLists(struct Node *head1, struct Node *head2);
```

### Purpose

Compare two lists element by element.

### Output

Recommended:

- `1` if same sequence.
- `0` otherwise.

### Important

Length and order must both match.

### Complexity

- Time: `O(min(n,m))` until a mismatch, or `O(n+m)` worst case.
- Space: `O(1)`.

---

## 15.2 `isIdentical`

### Suggested signature

```c
int isIdentical(struct Node *head1, struct Node *head2);
```

### Purpose

Check whether two lists contain exactly the same sequence of values.

This is functionally equivalent to `compareLists` under the conventions of this specification, but can be retained as a separately named API function if the assignment explicitly asks for it.

---

## 15.3 `isPalindrome`

### Suggested signature

```c
int isPalindrome(struct Node *head);
```

### Purpose

Determine whether the sequence of values is identical forwards and backwards.

### Example

```text
1 -> 2 -> 3 -> 2 -> 1
```

returns true.

### Recommended approach

1. Find middle.
2. Reverse second half.
3. Compare both halves.
4. Optionally restore the original list.

### Complexity

- Time: `O(n)`
- Auxiliary space: `O(1)` if pointer-based.

---

# 16. Cycle Operations

## 16.1 `detectCycle`

### Suggested signature

```c
int detectCycle(struct Node *head);
```

### Purpose

Determine whether any node eventually points back to an earlier node.

### Recommended algorithm

Floyd's tortoise-and-hare algorithm.

### Output

- `1` if cycle exists.
- `0` otherwise.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 16.2 `findCycleStart`

### Suggested signature

```c
struct Node *findCycleStart(struct Node *head);
```

### Purpose

Return the first node belonging to the cycle.

### Output

- Cycle entry node.
- `NULL` if no cycle exists.

### Recommended algorithm

Floyd's algorithm followed by resetting one pointer to head.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 16.3 `removeCycle`

### Suggested signature

```c
int removeCycle(struct Node *head);
```

### Purpose

Detect and remove a cycle without freeing nodes.

### Important

After successful execution, the list must terminate in:

```c
NULL
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 17. Rotation and Node Manipulation

## 17.1 `rotateLeft`

### Suggested signature

```c
void rotateLeft(struct Node **head, int k);
```

### Purpose

Move the first `k` nodes to the end.

### Example

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2

3 -> 4 -> 5 -> 1 -> 2
```

### Optimization

Reduce:

```text
k = k % n
```

before performing the rotation.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 17.2 `rotateRight`

### Suggested signature

```c
void rotateRight(struct Node **head, int k);
```

### Purpose

Move the last `k` nodes to the front.

### Example

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2

4 -> 5 -> 1 -> 2 -> 3
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 17.3 `swapNodes`

### Suggested signature

```c
int swapNodes(struct Node **head, int x, int y);
```

### Purpose

Exchange the positions of the first nodes containing `x` and `y`.

### Important requirement

The preferred implementation should **swap the actual nodes by changing links**, not merely swap their `data`.

### Edge cases

- `x == y` -> no change.
- Either value absent -> failure.
- One or both nodes are head.
- Nodes are adjacent.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 17.4 `moveLastToFirst`

### Suggested signature

```c
void moveLastToFirst(struct Node **head);
```

### Purpose

Move the final node to the beginning.

### Example

```text
10 -> 20 -> 30 -> 40

40 -> 10 -> 20 -> 30
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 17.5 `moveFirstToLast`

### Suggested signature

```c
void moveFirstToLast(struct Node **head);
```

### Purpose

Move the first node to the end.

### Example

```text
10 -> 20 -> 30 -> 40

20 -> 30 -> 40 -> 10
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 17.6 `pairwiseSwap`

### Suggested signature

```c
void pairwiseSwap(struct Node **head);
```

### Purpose

Swap adjacent nodes by changing links.

### Example

```text
1 -> 2 -> 3 -> 4 -> 5

2 -> 1 -> 4 -> 3 -> 5
```

### Important

Prefer actual node swapping instead of data swapping.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 18. Multiple-List Operations

## 18.1 `findIntersection`

### Suggested signature

```c
struct Node *findIntersection(struct Node *head1, struct Node *head2);
```

### Purpose

Find the first **physically shared node** between two lists.

This is NOT a comparison of equal data values.

Example:

```text
List 1: A -> B \
                 C -> D -> NULL
List 2: X -> Y /
```

The intersection is node `C`.

### Complexity

- Time: `O(n + m)`
- Space: `O(1)`.

---

## 18.2 `unionOfLists`

### Suggested signature

```c
struct Node *unionOfLists(struct Node *head1, struct Node *head2);
```

### Purpose

Create a new list containing each distinct value occurring in either input list.

### Ownership

The returned list should contain newly allocated nodes and should not modify either input list.

### Example

```text
List 1: 1 -> 2 -> 3
List 2: 3 -> 4 -> 5

Result: 1 -> 2 -> 3 -> 4 -> 5
```

### Duplicate policy

Each value occurs at most once in the result.

### Complexity

- Time: `O((n+m)^2)` with a no-extra-data-structure implementation.
- Space: `O(n+m)` for the result.

---

## 18.3 `intersectionOfLists`

### Suggested signature

```c
struct Node *intersectionOfLists(struct Node *head1, struct Node *head2);
```

### Purpose

Create a new list containing distinct values present in both input lists.

### Important

This is **value-based intersection**, unlike `findIntersection`, which is address/node based.

### Example

```text
List 1: 1 -> 2 -> 3
List 2: 2 -> 3 -> 4

Result: 2 -> 3
```

### Complexity

- Time: `O(n*m)` without auxiliary storage.
- Space: `O(min(n,m))` for the result.

---

## 18.4 `differenceOfLists`

### Suggested signature

```c
struct Node *differenceOfLists(struct Node *head1, struct Node *head2);
```

### Purpose

Create a new list containing distinct values present in list 1 but absent from list 2.

### Example

```text
List 1: 1 -> 2 -> 3 -> 4
List 2: 2 -> 4

Result: 1 -> 3
```

### Complexity

- Time: `O(n*m)` without auxiliary storage.
- Space: `O(n)` for the result.

---

# 19. Memory and Validation Functions

## 19.1 `freeNode`

### Suggested signature

```c
void freeNode(struct Node *node);
```

### Purpose

Release dynamically allocated memory for a node.

### Critical rule

The node must not be accessed after this function is called.

### Complexity

- Time: `O(1)`
- Space: `O(1)`

---

## 19.2 `freeList`

### Suggested signature

```c
void freeList(struct Node **head);
```

### Purpose

Release every node and set the head to `NULL`.

This is equivalent in purpose to `clearList`; retain both only if the assignment explicitly requires both names.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 19.3 `isValidPosition`

### Suggested signature

```c
int isValidPosition(struct Node *head, int position);
```

### Purpose

Determine whether a 1-based position exists in the list.

### Output

- `1` if valid.
- `0` otherwise.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 19.4 `getLength`

### Suggested signature

```c
int getLength(struct Node *head);
```

### Purpose

Return the number of nodes.

This is functionally equivalent to `countNodes`; retain one or both depending on assignment requirements.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 20. Debugging / Visualization Functions

## 20.1 `displayDetailed`

### Suggested signature

```c
void displayDetailed(struct Node *head);
```

### Purpose

Display the address, data, and next pointer of every node.

### Suggested output

```text
Node Address    Data    Next Address
-------------------------------------
0x1234          10      0x5678
0x5678          20      0x7890
0x7890          30      NULL
```

### Purpose in a lab

This is especially useful for demonstrating dynamic memory allocation and pointer manipulation during a viva.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

## 20.2 `displayAddresses`

### Suggested signature

```c
void displayAddresses(struct Node *head);
```

### Purpose

Display the memory address of every node and its `next` pointer.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

---

# 21. Function Summary

| # | Function | Main purpose | Typical time |
|---|---|---|---|
| 1 | `createNode` | Allocate a node | O(1) |
| 2 | `initializeList` | Initialize empty list | O(1) |
| 3 | `isEmpty` | Check empty state | O(1) |
| 4 | `clearList` | Delete entire list | O(n) |
| 5 | `displayList` | Forward traversal | O(n) |
| 6 | `displayReverse` | Reverse display | O(n) |
| 7 | `countNodes` | Count nodes | O(n) |
| 8 | `getLastNode` | Find last node | O(n) |
| 9 | `insertAtBeginning` | Insert at head | O(1) |
| 10 | `insertAtEnd` | Insert at tail | O(n) |
| 11 | `insertAtPosition` | Insert at position | O(n) |
| 12 | `insertBeforeValue` | Insert before value | O(n) |
| 13 | `insertAfterValue` | Insert after value | O(n) |
| 14 | `insertBeforeNode` | Insert before node | O(n) |
| 15 | `insertAfterNode` | Insert after node | O(1) |
| 16 | `insertSorted` | Sorted insertion | O(n) |
| 17 | `deleteFromBeginning` | Delete head | O(1) |
| 18 | `deleteFromEnd` | Delete tail | O(n) |
| 19 | `deleteAtPosition` | Delete at position | O(n) |
| 20 | `deleteByValue` | Delete first value | O(n) |
| 21 | `deleteAllOccurrences` | Delete all matches | O(n) |
| 22 | `deleteBeforeValue` | Delete predecessor | O(n) |
| 23 | `deleteAfterValue` | Delete successor | O(n) |
| 24 | `deleteNode` | Delete specified node | O(n) |
| 25 | `search` | Find first value | O(n) |
| 26 | `searchAll` | Find all matches | O(n) |
| 27 | `contains` | Membership test | O(n) |
| 28 | `findPosition` | Find first position | O(n) |
| 29 | `countOccurrences` | Count value | O(n) |
| 30 | `getNodeAtPosition` | Access node | O(n) |
| 31 | `getValueAtPosition` | Access value | O(n) |
| 32 | `updateAtPosition` | Update position | O(n) |
| 33 | `updateFirstOccurrence` | Update first match | O(n) |
| 34 | `updateAllOccurrences` | Update all matches | O(n) |
| 35 | `findMaximum` | Find maximum | O(n) |
| 36 | `findMinimum` | Find minimum | O(n) |
| 37 | `calculateSum` | Sum values | O(n) |
| 38 | `calculateAverage` | Average values | O(n) |
| 39 | `findSecondLargest` | Second distinct maximum | O(n) |
| 40 | `findSecondSmallest` | Second distinct minimum | O(n) |
| 41 | `reverseIterative` | Reverse list | O(n) |
| 42 | `reverseRecursive` | Recursive reversal | O(n) |
| 43 | `reverseInGroups` | Group reversal | O(n) |
| 44 | `sortAscending` | Ascending sort | O(n log n) |
| 45 | `sortDescending` | Descending sort | O(n log n) |
| 46 | `removeDuplicates` | Remove all duplicates | O(n²) |
| 47 | `removeConsecutiveDuplicates` | Remove adjacent duplicates | O(n) |
| 48 | `getMiddleNode` | Find middle | O(n) |
| 49 | `getNthNodeFromBeginning` | nth from start | O(n) |
| 50 | `getNthNodeFromEnd` | nth from end | O(n) |
| 51 | `copyList` | Deep copy | O(n) |
| 52 | `concatenateList` | Join lists | O(n) |
| 53 | `mergeSortedLists` | Merge sorted lists | O(n+m) |
| 54 | `splitList` | Divide list | O(n) |
| 55 | `compareLists` | Compare sequences | O(n+m) worst |
| 56 | `isIdentical` | Check identical lists | O(n+m) worst |
| 57 | `isPalindrome` | Palindrome test | O(n) |
| 58 | `detectCycle` | Detect cycle | O(n) |
| 59 | `findCycleStart` | Find cycle entry | O(n) |
| 60 | `removeCycle` | Remove cycle | O(n) |
| 61 | `rotateLeft` | Left rotation | O(n) |
| 62 | `rotateRight` | Right rotation | O(n) |
| 63 | `swapNodes` | Swap actual nodes | O(n) |
| 64 | `moveLastToFirst` | Move tail to head | O(n) |
| 65 | `moveFirstToLast` | Move head to tail | O(n) |
| 66 | `pairwiseSwap` | Swap adjacent nodes | O(n) |
| 67 | `findIntersection` | Physical node intersection | O(n+m) |
| 68 | `unionOfLists` | Value union | O((n+m)²) |
| 69 | `intersectionOfLists` | Value intersection | O(nm) |
| 70 | `differenceOfLists` | List difference | O(nm) |
| 71 | `freeNode` | Free one node | O(1) |
| 72 | `freeList` | Free entire list | O(n) |
| 73 | `isValidPosition` | Validate position | O(n) |
| 74 | `getLength` | Return length | O(n) |
| 75 | `displayDetailed` | Show pointer structure | O(n) |
| 76 | `displayAddresses` | Show addresses | O(n) |

> The original function set contains 75 conceptual operations. `getLength()` and `freeList()` are retained as explicit aliases of functionality already covered by `countNodes()` and `clearList()` because they are common lab/API names. This specification therefore lists 76 named functions when those aliases are counted separately.

---

# 22. Critical Edge Cases to Test

A robust implementation should test every mutating function against at least these states:

### Case A — Empty list

```text
NULL
```

### Case B — One node

```text
10 -> NULL
```

### Case C — Two nodes

```text
10 -> 20 -> NULL
```

### Case D — Multiple nodes

```text
10 -> 20 -> 30 -> 40 -> NULL
```

### Case E — Duplicate values

```text
10 -> 20 -> 10 -> 20 -> 10 -> NULL
```

### Case F — Negative values

```text
-10 -> 5 -> -20 -> 30 -> NULL
```

### Case G — All values identical

```text
7 -> 7 -> 7 -> 7 -> NULL
```

### Case H — Invalid positions

Test:

```text
position = 0
position = -1
position > length
```

### Case I — Allocation failure

`createNode()` must safely handle `malloc()` returning `NULL`.

### Case J — Head modification

Every function that can change the first node must correctly update `head`.

---

# 23. Memory-Safety Rules

The following rules should be treated as mandatory:

1. Every successful `malloc()` must have a corresponding `free()`.
2. Never call `free()` twice on the same node.
3. Never dereference a pointer after freeing it.
4. Save the next pointer before freeing a node during traversal.
5. When deleting the head:
   ```text
   old_head = head
   head = head->next
   free(old_head)
   ```
6. When deleting a middle node:
   ```text
   predecessor->next = target->next
   free(target)
   ```
7. After clearing a list:
   ```text
   head == NULL
   ```
8. A normal non-cyclic linked list must eventually terminate at `NULL`.
9. Cycle functions must be used carefully because ordinary traversal can otherwise become infinite.
10. If a function transfers ownership of nodes between lists, document which list owns those nodes afterward.

---

# 24. Recommended Testing Strategy

Implement and test in this order:

```text
Phase 1:
createNode
initializeList
isEmpty
displayList
countNodes

Phase 2:
insertAtBeginning
insertAtEnd
insertAtPosition

Phase 3:
deleteFromBeginning
deleteFromEnd
deleteAtPosition

Phase 4:
search
contains
findPosition
updateAtPosition

Phase 5:
insertBeforeValue
insertAfterValue
deleteByValue
deleteAllOccurrences

Phase 6:
reverseIterative
reverseRecursive
getMiddleNode
getNthNodeFromEnd

Phase 7:
removeDuplicates
sortAscending
sortDescending
insertSorted

Phase 8:
copyList
concatenateList
splitList
mergeSortedLists

Phase 9:
isPalindrome
detectCycle
findCycleStart
removeCycle

Phase 10:
rotation
node swapping
multiple-list operations
debugging functions

Final:
clearList / freeList
```

---

# 25. Minimum Quality Standard

Before considering the assignment complete, verify that:

- The program compiles as ANSI C.
- No C++ syntax is present.
- Empty lists are handled.
- Single-node lists are handled.
- Head modification is correct.
- Tail deletion is correct.
- Invalid positions do not corrupt the list.
- Duplicate values are handled according to specification.
- Every dynamically allocated node is eventually freed.
- No dangling pointer is dereferenced.
- No memory leak remains after program termination.
- No infinite loop occurs during ordinary traversal.
- Cycle functions work on both cyclic and acyclic lists.
- Functions that modify links preserve list integrity.
- Multi-list ownership is clearly understood.
'''

