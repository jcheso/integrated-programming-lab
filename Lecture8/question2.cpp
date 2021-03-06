/* Program 7.5.1 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 28th September 2013    */

/* This program creates and prints out a linked list of strings. */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
    char word[MAX_WORD_LENGTH];
    Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

void print_list_forwards(Node_ptr a_node);

void print_list_backwards(Node_ptr a_node);

void print_list_backwards_iterative(Node_ptr a_node);

/* MAIN PROGRAM */
int main()
{
    Node_ptr my_list = NULL;

    assign_list(my_list);

    cout << "\nTHE LIST FORWARDS IS:\n";
    print_list_forwards(my_list);
    print_list_backwards(my_list);
    print_list_backwards_iterative(my_list);
    return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION "assign_list" */
void assign_list(Node_ptr &a_list)
{
    Node_ptr current_node, last_node;

    assign_new_node(a_list);
    cout << "Enter first word (or '.' to end list): ";
    cin >> a_list->word;
    if (!strcmp(".", a_list->word))
    {
        delete a_list;
        a_list = NULL;
    }
    current_node = a_list;

    while (current_node != NULL)
    {
        assign_new_node(last_node);
        cout << "Enter next word (or '.' to end list): ";
        cin >> last_node->word;
        if (!strcmp(".", last_node->word))
        {
            delete last_node;
            last_node = NULL;
        }
        current_node->ptr_to_next_node = last_node;
        current_node = last_node;
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "assign_new_node" */
void assign_new_node(Node_ptr &a_node)
{
    a_node = new (nothrow) Node;
    if (a_node == NULL)
    {
        cout << "sorry - no more memory\n";
        exit(1);
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "print_list" */
void print_list(Node_ptr a_node)
{
    while (a_node != NULL)
    {
        cout << a_node->word << " ";
        a_node = a_node->ptr_to_next_node;
    }
}

void print_list_forwards(Node_ptr a_node)
{
    // If a_node->ptr_to_next_node == NULL; return
    // Else
    // cout << a_node->word
    // return (a_node->ptr_to_next_node)

    if (a_node->ptr_to_next_node == NULL)
    {
        cout << a_node->word << " ";
        return;
    }
    else
    {
        cout << a_node->word << " ";
        return print_list_forwards(a_node->ptr_to_next_node);
    }
}

void print_list_backwards(Node_ptr a_node)
{
    if (a_node->ptr_to_next_node != NULL)
    {
        print_list_forwards(a_node->ptr_to_next_node);
        cout << a_node->word << " ";
    }
    else
    {
        return;
    }
}

void print_list_backwards_iterative(Node_ptr a_node)
{
    vector<string> myArrayOfStrings(100);
    char *words = new char[255];
    int i = 0, j = 0;
    while (a_node->ptr_to_next_node != NULL)
    {
        cout << a_node->word << endl;
        myArrayOfStrings[i] = a_node->word;
        a_node = a_node->ptr_to_next_node;
        i++;
    }
    myArrayOfStrings[i] = a_node->word;
    while (i >= 0)
    {
        for (char n : myArrayOfStrings[i])
        {
            cout << n;
        }
        cout << " ";
        i--;
    }
    cout << "test" << endl;
    // Iterate through list and copy word to array;
    // When hit end of list, break while, iterate through array backwards and print words;
}
/* END OF FUNCTION DEFINITION */