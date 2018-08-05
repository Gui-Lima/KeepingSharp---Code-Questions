#include "iostream"
#include "algorithm"
#include "bitset"
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
    Notice the pattern, in the column 0, is 0 1 0 1 0 1
                        in the column 1, is 00 11 00 11 00 11
 *                      in the column 2, is 0000 1111 0000 1111
 *
 *  We will use this to count the zeros
 */

long long pattern(long long num, int cipher)

{

    long long bit = 1 << cipher;

    long long chain = num >> (cipher + 1);

    return chain * bit;

}



long long restOfBinary(long long num, int cipher)

{

    long long bit = 1 << cipher;

    long long rest = num % (bit << 1);

    return max((long long)0, (rest - bit) + 1);

}



long long column(long long num, int cipher) {
    /* Go search in the column for the number of 'ones'
     * The column we are looking at is represented by the cipher
     * being 0 the leftmost column.
     * So at each column we are counting the number of '1' in that column
     * By using the pattern commented in the beginning of the code
     */

    return pattern(num, cipher) + restOfBinary(num, cipher);

}



long long addUpTo(long long num) {
    /* Here we get a number, then keeps adding the one to the total
    *  We make Offsets starting from 0 until the number is 0, this is to check
    *  if there are any ones left
    *
    */

    long long bit = 0, total = 0;

    while ((num >> bit) > 0)

        total += column(num, bit++);

    return total;

}



long long countOnes(long long left, long long right) {
    //Adding all 1-digits from 0 to the highest number(right)
    //Adding all 1-digits from 0 to the lowest number-1(left-1)
    //Subctract it to obtain the real number

    return addUpTo(right) - addUpTo(left - 1);

}



int main(void)

{

    cout << countOnes(4, 8) << endl;

    return 0;

}