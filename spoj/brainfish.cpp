/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE 512000
#define MAX_MEM 32768

#define DEBUG 0
char code [ MAX_CODE ];             // Contains the code for execution
char memory[ MAX_MEM ] = {0};       // Contains the memory involved
long int memPtr = 0;                // Points to the current memory location

void brackets ( long int * startPtr )
{
    long int codePtr = *startPtr;
    int flag = true;

    while( flag ) {
        codePtr ++;
        switch ( code [ codePtr ] ) 
        {
            case '+':
                memory [ memPtr ] ++;
                break;
            case '-':
                memory [ memPtr ] --;
                break;
            case '.':
                putchar( memory [ memPtr ] );
                break;                            
            case ',':
                memory [ memPtr ] = getchar();
                break;        
            case '<':
                memPtr = (memPtr - 1) % MAX_MEM;
                break;
            case '>':
                memPtr = (memPtr + 1) % MAX_MEM;
                break;
            case '[':
                brackets ( & codePtr );
                break;
            case ']':
                if ( memory [ memPtr ] == 0 ) {
                    flag = false;
                    *startPtr = codePtr;                   
                }
                else {
                    codePtr = * startPtr;
                }
                break;
            default:     // Any other character for commenting purposes
                break;                                                                
        }
    }
    
}

#if DEBUG
int printCode( char * code, long int codeSize )
{
    for ( int i = 0 ; i < codeSize ; i ++ ) {
        putchar(code[i]);
    }
    return 0;
}
#endif
int main()
{
    long int codePtr = 0;           // Points to the current instruction
    char ch;                        // A temporary character
    long int codeSize;              // The size of the code
    long int balNo;                 // The balance number 
    int error = false;              // Indicates compiler error
    // ( balance number is needed for compilation error check )
    while ( ! feof (stdin) ) {
        if ( (ch = getchar())) {
            if ( ch == '%' ) {
                while((ch = getchar()) != '\n') {}
            }
            else {
                code [ codePtr ++ ] = ch;
            }
        }
    }
    codeSize = codePtr;
#if DEBUG    
     printCode(code, codeSize);
#endif
    // Compilation check. Check for unbalanced parantheses error
    for ( codePtr = 0 , balNo = 0 ; codePtr < codeSize ; codePtr ++ ) {
        if ( code [ codePtr ] == '[' )
            balNo ++;
        else if ( code [ codePtr ] == ']' ) {
            balNo --;
            if ( balNo < 0 ) {
                error = true;
                break;
            }
        }
    }
    if ( balNo != 0 )
        error = true;
    if ( error ) {
        printf("COMPILE ERROR");
        return 0;
    }
    
    for ( codePtr = 0 ; codePtr < codeSize ; codePtr ++ ) {
        switch (code [ codePtr ]) {
            case '+':
                memory [ memPtr ] ++;
                break;
            case '-':
                memory [ memPtr ] --;
                break;
            case '.':
                putchar( memory [ memPtr ] );
                break;
            case ',':
                memory[ memPtr ] = getchar();
                break;
            case '<':
                memPtr = ( memPtr - 1 ) % MAX_MEM;
                break;
            case '>':
                memPtr = ( memPtr + 1 ) % MAX_MEM;
                break;
            case '[':
                brackets ( & codePtr );
                break;
            case ']':
                break;
            default :       // Other character for commenting purposes
                break;
        }
    }
}


