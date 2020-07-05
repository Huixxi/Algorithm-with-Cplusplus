class TreeAncestor {
public:
    int h = 0;
    vector<vector<int>> ast;
    TreeAncestor(int n, vector<int>& parent) {
        ast.push_back(parent);
        int cnt = 0;
        while(cnt != n) {
            cnt = 0;
            vector<int> tmp(n, -1);
            for(int i = 0; i < n; ++i) {
                tmp[i] = ast[h][i] == -1 ? -1 : ast[h][ast[h][i]];
                if(tmp[i] == -1)
                    ++cnt;
            }
            ast.push_back(tmp);
            ++h;
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k > pow(2, h)) return -1;
        int j = (1 << h);
        for(int i = 0; i <= h; ++i) {
            if(k & (j >> i)) {
                node = ast[h-i][node];
                if(node == -1)
                    return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
