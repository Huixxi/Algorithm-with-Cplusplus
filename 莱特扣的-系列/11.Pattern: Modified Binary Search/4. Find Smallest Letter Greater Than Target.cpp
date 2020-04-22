class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int n = letters.size();
        if(target < letters[0] || target > letters[n - 1])
            return letters[0];
        
        int start = 0, end = n - 1, mid = 0;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(letters[mid] == target)
                break;
            if(target > letters[mid]) 
                start = mid + 1;
            else 
                end = mid - 1;
        }
        while(mid < n) {
            if(letters[mid] > target)
                return letters[mid];
            ++mid;
        }
        return letters[0];
    }
};
