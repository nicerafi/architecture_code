#include <stdio.h>
#include <math.h> // Uses math.h for power function

int bintodenary(char *a){
    int sum = 0;
    int j = 1; // Iterates through the array on the 1st index as the MSB is our sign bit
    do {
        if (a[j] == '1'){ // Iterates through the binary number
            sum = sum + pow(2, (7 - j)); // Using power function from the math library
            j++; // Increments j to go to the next value in the array
        }
        else{
            j++;
        }
    } while (j <= (sizeof(a) - 1)); // As the 8th bit is the sign bit, we don't want to include it when getting the absolute value of the sum
    if (a[0] == '1'){ // Checks if the MSB is a 1, meaning out answer would be negative.
        sum = sum * (-1); // Multiplies our answer by -1
    }
    return sum;
}

int abs(int b){ // Created a function to get the absolute value of the binarytodenary value so I can use it for finding twos complement
    if (b < 0) {
        b = b * (-1);
    }
    return b;
}

int twoscomp(int a){
    int b = abs(a);
    int twocomp[16]; // Storing number in a 16 bit binary number as it can account for all possible numbers created by the addition of the two sign magnitude numbers, this is probably overkill as a 9 bit TC number could hold every combination.
    int i = 15;
    int j = 0;
    int loop;
    int store;
    if (a < 0){ // As we are using 16 bits only the last 8 bits are affected by the TC calculation
        do {
            twocomp[j] = 1;
            j++;
        } while (j <= 7);
    }
    else{
        do {
            twocomp[j] = 0;
            j++;
        } while (j <= 7);
    }
    if (a != 0){ // Only finds the TC value if the input isn't 0
        do {
            twocomp[i] = b % 2;
            b = b / 2;
            i--;
        } while (i >= 8);
        if (a < 0){ // If the original input is negative it will go through the necessary process of inverting bits and adding 1
            for (i = 8; i <= 15; i++) {
                if (twocomp[i] == 1) { // invert bits
                    twocomp[i] = 0;
                }
                else{
                    twocomp[i] = 1;
                }
            }

            if (twocomp[15] == 1) { // This adds 1 to the LSB and accounts for overflow
                i = 15;
                store = twocomp[15]; // Stores original value to compare and see if we should carry the one to the next bit
                while (store == 1) {
                    twocomp[i] = 0;
                    store = twocomp[i - 1];
                    twocomp[i - 1] = 1;
                    i--;
                }
            }
            else{ // Just adds 1 if the LSB is 0
                twocomp[15] = 1;
            }
        }
    }
    else{ // If the number inputted into the function is a zero just gives us 0000000000000000
        do {
            twocomp[j] = 0;
            j++;
        } while (j <= 15);
    }
    for(loop = 0; loop < 16; loop++){ // Prints out the output
        printf("%d ", twocomp[loop]);
    }
    return 0;
}

int binarychecker(char *a){
    int j;
    int check = 0;
    for (j = 0; j <= 7; j++) {
        if (a[j] == '0'){ // Checks if value in the binary char array are 1 or 0 and increments our checksum if there is one
            check++; //Adds 1 to the checksum
        }
        else if (a[j] == '1'){
            check++;
        }
        else{
            check--;
        }
    }
    return check;
}

int main()
{
    char binary1[9]; // Using char arrays as it is much easier to get user inputs
    char binary2[9];
    int sumofsign;
    printf("Enter First Binary Number: ");
    scanf("%s", binary1); // scanf takes in the users input
    printf("Enter Second Binary Number: ");
    scanf("%s", binary2);
    if (((binarychecker(binary1)) == 8) && (binarychecker(binary2) == 8)) { // Checks if values are binary numbers (they are valid inputs
        sumofsign = bintodenary(binary1) + bintodenary(binary2);
        twoscomp(sumofsign);
    }
    else{
        printf("Error: Values inputted arent 8 bit binary numbers!");
    }
}
