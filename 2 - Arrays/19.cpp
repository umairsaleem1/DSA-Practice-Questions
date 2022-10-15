// Find the first non-repeating element in a given array arr of N integers.
// Note: Array consists of only positive and negative integers and not zero.
// Example 1:
// Input : arr[] = {-1, 2, -1, 3, 2}
// Output : 3
// Example 2:
// Input : arr[] = {1, 1, 1}
// Output : 0





#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;



int firstNonRepeatingNo(int arr[], int n){

    unordered_map<int , int> m;    // it will store the frequency(count) of each distinct element present in array arr
    vector<int> v;                 // it will store all elements that occurs once in the array arr


    // storing count in the form of element:count in map i.e {-1:2, 2:2, 3:1}
    for(int i=0; i<n; i++){      
        m[arr[i]]++;
    }

    for(auto it:m){
        // checking if the element has count '1'( means occurs in array only once ) then push it to vector v
        if(it.second==1){
            v.push_back(it.first);
        }
    }

    sort(v.begin(), v.end());

    for(int j=0; j<n; j++){
        int isPresent = binary_search(v.begin(), v.end(), arr[j]);   // when binary_search algo returns true, means it is the first not-repeating element
        if(isPresent){
            return arr[j];
        }
    }

    return 0;
}
int main(){
    int size = 5;
    int arr[] = {-1, 2, -1, 3, 2};

    int no = firstNonRepeatingNo(arr, size);
    cout<<no<<endl;

    return 0;
}