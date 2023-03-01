using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        long long rem, rev = 0;
        long long n = (long long)x;
        while (n != 0)
        {
            rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        if (((long long)x == rev && x > 0) || (x == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};