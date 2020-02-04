#include "leetcode.h"

int main() {
	vector<int> nums = { 5,7,7,8,8,10 };
    int a=INT_MIN;
    cout<<"a: "<<a<<endl;
    cout<<"nums.size()>INT_MIN: "<<(nums.size()>INT_MIN)<<endl;
    cout<<"nums.size()>0: "<<(nums.size()>0)<<endl;
    cout<<"nums.size()>-999: "<<(nums.size()>-999)<<endl;
	
	return 0;
}
