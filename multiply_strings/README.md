Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


NAIVE - run time n^2 (Not yet implemented to handle carry)
        Goes through n by n size char array and handles long
        multiplication. C[j + k - 1] = A[j - 1] * B[k - 1],
        where j = size of array A, and k = size of array B;

    
    To finish :
        Handle carries
        Faster run time implementation ??¿¿