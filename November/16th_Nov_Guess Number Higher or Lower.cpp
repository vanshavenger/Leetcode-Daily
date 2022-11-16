/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long st = 1;
        long long et = n;
        while(st <= et){
            long long mid = st + (et - st)/2;
            if(guess(mid) == 0){
                return (int)mid;
            }
            else if(guess(mid) == -1){
                et = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return -1;
    }
};
