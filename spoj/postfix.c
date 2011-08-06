/******************************************************************************
The postfix program.
The following explains how to write a program that uses a stack to evaluate a postfix expression, e.g., 3 4 * 5 +, directly. The algorithm is:
(1) As you read the expression from left to right, push each operand on the stack (here 3 and 4) until you encounter an operator (here, *).
(2) Pop the stack twice and perform a calculation using the operator and the two operands popped (here, 3*4 or 12). Push this result (here, 12) on the stack.
(3) Next push 5 on the stack and when the "+" is encountered, pop 5 and then 12 from the stack and get 5 + 12 or 17. Then push 17 onto the stack. Since there is no more data, pop the stack and obtain 17 as the final answer. If during the program you can't pop the stack or there is data remaining on the stack at the end, then our postfix expression is wrong.

Converting an Infix to a Postfix expression without parentheses
The algorithm is:

(1) As you read the input string from left to right, add each operand to the output string (in 3 * 4 + 5, add 3 to the output string). (2) When you encounter the first operator (here, *) push it on the stack.
(3) Add the next operand to the output string (it is now 3 4).
(4) When you encounter the next operator (here, +), while the operator on the stack top (here, *) has a higher or equal precedence to this operator, pop it and add it to the output string (it is now 3 4 *). Push the operator (here, +) on the stack.
(5) Continue this process until you read the entire input string (in our example, the output string becomes 3 4 * 5).
(6) Pop the stack and add the operators to the output string until the stack is empty (our output becomes 3 4 * 5 +).

Converting an Infix to a Postfix expression with parentheses.
When a '(' is encountered, its always pushed on the stack. When its on the stack, all incoming tokens (except the ")" ) have precedence over it and are pushed on the stack. When a ')' is encountered, everything on the stack to the first '(' is popped and added to the postfix expression. Then the '(' is popped and discarded.

Lets look at (2+3)/(4*5)

(1) The '(' is pushed.
(2) The 2 is added to the output.
(3) The '+' is pushed on the stack.
(4) The 3 is added to the out; its now 23.
(5) The ')' triggers the '+' to be popped and added to output; its now 23+.
(6) The '(' is popped and discarded.
(7) The '/' is pushed.
(8) The '(' is pushed.
(9) The 4 is added to the output; its now 23+4
(10) The "*' is pushed.
(11) The 5 is added to the output; its now 23+45
(12) The ')' triggers the '*' to be popped and added to output; its now 23+45*
(13) The '(' is popped and discarded.
(14) The eoln is now true, so if no invalid characters have been encountered. all the tokens remaining on the stack are popped and added to the output; its now 23+45
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 400

struct Stack    /*Definition of Stack*/
{
    char value;       
    struct Stack* prev;
};
typedef struct Stack stack;    /*Calling the structure Stack as stack*/

struct Stacki    /*Definition of Stack*/
{
    char value;       
    struct Stacki* prev;
};
typedef struct Stacki stacki;    /*Calling the structure Stack as stack*/

void push (stack** top,char ch);    /*Prototypes for the functions*/
void pushi (stacki** top,char i);    /*Prototypes for the functions*/
char pop (stack**);                    /*Push and Pop and peek respectively*/
char popi (stacki**);                    /*Push and Pop and peek respectively*/
char peek (stack**);
int prcdnce (char);                /*Returns the preceedance of the character*/

int main()
{
    int t = 0, T = 0;    
    scanf("%d",&T);	
    
	while (t++ < T)
	{
	    long int i=0,j=0,k=0;                /*counter*/
	    stack *top;        /*The topmost element of the stack*/
	    stacki *topi;
	    top = NULL;                /*the pointer to the topmost element is NULL*/
	    char infix[MAX];            /*Defining a string to store the infix*/
	    char postfix[MAX];            /*Defining a string to store the postfix*/
	    char a;
		
	    scanf("%s",infix);        /*Scanning the string*/

	    while( infix [ i ] != '\0')   
	    {
	        if ( infix[i]=='(')
	            push( & top , infix [i ++ ] );

	        else if (infix[i]==')')
	        {
	            while( peek ( &top ) != '(' )
	            {
	                postfix [ j++ ] = pop( & top );               
	            }
	           
	            pop( & top );  /*Discard the  '('  */
	            i++;
	        }
	       
	        else if ( isalpha ( infix [ i ] ) )
	            postfix [ j ++ ] = infix [ i ++ ];
	       
	        else if (top != NULL)
	        {
	            if ( prcdnce ( infix [ i ]) > prcdnce ( peek ( &top ) ) )
	                push( & top , infix [ i ++ ] );
	       
	            else
	            {
	                while ( prcdnce (infix [ i ]) <= prcdnce ( peek ( &top ) ) )
	                {
	                	 postfix[ j ++ ] = pop ( & top );
	                	 
	                	 if ( top == NULL)
	                        break;
	                }
	               
	                push( & top , infix [ i ++ ] );
	//  					postfix[j++] = infix[i++];
	            }
	        }   
	        else if (top == NULL)
	            push( & top , infix [ i ++ ] );
	    }
	   
	    while(top != NULL)
	    {
	        postfix[ j ++] = pop( & top );
	    }
	   
	    postfix[j]='\0';
	           
	    printf ("%s\n",postfix);
	}
return 0;            /*successful termination*/
}

void push (stack ** top, char ch)    /*Push function takes in the address of the*/
{                                    /*topmost pointer and the value for insertion*/
    stack *temp = (stack*) malloc (sizeof(stack));   
    /*A temporary pointer for storage*/
    temp -> value = ch;        /*value is stored in the temporary pointer*/
    temp -> prev = *top;    /*The temorary pointer in now put at the top*/
    *top = temp;            /*therefore it is the top now*/
    return;                    /*End of the function*/
}

void pushi (stacki ** top, char ch)    /*Push function takes in the address of the*/
{                                    /*topmost pointer and the value for insertion*/
    stacki *temp = (stacki*) malloc (sizeof(stacki));   
    /*A temporary pointer for storage*/
    temp -> value = ch;        /*value is stored in the temporary pointer*/
    temp -> prev = *top;    /*The temorary pointer in now put at the top*/
    *top = temp;            /*therefore it is the top now*/
    return;                    /*End of the function*/
}

char pop(stack **top)        /*The pop function takes in the address of the */
{                                    /*topmost element*/
    stack *temp = (*top);    /*Temporary alias for topmost element*/
    char ch;                /*Value to be popped*/
   
    ch = (*top) ->value;    /*ch is given the value supposed to be popped*/
    (*top) = (*top) -> prev;    /*Shift of the pointer*/
    free (temp);    /*Freeing the memory from which it was popped*/
    return ch;                /*end of the function returning the popped element*/
}

char popi(stacki **topi)        /*The pop function takes in the address of the */
{                                    /*topmost element*/
    stacki *temp = (*topi);    /*Temporary alias for topmost element*/
    char ch;                /*Value to be popped*/
   
    ch = (*topi) ->value;    /*ch is given the value supposed to be popped*/
    (*topi) = (*topi) -> prev;    /*Shift of the pointer*/
    free (temp);    /*Freeing the memory from which it was popped*/
    return ch;                /*end of the function returning the popped element*/
}


char peek (stack** top)        /*Peek function gives a peek of the topmost element*/
{
	if (*top == NULL);
	
    char ch = pop(top);        /*pops out the topmost element*/
   
    push(top,ch);            /*pushes the element back in*/
    return ch;                /*return the element that was peeked*/
}

int prcdnce (char ch)        /*The preceedence function*/
{                        /*takes in a character and returns its preceedence*/
    if((ch=='+') || (ch=='-'))
        return 1;
    else if ( (ch == '/' ) || ( ch == '\\' )||( ch == '*' ))
        return 2;
    else if ( (ch == '^'))
    	return 3;
    else if ( ( ch == '(' ) || ( ch == ')' ) )
        return 0;
}
