class Solution {
public:
    bool checkRecord(string s) {
        int startlate = 0;
        int clateday = 0;
        int absentday = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                clateday++;
                if (clateday > 2) return false;
            } else {
                clateday = 0;
            }
            if (s[i] == 'A') {
                absentday++;
                if (absentday > 1) return false;
            }
        }
        return true;
    }
};