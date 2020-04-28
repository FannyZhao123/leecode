/*
1281. Subtract the Product and Sum of Digits of an Integer

Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

*/


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        int temp;
        int c = n;
        for (int i=0; pow(10, i) <= c; i++){
            temp = n % (10);
            n = (n - temp)/10; 
            p *= temp;
            s += temp;
        }
        return p-s;
    }
};


// better

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1,sum=0;
        while(n>0)
        {
            prod*=(n%10);
            sum+=(n%10);
            n /= 10;
        }
        return (prod-sum);
    }
};