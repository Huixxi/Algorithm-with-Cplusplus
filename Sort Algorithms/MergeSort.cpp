void merge(vector<int>& nums, int l, int m, int h) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;

    int tmp1[n1], tmp2[n2];

    for(i = 0; i < n1; ++i)
        tmp1[i] = nums[l + i];
    for(j = 0; j < n2; ++j)
        tmp2[j] = nums[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(tmp1[i] < tmp2[j]) {
            nums[k] = tmp1[i];
            ++i;
        }
        else {
            nums[k] = tmp2[j];
            ++j;
        }
        ++k;
    }

    while(i < n1) {
        nums[k] = tmp1[i];
        ++i;
        ++k;
    }

    while(j < n2) {
        nums[k] = tmp2[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
}
