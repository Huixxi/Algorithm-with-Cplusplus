void heapify(vector<int>& points, int i, int len) {
    // min-heap sort
    int tmp = points[i];
    int left = 2 * i + 1;
    while(left < len) {
        if(left + 1 < len && points[left] > points[left + 1])
            ++left;
        if(tmp > points[left]) {
            points[i] = points[left];
            i = left;
            left = 2 * i + 1;
        }
        else
           break;
    }
    points[i] = tmp;
}

void heapSort(vector<int>& points) {
    int n = points.size();
    
    for(int i = n / 2 - 1; i >= 0; --i) 
        heapify(points, i, n);

    while(n > 0) {
        swap(points[0], points[n - 1]);
        heapify(points, 0, --n);
    }
}
