class Solution {
public:
    /*
    vector<int> parseString(string a) {
        bool negative = false;
        int i = 0;
        if (a.at(0) == '-') {
            i++;
            negative = true;
        }
        int real = 0;
        while (a.at(i) != '+') {
            real = real * 10 + a.at(i) - '0';
        }
        if (negative) {
            real = -real;
            negative = false;
        }
        int complex = 0;
        i++;
        if (a.at(i) == '-') {
            i++;
            negative = true;
        }
        while (i < a.length()) {
            complex = complex * 10 + a.at(i) - '0';
        }
        if (negative) complex = -complex;
        return {real, complex};
    }
    */
    string complexNumberMultiply(string a, string b) {
        int ra, rb, ia, ib;
        char buf;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buf >> ia >> buf;
        bb >> rb >> buf >> ib >> buf;
        int c = ra * rb - ia * ib;
        int d = ra * ib + ia * rb;
        ans << c << "+" << d << "i";
        return ans.str();
    }
};