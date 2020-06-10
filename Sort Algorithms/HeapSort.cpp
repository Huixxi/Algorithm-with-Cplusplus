void heapify(vector<int>& points, int i, int len) {
    // min-heap sort 最小堆
    int tmp = points[i];  // i：父节点
    int left = 2 * i + 1;  // 左子节点
    while(left < len) {  // 若子节点在范围内
        if(left + 1 < len && points[left] > points[left + 1])  // 比较两个子节点的大小，选择最小的
            ++left;
        if(tmp > points[left]) {  // 因为是最小堆，若父节点大于子节点：交换父子节点内容，继续子节点和孙节点比较
            points[i] = points[left];
            i = left;
            left = 2 * i + 1;
        }
        else // 调整完成
           break;
    }
    points[i] = tmp;
}

void heapSort(vector<int>& points) {
    int n = points.size();
    // 第一步：将数组堆化，i从最后一个父节点开始调整
    for(int i = n / 2 - 1; i >= 0; --i) 
        heapify(points, i, n);
    // 第二步：对堆化数据排序
    while(n > 0) {
        // 每次都是移出最顶层的根节点A[0]，与最尾部节点位置调换，同时遍历长度 -1
        swap(points[0], points[n - 1]);
        // 然后重新整理被换到根节点的末尾元素，使其符合堆的特性
        heapify(points, 0, --n);
    }
}
