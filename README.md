# C/C++ Programs-Sem-2-IIITV-ICD
Welcome to the repository containing C/C++ programs for the second semester at IIITV-ICD. This repository includes code from various sources such as lab sessions, assignments, tutorials, and class discussions.
## Repository Structure
The repository is organized into the following directories:
<br>
1. Lab Sessions: Contains programs written during lab sessions.
2. Tutorials: Features tutorial examples and practice problems.
3. Other
## Lab Sessions :

### 1. Student Linked List Program :
This C program manages a list of students using a singly linked list. It allows users to perform various operations such as adding new student records, displaying all student records, deleting a student record by roll number, searching for a student by roll number, and inserting a new student at a specified position. The program demonstrates fundamental linked list operations and provides a basic interface for interacting with the student data. Each student record consists of a roll number, name, and a pointer to the next student, forming a chain of records that can be traversed and modified as needed.

### 2. Double-Ended Queue (Deque) Implementation in C : 
This C program implements a double-ended queue (deque) using a circular array. The deque allows for insertion and deletion of elements from both the front and back ends of the queue. The program includes functions to check if the deque is empty or full, to push and pop elements from both ends, and to retrieve the front and back elements. Additionally, it can display the current size and contents of the deque.

### 3. a)Polynomial Operations Using Linked Lists in C :
This C program implements polynomial addition and subtraction using singly linked lists. Each polynomial is represented as a linked list, where each node contains a coefficient and an exponent. The program provides functions to display, add, and subtract polynomials.
### 3. b)Polynomial Operations Using Linked Lists in C with Auxiliary Memory Management :
This C program implements polynomial addition using singly linked lists. Each polynomial is represented as a linked list, where each node contains a coefficient and an exponent. The program includes functions to display polynomials, add two polynomials, and manage auxiliary memory for efficient memory usage.

### 4.Stack Implementation Using Two Queues in C :
This C program implements a stack using two queues. It demonstrates fundamental stack operations such as push and pop while using queues to store and manage the elements. The program utilizes two arrays to represent the queues and provides various utility functions to manage and display the stack contents.

### 5. QuickSort Algorithm in C :
This C program implements the QuickSort algorithm, a highly efficient sorting algorithm that uses the divide-and-conquer strategy to sort an array of integers. The program sorts an array of ten integers and displays the array before and after sorting.

### 6. Heap Sort Algorithm in C : 
This C program implements the Heap Sort algorithm, a highly efficient sorting algorithm that uses a binary heap data structure to sort an array of integers. The program sorts an array of ten integers and displays the array before and after sorting.

### 7. Infix to Postfix Conversion and Evaluation :
This C program converts an infix expression to postfix and then evaluates the postfix expression to produce the result. It utilizes a stack-based approach to convert infix to postfix and evaluates the postfix expression.

### 8. Infix Expression Evaluation with Balanced Parentheses Check :
This C program efficiently evaluates infix expressions while ensuring that the input expressions have balanced parentheses. It converts the infix expression into postfix notation, handling operators and maintaining the correct order of operations. After conversion, it evaluates the postfix expression, performing arithmetic and logical operations as needed. If the input expression contains unbalanced parentheses, the program promptly notifies the user, ensuring the integrity of the evaluation process. This program provides a robust solution for evaluating infix expressions, making it suitable for various mathematical and computational tasks.

### 9. Binary Search Tree Operations in C :
This C program demonstrates various operations on a Binary Search Tree (BST), including insertion and deletion. It provides a user-friendly interface for adding and removing nodes from the tree while maintaining the binary search tree property. The program prompts the user to input values to add to the BST and then displays the resulting tree structure using an in-order traversal. Additionally, it allows users to delete specific nodes from the BST by entering the value to be deleted, providing feedback on the success or failure of the deletion operation. Throughout the program, careful attention is paid to maintaining the integrity of the BST structure and handling edge cases, ensuring the correct functioning of the operations.

## Tutorials :
### 1. Parenthesis Balancing Check in C :
This C program checks if the parentheses in a given expression are balanced. Using a stack-based approach, it processes the expression character by character. For each opening parenthesis '(', it pushes onto the stack, and for each closing parenthesis ')', it pops from the stack. After processing the entire expression, it determines if the stack is empty to confirm balanced parentheses, otherwise, it reports the expression as unbalanced. This method ensures that every opening parenthesis has a corresponding closing parenthesis in the correct order.
### 2. Implementing a Queue Using Two Stacks in C :
This C program simulates a queue using two stacks, providing queue functionalities such as enqueue (pushQ), dequeue (popQ), and display (disp). The queue operations handle up to 100,000 elements, ensuring efficient management of large data sets. When a dequeue operation is requested, elements are transferred from the primary stack to a secondary stack if the secondary stack is empty, thus maintaining the correct order for queue operations. The display function outputs the queue's front element. This approach leverages the LIFO property of stacks to achieve the FIFO behavior of a queue.
### 3. Comprehensive Management of Singly and Circular Linked Lists in C :
This C program demonstrates the creation and manipulation of singly and circular linked lists using various operations. The program includes functions to add elements to singly linked lists (linkadder), display the contents of the lists (display), concatenate two singly linked lists (concatenation), reverse a singly linked list (reverser), create a circular linked list (circulist), and delete all nodes in a circular linked list (circudel). The main function tests these operations, showcasing the versatility and utility of linked lists in data management.
### 4. Efficient Polynomial Manipulation Using Linked Lists in C :
This C program provides an efficient way to manipulate polynomials represented as linked lists. It includes functionalities for displaying polynomials, adding polynomials, and managing memory with an auxiliary list to reuse nodes. The program handles operations such as adding polynomials by combining like terms and efficiently managing memory allocation and deallocation using an auxiliary list. This implementation ensures that polynomials are manipulated with minimal memory overhead and optimal performance.
### 5. Finding the ith Smallest Element and QuickSort Implementation in C :
This C program demonstrates the implementation of the QuickSort algorithm and the procedure to find the ith smallest element in an array. QuickSort is a highly efficient sorting algorithm that uses the divide-and-conquer strategy. The program includes functions for sorting the array, partitioning the array around a pivot, and finding the ith smallest element using a modified QuickSort approach. It also includes a function to display the array.
## Other :
### 1. Fibonacci Sequence Using Stack in C++
This C++ program demonstrates a non-traditional way of calculating Fibonacci numbers using a stack to track the recursive calls. The program uses a global stack to simulate the function call stack and visualize the process of calculating the Fibonacci sequence. Each call to the Fibonacci function pushes the current value onto the stack, and each return from the function pops the value off the stack. The stack is displayed at each step to show the state of the recursive calls.
### 2. Checking Balanced Parentheses Using Stack in C :
This C program checks if an input expression has balanced parentheses using a stack implemented with a linked list. Each time an opening parenthesis '(' is encountered, it is pushed onto the stack. When a closing parenthesis ')' is encountered, the program pops the top of the stack. If the stack is empty at the end of the expression, the parentheses are balanced; otherwise, they are not.
### 3. Disjoint Set Data Structure in C :
This C program demonstrates the implementation of a Disjoint Set Data Structure, also known as Union-Find. It provides functionalities for creating sets, finding sets, and performing union operations on sets.
