#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeofnums1 = nums1.size();
        int sizeofnums2 = nums2.size();
        int totalsize = sizeofnums1 + sizeofnums2;

        if(sizeofnums1 > sizeofnums2)
            return findMedianSortedArrays(nums2, nums1);
        
        int maxpart = totalsize/2;

        // Edge case where either list are empty
        // Below is the main logic
        // if(sizeofnums1 == 0){
        //     if(sizeofnums2 % 2 = 0)
        //         return (nums2[sizeofnums2 / 2]+nums2[sizeofnums2 / 2])/2);
        //     else 
        //         return (nums2[sizeofnums2/2]);
        // }
        if(!sizeofnums1==0)
            return ( ( sizeofnums2%2 == 0 ) ? ( ( nums2[sizeofnums2 / 2] + nums2[ (sizeofnums2/2)-1] ) / 2.0) : ( nums2[sizeofnums2 / 2] ) );
        // Similarly for nums2
        if(!sizeofnums2==0)
            return ( ( sizeofnums1%2 == 0 ) ? ( ( nums2[sizeofnums1 / 2] + nums2[ (sizeofnums1 / 2) - 1] ) / 2.0) : ( nums2[sizeofnums1 / 2] ) );

        // Working on the first array which is co nsidered small
        int l = 0, r = sizeofnums1;
        int c1, c2; // Cut indices
        int a,b,c,d; // a is left of nums1, b is right of nums1 and c,d are markers for nums2 in a similar fashion

        while(l <= r){ // This while loop works out the cut points and is similar to BS
            c1 = ( l + r )/2; // For first array, our first hit is the mid point
            c2 = maxpart - c1; // Since the value of c1 and c2 depend on each other and maxpart ultimately, we calculate c2 from c1 

            // c1 is the index before which an imaginary partition can be placed, a is before c1, c is at c1
            // Similar logic can be applied for other cases
            
            // It is important for the arbitrary values to be different, so -99999 and 99999 are also valid 
            // However, 
            a = c1 == 0 ? -100000 : nums1[c1-1];
            c = c2 == 0 ? -100000 : nums2[c2-1];
            b = c1 >= sizeofnums1 ? 100000 : nums1[c1]; // If cut1 value is greater than size of nums1, we assign an arbitrary large value
            d = c2 >= sizeofnums2 ? 100000 : nums2[c2];
            // However, for solving this problem, use INT_MIN and INT_MAX as there is a testcase with -100000 and 100000, leetcode being leetcode
            // Now we do the main check a < d and c < b
            // if(a < d && c < b){ // Answer Case
            //     if(totalsize%2==0)
            //         return (max(a,c) + min(b,d))/2;
            //     else
            //         return (max(a,c));
            // }
            if( a <= d && c <= b )
                return ( totalsize%2==0 ) ? ( max(a,c) + min(b,d) ) / 2 : max(a,c); 
            else{
                if(a > d)
                    r = c1 - 1;
                else
                    l = c1 + 1;
            }
        }
        return (double)0.0; // default
    }
};