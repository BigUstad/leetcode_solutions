class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ( nums1.size() == 0 || m == 0)
        {
            if ( m == 0)
            {
                nums1.clear();
            }
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());

            return;
        }
        if ( nums2.size() == 0 )
        {
            return;
        }
        auto nums1Itr = nums1.begin();
        auto nums2Itr = nums2.begin();
        int countInsert = 0;
        std::cout << " 0. Erasing " <<
            (nums1.end() - (nums1.begin() + m)) << std::endl;
        nums1.erase(nums1.begin() + m, nums1.end());
        nums1Itr = nums1.begin();
        if ( *nums1Itr > *nums2Itr )
        {
            while ( nums2Itr != nums2.end() )
            {
                if ( *nums1Itr >= *nums2Itr )
                {
                    //std::cout << " Comparing " << *nums1Itr << " " << *nums2Itr << std::endl;
                    nums2Itr++;
                }
                else
                    break;
            }
            countInsert++;
            if ( nums2Itr != nums2.end() )
            {
                nums1Itr = nums1.insert(nums1.begin(), nums2.begin(), nums2Itr);
                nums1Itr += (nums2Itr - nums2.begin()); 
                std::cout << " a.Insert at beginning." << (nums2Itr - nums2.begin())
                    << " " << *nums1Itr
                    << std::endl;
            }
            else
            {
                nums1Itr = nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
                nums1Itr += (nums2.end() - nums2.begin());
                std::cout << " b.Insert at beginning." << (nums2.end() - nums2.begin())
                    << " " << *nums1Itr
                    << std::endl;
            }
        }
        while ( nums1Itr != nums1.end()
                && nums2Itr != nums2.end() )
        {
            if ( *nums1Itr <= *nums2Itr )
            {
                
                while ( nums1Itr != nums1.end()
                        && *nums1Itr < *nums2Itr )
                {
                    nums1Itr++;
                    //std::cout << " Comparing " << *nums1Itr << " " << *nums2Itr << std::endl;
                }
                countInsert++;
                //std::cout << "2. Inserting after " << *nums1Itr << " " << *nums2Itr << std::endl;
                nums1Itr = nums1.insert(nums1Itr, *nums2Itr);
            }
            else // nums1Itr > nums2Itr
            {
                countInsert++;
                //std::cout << "3. Inserting after " << *nums1Itr << " " << *nums2Itr << std::endl;
                nums1Itr = nums1.insert(nums1Itr, *nums2Itr);                    
            }
            nums1Itr++;
            nums2Itr++;
        }
        if ( nums2Itr != nums2.end())
        {
            for ( ; nums2Itr != nums2.end(); nums2Itr++)
            {
                nums1.push_back(*nums2Itr);
            }
        }
        /*if ( nums1Itr != nums1.end() )
        {
            while ( nums1Itr != nums1.end() )
            {
                if ( *nums1Itr == 0 )
                {
                    nums1Itr = nums1.erase(nums1Itr);
                }
                else
                {
                    nums1Itr++;
                }
            }
        }*/
    }
};
