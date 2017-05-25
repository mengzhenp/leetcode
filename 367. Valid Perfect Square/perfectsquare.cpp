/*
sqare num = 1 + 3 + 5 + 7 +.......
diagram:
*

.*
**

..*
..*
***

...*
...*
...*
****

*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        int upperbound = num;
        int sumOdds = 0;
        for (int i = 1; i <= upperbound; i++) {
            sumOdds += i * 2 - 1;
            if (sumOdds == num) return true;
            if (sumOdds < num) {
                upperbound = num/(i+1) + 1;
            } else {
                return false;
            }
        } 
        return false;
    }
};