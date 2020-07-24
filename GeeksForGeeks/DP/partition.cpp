// CPP program to Partition an array of 
// non-negative integers into two subsets 
/* such that average of both the subsets are equal

https://www.interviewbit.com/problems/equal-average-partition/
*/


#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std; 

vector<vector<vector<bool> > > dp; 
vector<int> res; 
vector<int> original; 
int total_size; 

// Function that returns true if it is possible to 
// use elements with index = ind to construct a set of s 
// ize = curr_size whose sum is curr_sum. 
bool possible(int index, int curr_sum, int curr_size) 
{ 
	// base cases 
	if (curr_size == 0) 
		return (curr_sum == 0); 
	if (index >= total_size) 
		return false; 

	// Which means curr_sum cant be found for curr_size 
	if (dp[index][curr_sum][curr_size] == false) 
		return false; 

	if (curr_sum >= original[index]) { 
		res.push_back(original[index]); 
		// Checks if taking this element at 
		// index i leads to a solution 
		if (possible(index + 1, curr_sum - 
		original[index], 
					curr_size - 1)) 
			return true; 

		res.pop_back(); 
	} 
	// Checks if not taking this element at 
	// index i leads to a solution 
	if (possible(index + 1, curr_sum, curr_size)) 
		return true; 

	// If no solution has been found 
	return dp[index][curr_sum][curr_size] = false; 
} 

// Function to find two Partitions having equal average 
vector<vector<int> > partition(vector<int>& Vec) 
{ 
	// Sort the vector 
	sort(Vec.begin(), Vec.end()); 
	original.clear(); 
	original = Vec; 
	dp.clear(); 
	res.clear(); 

	int total_sum = 0; 
	total_size = Vec.size(); 

	for (int i = 0; i < total_size; ++i) 
		total_sum += Vec[i]; 
	// building the memoization table 
	dp.resize(original.size(), vector<vector<bool> > 
(total_sum + 1, vector<bool>(total_size, true))); 

	for (int i = 1; i < total_size; i++) { 
		// Sum_of_Set1 has to be an integer 
		if ((total_sum * i) % total_size != 0) 
			continue; 
		int Sum_of_Set1 = (total_sum * i) / total_size; 
                cout<<"finding sum: "<<Sum_of_Set1<<endl;
		// We build our solution vector if its possible 
		// to find subsets that match our criteria 
		// using a recursive function 
		if (possible(0, Sum_of_Set1, i)) { 

			// Find out the elements in Vec, not in 
			// res and return the result. 
			int ptr1 = 0, ptr2 = 0; 
			vector<int> res1 = res; 
			vector<int> res2; 
			while (ptr1 < Vec.size() || ptr2 < res.size()) 
			{ 
				if (ptr2 < res.size() && 
						res[ptr2] == Vec[ptr1]) 
				{ 
					ptr1++; 
					ptr2++; 
					continue; 
				} 
				res2.push_back(Vec[ptr1]); 
				ptr1++; 
			} 

			vector<vector<int> > ans; 
			ans.push_back(res1); 
			ans.push_back(res2); 
			return ans; 
		} 
	} 
	// If we havent found any such subset. 
	vector<vector<int> > ans; 
	return ans; 
} 

// Function to print partitions 
void Print_Partition(vector<vector<int> > sol) 
{ 
	// Print two partitions 
	for (int i = 0; i < sol.size(); i++) { 
		cout << "["; 
		for (int j = 0; j < sol[i].size(); j++) { 
			cout << sol[i][j]; 
			if (j != sol[i].size() - 1) 
				cout << " "; 
		} 
		cout << "] "; 
	} 
} 

// Driver code 
int main() 
{ 
	vector<int> Vec = { 47, 14, 30, 19, 30, 4, 32, 32, 15, 2, 6, 24}; 

	vector<vector<int> > sol = partition(Vec); 

	// If partition possible 
	if (sol.size()) 
		Print_Partition(sol); 
	else
		cout << -1; 

	return 0; 
} 

