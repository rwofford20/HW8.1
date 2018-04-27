/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {
	//Implement recursive binary search
    //If first > last, there are no more items to search
    if(first > last){
        return -1;
    }
    else {
        //compute middle element in current vector
        int middle = (first+last)/2;
        //compare target to middle element of vector and return middle if it is the target
        if(target == items[middle]){
            return middle;
        }
        //if target is less than the middle element, use recursion to repeat the binary search
        //search again from the first term to one less than the middle term just searched
        if (target < items[middle]){
            return binary_search(items, first, (middle-1), target);
        }
        //if target is greater than the middle element, use recursion to repeat the binary search
        //search again from one more than the middle term just searched to the last term
        else {
            return binary_search(items, (middle+1), last, target);
        }
    }
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size()-1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);

	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
        //mod by 100 just for testing purposes (I couldn't find any numbers in haystack)
		haystack.push_back(rand()%100);

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		} else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}
