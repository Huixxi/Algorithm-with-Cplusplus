class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), miLen = n + 1;
        deque<int> dq;
        for(int i = 0; i < n; ++i) {
            if(i > 0)
                A[i] += A[i-1];
            if(A[i] >= K)
                miLen = min(miLen, i + 1);
            while(!dq.empty() && A[i] - A[dq.front()] >= K)
                miLen = min(miLen, i - dq.front()), dq.pop_front();
            while(!dq.empty() && A[i] <= A[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return miLen == n + 1 ? -1 : miLen;
    }
};
