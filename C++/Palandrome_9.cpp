class Solution
{
public:
    bool isPalindrome(int x)
    {
        long long rem, rev = 0;     // Long is used here just to accomodate the large numeric values
        long long n = (long long)x; // Type casting int x (Used wherever we want to do long long related operations)
        while (n != 0)
        {
            // Loop iterates until n is NOT 0
            rem = n % 10; // We store the remainder in rem
            n /= 10; // Value reduced by one order of 10
            rev = rev * 10 + rem;  // We reconstruct the reverse number using this formula and the loop iterations
        }
        if (( (long long) x == rev && x > 0) || (x==0)) // Considering the given conditions
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};