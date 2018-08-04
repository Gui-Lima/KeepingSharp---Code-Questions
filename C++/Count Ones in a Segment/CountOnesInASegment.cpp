#include "iostream"
#include "algorithm"
#include "bitset"
using namespace std;

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

    return max((long long)0, rest - bit + 1);

}



long long column(long long num, int cipher) {

    return pattern(num, cipher) + restOfBinary(num, cipher);

}



long long addUpTo(long long num) {
    /*  
    * 
    * 
    */
    
    long long bit = 0, total = 0;

    while ((num >> bit) > 0) //자릿수가 존재할때까지 각 세로줄을 다 더한다

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

    cout << countOnes(4, 7) << endl;

    return 0;

}