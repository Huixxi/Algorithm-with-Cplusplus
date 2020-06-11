void quickSort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int l = low;
        int h = high;
        int pivot = nums[l];

        while(l < h) {
            while (l < h && nums[h] >= pivot)
                --h;
            nums[l] = nums[h];
            while (l < h && nums[l] <= pivot)
                ++l;
            nums[h] = nums[l];
        }

        nums[l] = pivot;

        quickSort(nums, low, l-1);
        quickSort(nums, l+1, high);
    }
}
