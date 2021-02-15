#include <stdio.h>



double fact(double num) // Created a factorial function
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
            k = k * i; // Uses recursion to get factorial of desired number as it increments through values of i and multiplys it by itself
        }
    }
    return(k);
}

void nCr(long a)
{
    double nCr[a + 1]; // Creates array with size of a + 1 as the corresponding row of the pascal triangle has n + 1 elements
    long int i;
    long int loop;
    for(i = 0; i <= (a + 1); i++) // Loops through calculation until it has reached end of the array
        nCr[i] = (fact(a)) / ((fact(i))*(fact(a-i))); // Value of the ith element in the array would be the nCr of the index of the element
    for(loop = 0; loop < (a + 1); loop++) // Loops through each value in the array
        printf("%.0lf ", nCr[loop]); // Prints out each value of the nCr array

}


int main()
{
    long int row;
    printf("Enter the row number you want: ");
    scanf("%ld", &row);
    if ((row >= 35) || (row < 0)) { // Program seems to work best until 35th row (as it became quite hard to validate the output as the numbers get larger). We also check if the value is a positive integer
        printf("Error: Value is too high or not a positive integer!"); // Prints out error message
    }
    else{
        nCr(row);
    }
}
