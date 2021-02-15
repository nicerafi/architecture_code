#include <stdio.h>

double fact(double num) // Created a factorial function, which is vital in the NCR formula
{
    double k = 1, i;
    // factorial of 0 is 1
    if (num == 0)
    {
        return(k);
    }
    else
    {
        for (i = 1; i <= num; i++)
        {
            k = k * i; // Uses recusion to multiply by the old value by itself
        }
    }
    return(k);
}

double nCr(long int a, long int i) // nCr Function, doesn't use a array as we just need one value
{
    double nCr;
    nCr = (fact(a) / (fact(i)*fact(a-i))); // nCr Formula
    return nCr;
}

double fib(int a) // fib function calculates the corresponding fibonnaci number
{
    long int i = 0;
    double fib = 0;
    if (a == 0){ // I have assumed the 0th term of the fibonacci sequence is 0
        fib = 0;
    }
    else{
        a--;
        do {
            fib = fib + nCr(a, i); // Looking at the diagram it sum together the NCR value of the ath number on the ith row and decreases a and increases i until a = i
            a--; // Decrements a
            i++; // Increments i
        } while((a - i) >= 0); // Only does calculation until a - i >= 0
    }
    printf("%.0lf", fib); // Prints out our fibonacci number
    return fib;
}


int main()
{
    int fibinput;
    printf("Please enter term of fibonacci sequence wanted: ");
    scanf("%d", &fibinput);
    if((fibinput >= 0) && (fibinput <= 77)){ // After testing values I found that the limit of the fib function is 77.
        fib(fibinput);
    }
    else{
        printf("Error: Input is either too large or not a positive integer!"); // Prints out error if value isn't within the range of accepted values or a positive integer
    }
}
