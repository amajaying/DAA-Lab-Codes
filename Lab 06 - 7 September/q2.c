// Huffman coding assigns variable length codewords to fixed length input characters based on their frequencies or probabilities of occurrence. Given a set of characters along with their frequency of occurrences, write a c program to construct a Huffman tree.
// Note#
// · Declare a structure SYMBOL having members alphabet and frequency. Create a Min-Priority Queue, keyed on frequency attributes.
// · Create an array of structures where size=number of alphabets.
// Input:      
// Enter the number of distinct alphabets: 6
// Enter the alphabets:      a       b       c       d       e       f
// Enter its frequencies:    45     13     12     16     9       5
// Output:
// In-order traversal of the tree (Huffman): a  c  b  f  e  d

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char alphabet;
    int freq;
    struct node *left, *right;
};

struct node *newNode(char alphabet, int freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->alphabet = alphabet;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

struct minHeap
{
    int size;
    int capacity;
};
