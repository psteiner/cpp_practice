#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

int CompareToMax(int array[], int n);
int CompareToAll(int array[], int n);

int main()
{
    const int arrSize = 10;
    int a[arrSize] = { 1, 3, 6, 13, 43, 8, 18, 7, 25, 33 };

    CompareToMax(a, arrSize);
    CompareToAll(a, arrSize);


    return 0;
}

/* Returns the largest integer in the array */
int CompareToMax(int array[], int n)
{
    int curMax, i;

    /* Make sure that there is at least one element in the array. */
    if (n <= 0)
        return -1;

    /* Set the largest number so far to the first array value. */
    curMax = array[0];

    /* Compare every number with the largest number so far. */
    for (i = 1; i < n; i++) {
         if (array[i] > curMax) {
             curMax = array[i];
         }
    }
    return curMax;
}

/* Returns the largest integer in the array */
int CompareToAll(int array[], int n)
{
   int  i, j;
   bool isMax;

   /* Make sure that there is at least one element in the array. */
   if (n <= 0)
       return -1;

   for (i = n-1; i > 0; i--) {
       isMax = true;
       for (j = 0; j < n; j++) {
           /* See if any value is greater. */
           if (array[j] > array[i])
               isMax = false; /* array[i] is not the largest value. */
        }
        /* If isMax is true, no larger value exists; array[i] is max. */
        if (isMax) break;
   }

return array[i];
}