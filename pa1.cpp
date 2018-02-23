#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pa1.h"

using namespace std;

void printArray (int** arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void checkRows (int** arr, int n)
{
    printf("Checking the sum of every row: ");
    for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += arr[i][j];
		}
		printf("%d ", sum);
	}
}

void checkColumns (int** arr, int n)
{
    printf("Checking the sum of every column: ");
    for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += arr[j][i];
		}
		printf("%d ", sum);
	}

}

void checkDiagonals (int** arr, int n)
{
    printf("Checking the sum of every diagonal: ");
    int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i][i];
	}
	printf("%d ", sum);

	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum2 += arr[n - 1 - i][i];
	}
    printf("%d ", sum2);
}

int main()
{

    printf("Enter the size of a magic square: ");
    int n = 0;
    cin >> n;

    int** magicSquare = new int*[n];
    for (int i = 0; i < n; i++) { 
        magicSquare[i] = new int[n]; 
    }

    for (int i = 0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            magicSquare[i][j]=0;
        }
    }

    //Creates Magic Square
    int i = n/2;
    int j = n-1;

    for (int num=1; num <= n*n;)
    {
        if (i==-1 && j==n)
        {
            j = n-2;
            i = 0;
        }
        else 
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n-1;
        }
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        } 
        else
            magicSquare[i][j] = num++; 

            j++; i--;
    }
    //Prints Array
    int count =1;
    int set = 1;
    bool flipx = 1;
    do {
        printf("Magic Square #%d is: ", count);
        printf("\n");
        printArray(magicSquare,n);

        printf("\n");
        checkRows(magicSquare,n);
        printf("\n");
        checkColumns(magicSquare, n);
        printf("\n");
        checkDiagonals(magicSquare, n);
        count++;
        //Reflect Array, x axis if 1 is on top or bottom edge, y axis if 1 is on left or right edge.
        int** refArr = magicSquare;
        printf("\n");
        if (flipx == 0)
        {
            for (int i=0; i < n; i++)
            {
                for (int j=0; j< n / 2; j++)
                {
                    int temp = refArr[i][j];
                    refArr[i][j] = refArr[i][n-1-j];
                    refArr[i][n-1-j] = temp;
                }

            }
        } else {
            for (int i=0;i < n; i++)
            {
                for (int j=0; j< n / 2; j++)
                {
                    int temp = refArr[j][i];
                    refArr[j][i] = refArr[n-1-j][i];
                    refArr[n-1-j][i] = temp;
                }
            }
        }
        printf("Magic Square #%d is: ", count);
        printf("\n");
        printArray(refArr,n);
        printf("\n");
        checkRows(refArr,n);
        printf("\n");
        checkColumns(refArr, n);
        printf("\n");
        checkDiagonals(refArr, n);
        printf("\n");
        count++;


        //Rotates Array

        int** rotArr = magicSquare;
        for (int x = 0; x < n / 2; x++)
        {
            for (int y = x; y < n-x-1; y++)
            {
                int temp = rotArr[x][y];
                rotArr[x][y] = rotArr[y][n-1-x];
                rotArr[y][n-1-x] = rotArr[n-1-x][n-1-y];
                rotArr[n-1-x][n-1-y] = rotArr[n-1-y][x];
                rotArr[n-1-y][x] = temp;
            }
        }
        magicSquare = rotArr;
        set++;
        if (flipx == 1){
            flipx = 0;
        } else if (flipx == 0){
            flipx = 1;
        }
    } while (set <= 4);

    if (n == 3){
        printf("\n");
        printf("No more possible magic squares combinations.");
        printf("\n");
    } else {
        //Bachet de Meziriac Method

        int** magicSquare = new int*[n];
        for (int i = 0; i < n; i++) { 
            magicSquare[i] = new int[n]; 
        }

        for (int i = 0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                magicSquare[i][j]=0;
            }
        }

        int i = n / 2;
        int j = (n/2) + 1;
        int previ = 0;
        int prevj = 0;
        for (int num=1;num<=n*n;)
        {
            if (i==-1 && j==n)
            {
                i = 0;
                j = 1;
            } else 
            {
                if (j == n)
                {
                    j = 0;
                }
                if (i < 0){
                    i = n-1;
                }
            }

            if (magicSquare[i][j])
            {
                i++; j++;
            } else
            {
                magicSquare[i][j] = num++;
                i--; j++;

            }
        }
        
        
        printf("Magic Square #9 is: ");
        printf("\n");
        for (int i = 0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                printf("%d ", magicSquare[i][j]);
            printf("\n");
        }
        printf("\n");
        checkRows(magicSquare,n);
        printf("\n");
        checkColumns(magicSquare, n);
        printf("\n");
        checkDiagonals(magicSquare, n);
        printf("\n");

        //Previous square but rotated
        printf("Magic Square #10 is: ");
        printf("\n");
        int** rotArr = magicSquare;
        for (int x = 0; x < n / 2; x++)
        {
            for (int y = x; y < n-x-1; y++)
            {
                int temp = rotArr[x][y];
                rotArr[x][y] = rotArr[y][n-1-x];
                rotArr[y][n-1-x] = rotArr[n-1-x][n-1-y];
                rotArr[n-1-x][n-1-y] = rotArr[n-1-y][x];
                rotArr[n-1-y][x] = temp;
            }
        }
        for (int i = 0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                printf("%d ", rotArr[i][j]);
            printf("\n");
        }
        printf("\n");
        checkRows(rotArr,n);
        printf("\n");
        checkColumns(rotArr, n);
        printf("\n");
        checkDiagonals(rotArr, n);
        printf("\n");

    }
    return 0;
}