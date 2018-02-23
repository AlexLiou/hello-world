#ifndef PA1
#define PA1

//Prints pointer array of Magic Square
void printArray(int** arr, int n);

//Sums up each row in pointer array, prints each row sum with space in front.
void checkRows (int** arr, int n);

//Sums up each column in pointer array, prints each column sum with space in front.
void checkColumns (int** arr, int n);

//Sum up both diagonals in pointer array, prints each diagonal sum with space in front.
void checkDiagonals (int** arr, int n);

#endif