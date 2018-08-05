#include "iostream"
#include "algorithm"
#include "bitset"
#include "math.h"

using namespace std;


/*      4   3   2   1   0
 * 0    0   0   0   0   0
 * 1    0   0   0   0   1
 * 2    0   0   0   1   0
 * 3    0   0   0   1   1
 * 4    0   0   1   0   0
 * 5    0   0   1   0   1
 * 6    0   0   1   1   0
 * 7    0   0   1   1   1
 * 8    0   1   0   0   0
 * 9    0   1   0   0   1
 * 10   0   1   0   1   0
 * 11   0   1   0   1   1
 * 12   0   1   1   0   0
 * 13   0   1   1   0   1
 * ...
    Notice the onesBeforeCurrentPattern, in the column 0, is 0 1 0 1 0 1
                        in the column 1, is 00 11 00 11 00 11
 *                      in the column 2, is 0000 1111 0000 1111
 *
 *  We will use this to count the zeros
 */

long long onesBeforeCurrentPattern(long long num, int currentColumn) {
/*  Here we get all the ones that happened before the current pattern,
 *  basically we just have to discover the size of the onesBeforeCurrentPattern, that we now by 2^current column
 *  and how many patterns occurred until now, that we know by dividing the num by the current column(+1 couse 0) Universe explodes
 *
 */
    long long patternSizeOnThisColumn = (long long) pow(2, currentColumn);

    long long numbersOfPatternsUntilNum = num >> (currentColumn + 1);

    return patternSizeOnThisColumn * numbersOfPatternsUntilNum;

}



long long onesInCurrentPattern(long long num, int currentColumn) {
       /* First we ask where the number (num) is on the current pattern
        * As in '9' in the second column(1) is on the second zero of the pattern.(00 11 00)
        * So this function should return 0, since there is no ones in the current pattern
        * As in '12' in the fourth column(3) is on the fifth one of the onesBeforeCurrentPattern(00000000 11111111)
        */

    long long patternSizeOnThisColumn = (long long) pow(2, currentColumn);

    long long numberOfOnesInThisPatternUntilNum = num % (patternSizeOnThisColumn << 1);

    //the max is just to get edge cases where this could be negative
    return max((long long)0, (numberOfOnesInThisPatternUntilNum - patternSizeOnThisColumn) + 1);

}



long long column(long long num, int currentColumn) {
    /* Go search in the column for the number of 'ones'
     * The column we are looking at is represented by the currentColumn
     * being 0 the leftmost column.
     * So at each column we are counting the number of '1' in that column
     * By using the onesBeforeCurrentPattern commented in the beginning of the code
     */

    return onesBeforeCurrentPattern(num, currentColumn) + onesInCurrentPattern(num, currentColumn);

}



long long addUpTo(long long num) {
    /* Here we get a number, then keeps adding the one to the total
    *  We make Offsets starting from 0 until the number is 0, this is to check
    *  if there are any ones left
    *
    */

    long long currentColumn = 0, onesTotal = 0;

    while ((num >> currentColumn) > 0)

        onesTotal += column(num, currentColumn++);

    return onesTotal;

}



long long countOnes(long long left, long long right) {
    //Adding all 1-digits from 0 to the highest number(right)
    //Adding all 1-digits from 0 to the lowest number-1(left-1)
    //Subctract it to obtain the real number

    return addUpTo(right) - addUpTo(left - 1);

}
