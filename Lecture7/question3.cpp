/* C++ Programming, Example answer, Exercise 3, Sheet 7  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 5th November 2001    */

/* This program creates and prints out a linked list of strings,
and tests the functions 'add_after' and 'delete_node'. */

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;
enum Logical
{
    False,
    True
};

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
    char word[MAX_WORD_LENGTH];
    Node_ptr ptr_to_next_node;
};

/* Function which returns 'True' if 'first' is alphabetically smaller than 'second' */
Logical string_smaller_than(char first[], char second[]);

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

/* Function to insert a node containing "word_after" after the first node
   containing "a_word" in "a_list". */
void add_after(Node_ptr &a_list, char a_word[], char word_after[]);

/* Function to delete the first node in "a_list" containing "a_word". */
void delete_node(Node_ptr &a_list, char a_word[]);

/* Function to sort "a_list" alphabetically. */
void string_selection_sort(Node_ptr &a_list);

/* Function to set 'smallest_node_ptr' to the alphabetically
   smallest node afer 'current_node_ptr' */
void set_to_smallest_after(Node_ptr current_node_ptr, Node_ptr &smallest_node_ptr);

/* Function to swap the contents of two string variables. */
void swap(char first[], char second[]);

/* MAIN PROGRAM */
int main()
{
    Node_ptr my_list = NULL;
    char a_word[MAX_WORD_LENGTH];
    char new_word[MAX_WORD_LENGTH];

    assign_list(my_list);

    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    cout << "\n\nAFTER WHICH WORD WOULD YOU LIKE TO ADD AN EXTRA WORD? ";
    cin >> a_word;
    cout << "WHICH WORD WOULD YOU LIKE TO ADD? ";
    cin >> new_word;
    add_after(my_list, a_word, new_word);
    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    cout << "\n\nWHICH WORD WOULD YOU LIKE TO DELETE? ";
    cin >> a_word;
    delete_node(my_list, a_word);
    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    string_selection_sort(my_list);
    cout << "\n\nAFTER SORTING, THE LIST IS:\n";
    print_list(my_list);
    cout << "\n";

    return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION string_smaller_than */
Logical string_smaller_than(char first[], char second[])
{
    int count = 0;

    while (first[count] != '\0' && second[count] != '\0')
    {
        if (first[count] < second[count])
            return True;
        if (first[count] > second[count])
            return False;
        count++;
    }

    if (first[count] == '\0' && second[count] != '\0')
        return True;
    else
        return False;
}
/*END OF FUNCTION */

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
    a_node = new Node;
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
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "add_after" */
void add_after(Node_ptr &a_list, char a_word[], char word_after[])
{
    Node_ptr current_node_ptr = a_list, extra_node_ptr;

    assign_new_node(extra_node_ptr);
    strcpy(extra_node_ptr->word, word_after);

    while (current_node_ptr != NULL)
    {
        if (!strcmp(a_word, current_node_ptr->word))
        {
            extra_node_ptr->ptr_to_next_node = current_node_ptr->ptr_to_next_node;
            current_node_ptr->ptr_to_next_node = extra_node_ptr;
            return;
        }
        current_node_ptr = current_node_ptr->ptr_to_next_node;
    }

    delete extra_node_ptr;
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "delete_node" */
void delete_node(Node_ptr &a_list, char a_word[])
{
    Node_ptr node_before_ptr = a_list, node_to_be_discarded_ptr = a_list;

    while (node_to_be_discarded_ptr != NULL)
    {
        if (!strcmp(a_word, node_to_be_discarded_ptr->word))
        {
            if (node_to_be_discarded_ptr == a_list)
                a_list = node_to_be_discarded_ptr->ptr_to_next_node;
            else
                node_before_ptr->ptr_to_next_node = node_to_be_discarded_ptr->ptr_to_next_node;
            delete node_to_be_discarded_ptr;
            return;
        }
        node_before_ptr = node_to_be_discarded_ptr;
        node_to_be_discarded_ptr = node_to_be_discarded_ptr->ptr_to_next_node;
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "string_selection_sort" */
void string_selection_sort(Node_ptr &a_list)
{
    Node_ptr current_node_ptr, smallest_node_ptr;

    current_node_ptr = a_list;

    while (current_node_ptr != NULL)
    {
        set_to_smallest_after(current_node_ptr, smallest_node_ptr);
        swap(current_node_ptr->word, smallest_node_ptr->word);
        current_node_ptr = current_node_ptr->ptr_to_next_node;
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "set_to_smallest_after" */
void set_to_smallest_after(Node_ptr current_node_ptr, Node_ptr &smallest_node_ptr)
{
    smallest_node_ptr = current_node_ptr;
    Node_ptr count_ptr = current_node_ptr->ptr_to_next_node;

    while (count_ptr != NULL)
    {
        if (string_smaller_than(count_ptr->word, smallest_node_ptr->word))
            smallest_node_ptr = count_ptr;
        count_ptr = count_ptr->ptr_to_next_node;
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "swap" */
void swap(char first[], char second[])
{
    char temp[MAX_WORD_LENGTH];
    strcpy(temp, first);
    strcpy(first, second);
    strcpy(second, temp);
}
/* END OF FUNCTION DEFINITION */
