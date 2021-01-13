#include <bits/stdc++.h>
using namespace std;
#define lli long long int


lli maxSumFlip(lli a[], lli n)
{

	// Find the total sum of array
	lli total_sum = 0;

	for (lli i = 0; i < n; i++)
		total_sum += a[i];

	// Using Kadane's Algorithm
	lli max_ending_here = -a[0] - a[0];
	lli curr_sum = -a[0] - a[0];

	for (lli i = 1; i < n; i++) 
	{
		// Either extend previous
		// sub_array or start
		// new subarray
		curr_sum = max(curr_sum + (-a[i] - a[i]),
					(-a[i] - a[i]));

		// Keep track of max_sum array
		max_ending_here = max(max_ending_here, curr_sum);
	}

	// Add the sum to the total_sum
	lli max_sum = total_sum + max_ending_here;

	// Check max_sum was maximum
	// with flip or without flip
	max_sum = max(max_sum, total_sum);

	// Return max_sum
	return max_sum;
}

// Driver code
int main()
{
	lli test;
	cin>>test;
	while(test--){
	    lli N;
	    cin>>N;
	    lli arr[N];
	    for(lli i=0; i<N; i++) cin>>arr[i];
	    
	    cout << maxSumFlip(arr, N) << endl;
	}
	return 0;
}


