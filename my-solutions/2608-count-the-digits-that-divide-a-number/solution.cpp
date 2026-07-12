class Solution {
public:
    int countDigits(int num) {
        int og = num;
        int digit;
        int count = 0;

        for (int i = og; i > 0; i /= 10) {
            digit = i % 10;

            if (digit != 0 && og % digit == 0) {
                count++;
            }
        }

        return count;
    }
};
