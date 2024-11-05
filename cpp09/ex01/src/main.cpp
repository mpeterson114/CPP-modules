#include "RPN.hpp"

/* In RPN, operators act on the most recent numbers in the expression. Stack operates as a LIFO 
structure and naturally allows access to the most recent operands.
When operator is encountered, "pop" the two most recent numbers from the stack, perform the operation, 
then "push" the result back onto the stack. This mirrors the way RPN expressions are intended to be evaluated. */

int main(int argc, char **argv)
{
    
}