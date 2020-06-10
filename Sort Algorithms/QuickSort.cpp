void quickSort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int l = low;
        int h = high;
        int pivot = nums[l];

        while(l < h) {
            while (l < h && nums[h] >= pivot)
                --h;
            nums[l] = nums[h];
            while (low < high && nums[low] <= pivot)
                ++low;
            nums[high] = nums[low];
        }

        nums[low] = pivot;

        quickSort(nums, low + 1, h);
        quickSort(nums, l, low - 1);
    }
}
