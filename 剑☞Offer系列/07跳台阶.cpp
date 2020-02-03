class Solution {
public:
    int jumpFloor(int number) {
        if(number == 2)
            return 2;
        if(number == 1)
            return 1;
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
