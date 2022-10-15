// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) 
// with 0 sum.
// Example 1:
// Input:
// 5
// 4 2 -3 1 6
// Output: 
// Yes
// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

// Example 2:
// Input:
// 5
// 4 2 0 1 6
// Output: 
// Yes
// Explanation: 
// 0 is one of the element 
// in the array so there exist a 
// subarray with sum 0.



#include<iostream>
#include<unordered_set>
using namespace std;


bool subArrayExists(int arr[], int n){

    unordered_set<int> s;             // it will contain sum of combinations of array elements(e.g 0+4,0+4+2,0+4+2+(-23))
    int sum = 0;                      // it will contain sum of all array elements

    for(int i=0; i<n; i++){
        sum = sum+arr[i];
        if(sum==0 || s.find(sum)!=s.end()){      // if 'sum' is present in set then return true
            return true;
        }
        s.insert(sum);
    }

    return false;
}

int main(){
    int n = 5;
    int arr[] = {4, 2, -3, 1, 6};

    bool res = subArrayExists(arr, n);
    cout<<res<<endl;

    return 0;
}

