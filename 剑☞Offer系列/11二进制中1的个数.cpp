class Solution {
public:
     int NumberOf1(int n) {
         // 计算机中的负数以补码形式存储
         int unit = 1, count = 0;
         while(unit) {
             if(n & unit)
                 ++count;
             unit <<= 1;
         }
         return count;
     }
};
