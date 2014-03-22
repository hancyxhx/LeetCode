// Given an array of integers, every element appears three times except for one. Find that single one.

//     Note:
//     Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



class Solution {
public:
    int singleNumber(int A[], int n) {
	int r = 0;

	for(int j=0; j<sizeof(int)*8; j++){
	    int count = 0;
	    for(int i=0; i<n; i++)
		if((A[i] & (1<<j)) != 0)
		    count++;

	    if(count%3 != 0)
		r|=1<<j;
	}
	return r;
    }
};
