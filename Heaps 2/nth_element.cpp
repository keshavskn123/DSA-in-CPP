#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {2,1,3,3,5};
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // nth_element(nums.begin(), nums.begin()+2, nums.end());      // For sorting in ascending order
    nth_element(nums.begin(), nums.begin()+2, nums.end(), greater<int>());       // For sorting in descending order 
    
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}