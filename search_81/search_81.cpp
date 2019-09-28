// search_81.cpp : 定义控制台应用程序的入口点。
//
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//判断left--right直接数据是否完全相同
bool Judge(vector<int>& nums, int left, int right)
{
	if (right - left < 2)return true;
	int mid = (left + right) / 2;
	if (nums[mid] != nums[left])return false;
	if (Judge(nums,left,mid)&&Judge(nums,mid+1,right))
	{
		return true;
	}
	return false;
}

bool searchNum(vector<int>& nums, int target, int left, int right)
{
	if (left == right)
	{
		if (nums[left] == target)
		{
			return true;
		}
		return false;
	}
	if (left > right)return false;

	int mid = (left + right) / 2;
	if (nums[mid] == target)return true;

	//升序4,5,6,7
	if (nums[right] > nums[left])
	{
		if (nums[mid] >= target)
		{
			return searchNum(nums, target, left, mid);
		}
		else if (nums[mid] < target)
		{
			return searchNum(nums, target, mid + 1, right);
		}
	}
	//4,5,6,7,0,1,2
	else
	{
		//1,1,3,1
		if (nums[left]==nums[mid]&& nums[mid] ==nums[right])
		{
			if (Judge(nums, left, mid))
			{
				return searchNum(nums, target, mid + 1, right);
			}
			else
			{
				return searchNum(nums, target, left, mid);
			}
		}
		//left 升序4,5,6,7
		if (nums[mid] >= nums[left])
		{
			if (nums[mid] >= target&&nums[left] <= target)
			{
				return searchNum(nums, target, left, mid);
			}
			else
			{
				return searchNum(nums, target, mid + 1, right);
			}
		}
		else
		{
			if (nums[mid+1]<=target&&nums[right]>=target)
			{
				return searchNum(nums, target, mid + 1, right);
			}
			return searchNum(nums, target, left, mid);

		}
	}
	return false;
}

bool search(vector<int>& nums, int target) {
	if (nums.size() == 0)return false;
	return searchNum(nums, target, 0, nums.size() - 1);
}

int main()
{
	vector<int> nums = { 0,1,1,2,0,0 };
	cout << search(nums, 2);
	return 0;
}

