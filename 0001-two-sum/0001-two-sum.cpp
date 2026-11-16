class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int, int>mp;
for(int i = 0; i <nums.size();i++){
    int wanted = target - nums[i];
    if(mp.count(wanted)){
        return {mp[wanted], i};
    }
    mp[nums[i]] = i;
}
return {};
    }
};