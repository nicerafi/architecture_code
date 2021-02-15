#include <stdio.h>

int main(void)
{
    int a;
    int b;
    printf("Enter two positive integers: ");
    scanf("%d%d", &a, &b);

    if((a > 0) && (b > 0)){
        while(b != 0) { // Keeps on looping while b is not 0
            if (a > b) // Checks which of the integers is larger
                a=a-b;
            else
                b=b-a;
        }
        printf("GCD is %d\n", a); // Prints out the GCD of the two given numbers
    }
    else{
        printf("Error: Values inputted aren't positive integers"); // Prints error if values aren't positive integers
    }
}
