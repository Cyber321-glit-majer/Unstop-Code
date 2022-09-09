**problem statement
Print the number of AND triples, given an integer array arr.

An AND triplet is a set of three indices i, j, and k such that:

0 <= i<arr.length
0 <= j <arr.length
0 <= k <arr.length
arr[i] &arr[j] &arr[k] == 0, where & represents the bitwise-AND operator.
 

Input Format
The first line contains an integer n, the number of elements in the array.

The following line contains n numbers, arr[i], the elements of the array.

Output Format
Print the number of AND triplets in the array.

Constraints
1<=n<=1000

0 <= arr[i] < 216

Sample Testcase 0
Testcase Input
3
2 1 3 
Testcase Output
12
Explanation
We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2
Sample Testcase 1
Testcase Input
2
1 2 
Testcase Output
6
Explanation
We can select the following i, j ,k triples:
(i = 0, j = 0, k = 1) : 1&1&2 
(i = 0, j = 1, k = 1) : 1&2&2
(i = 1, j = 0, k = 1) : 2&1&2
(i = 1, j = 1, k = 0) : 2&2&1
(i = 0, j = 1, k = 0) : 1&2&1
(i = 1, j = 0, k = 0):  2&1&1



/// Brute force approach

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++)

    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                int temp=a[i]&a[j]&a[k];
                if(temp==0)
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}



<div>

**optimized code

#include<bits/stdc++.h>
using namespace std;

 int countTriplets(vector<int>& nums) 
 {
    unordered_map<int,int> mp; 
   
    
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums.size(); j++)
        {
            mp[(nums[i]&nums[j])]++;
        }
    }
    
    int ans = 0; 
    for(auto it : mp)
    {
        for(int i=0; i<nums.size(); i++)
        {
            if((nums[i]&it.first) == 0) 
                ans += it.second;
        }
    }
    return ans;
 }

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<countTriplets(arr); //printing the number of triplets in the array
    return 0;
}
