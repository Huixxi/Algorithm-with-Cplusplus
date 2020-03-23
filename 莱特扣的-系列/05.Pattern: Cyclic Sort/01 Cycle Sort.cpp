// C++ Version
void cycleSort(vector<int>& array) {
    const int l = array.size();
    // Loop through the array to find cycles to rotate.
    for(int i = 0; i < l - 1; ++i) {
        int item = array[i];
        
        // Find where to put the item.
        int pos = i;
        for(int j = i + 1; j < l; ++j) 
            if(array[i] < item)
                ++pos;
                
        // If the item is already there, this is not a cycle.
        if(pos == i)
            continue;
            
        // Otherwise, put the item there or right after any duplicates.
        while(item == array[pos])
            ++pos;
        
        // Swap.
        int temp = item;
        item = array[pos];
        array[pos] = temp;

        // Rotate the rest of the cycle.
        while(pos != i) {
            // Find where to put the item.
            pos = i;
            for(int j = i + 1; j < l; ++j) 
                if(array[i] < item)
                    ++pos;

            // If the item is already there, this is not a cycle.
            if(pos == i)
                continue;

            // Otherwise, put the item there or right after any duplicates.
            while(item == array[pos])
                ++pos;
                
            // Otherwise, put the item there or right after any duplicates.
            while(item == array[pos])
                ++pos;

            // Swap.
            int temp = item;
            item = array[pos];
            array[pos] = temp; 
        }
    }
}
