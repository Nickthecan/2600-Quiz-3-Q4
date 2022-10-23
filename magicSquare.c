//Author: Nicholas Amancio
//CS2600 | Quiz 3 | 10/23/22

/* Question 4 : Lo Shu Magic Square
Create a program by simulating a magic square using a two-dimensional array. Write a 
function that accepts a two-dimensional array as an argument and determines whether the 
array is a Lo Shu Magic Square. Test the function in a program. 
1) Create the program and test with an array that is a Lo Shu Magic Square and test 
where it is not. The array’s can be defined in your main and should not need to be 
input from the user.
2) Create and populate a two-dimensional array with random numbers from 1-9. Recall 
no number should repeat when populating the array. Then check if it is a Lo Shu 
Magic Share. Put this random number placement in a loop until you do get a Lo Shu 
Magic Square.   Print two things:
a. The total number of squares generated and tested before success, the count.
b. Print the square and show the placement of values in the following format:
[a b c]
[d e f]
[g h i]
*/

/* Outline
Create a 2D array with variables a - i
use a randomizer to fill the array with different numbers, but no duplicates
Throw the array into a function that will determine whether or not it is a magic square
the function will add each row, column, and diagonal and will see if the 3 numbers add up to 15
if all of them equal 15, then return true
if one is not 15, return false
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

//implemented methods
void resetBoard();
void printBoard();
void getRandomNumbers();
void addNumberToArray(int number);
bool checkSquare();

//create the array with a magic square
int board[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

int main() {
    //prints out the board
    printBoard();

    //if-else statement to check whether it is a magic square or not
    if (checkSquare()) {
        printf("it is a magic Square");
    }
    else {
        printf("it is not a magic Square");
    }

} //end main 

//resets the board that was once populated with randomized numbers
void resetBoard() {
    //loop through the row
    for(int i = 0; i < 3; i++) {
        //loop through the column
        for (int j = 0; j < 3; j++) {
            //turn every number to an empty space
            board[i][j] = ' ';
        }
    }
}  //end resetBoard method

//prints out the magic square board
void printBoard() {
    //print out the board
    printf("\n %d | %d | %d ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %d | %d | %d ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %d | %d | %d ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}  //end printBoard method

//gets the random numbers and then calls the addNumberToArray method to assign the number to the board
void getRandomNumbers() {
    //variables
    int number = 0;
    int usedNumbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand(time(0));
    bool wasNumberUsed = true;

    //for loop to get the random numbers and to make sure that the number can be used since there cannot be any duplicates
    for (int i = 0; i < 9; i++) {
        //do while loop to check for any duplicates
        do {
            wasNumberUsed = true;
            //get the random number
            number = rand() % 9 + 1;

            if (usedNumbers[number - 1] == 0) {
                //assign the random number to the used numbers so the next time it runs through, it doesnt use that number
                usedNumbers[number - 1] = number;
                wasNumberUsed = false;
            } 
        } while (wasNumberUsed);
        //called method to add it to the array
        addNumberToArray(number);
    }
} //end getRandomNumbers

//adds the number to the board
void addNumberToArray(int number) {
    //uses a nested for loop in order to go through the the board and insert the number at the next free space
    for(int i = 0; i < 3; i++) {
        //loop through the column
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = number;
                return;
            }
        }
    }
} //end addNumberToArray

//checks each row, column, and diagonal to see if it equals 15
bool checkSquare() {

    for(int i = 0; i < 3; i++) {
        if (board[i][0] + board[i][1] + board[i][2] != 15) {
            return false;
        }
    }
    //check columns
    for(int i = 0; i < 3; i++) {
        if (board[0][i] + board[1][i] + board[2][i] != 15) {
            return false;
        }
    }
    //check diagonals
    if (board[0][0] + board[1][1] + board[2][2] != 15) {
            return false;
        }
    if (board[0][2] + board[1][1] + board[2][0] != 15) {
            return false;
        }

    return true;
} //end checkSquare