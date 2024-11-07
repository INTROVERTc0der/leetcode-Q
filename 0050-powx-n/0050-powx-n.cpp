class Solution {
public:
    double myPow(double x, int n) {
         if (n < 0) {
        x = 1 / x; // x^(-n) = 1 / x^n
        n = abs(n);    // Use the absolute value of n
    }

    double result = 1.0;
    double currentProduct = x;

    while (n > 0) {
        if (n % 2 == 1) {  // If n is odd
            result *= currentProduct;
        }
        currentProduct *= currentProduct;  // Square the base
        n /= 2;  // Divide n by 2
    }

    return result;
    }
};