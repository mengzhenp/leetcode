class Solution {
public:
    
    bool guess(long mid, vector<int>& nums, int m)
    {
        long sum = 0;
        int mm = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if( sum + (long)nums[i] > mid )
            {
                sum = (long)nums[i];
                mm++;
                if(nums[i] > mid)
                {
                    return false;
                }
            }
            else
            {
                sum += (long)nums[i];
            }
        }
        
        return ( mm <= m );
    }
    
    
    int splitArray(vector<int>& nums, int m) 
    {
        long L = 0;
        //long R = (long)accumulate(nums.begin(), nums.end(), 0) + 1;
        long R = 0;
        for(int i=0; i<nums.size(); i++)
        {
            R += (long)nums[i];
        }
        
        long ans = 0;
        
        while(L <= R)
        {
            long mid = (L + R)/2;
            if(guess(mid, nums, m))
            {
                ans = mid;
                R = mid - 1 ;
            }
            else
            {
                L = mid + 1;
            }
        }
        
        return (int)ans;
        
    }
};