class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]=i;
        }
        vector<int> result(2);
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(mymap.count(t)&&mymap[t]!=i){
                result[0]=i;
                result[1]=mymap[t];
                return result;
            }
        }
        return result;
    }
};
