// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

//     For example, given
//     s = "leetcode",
//     dict = ["leet", "code"].

//     Return true because "leetcode" can be segmented as "leet code".



class Solution {
public:

    bool wordBreak(string s, unordered_set<string> &dict) {
	//flag[i] means if the word s.substr(0,i+1) can be segmented
	bool *flag = new bool[s.length()];
	for(int i=0; i<s.length(); i++)
	    flag[i] = false;

	for(int i=0; i<s.length(); i++)
	    for(int j=i-1; j>=-1; j--)
		if ((flag[j]==true || j==-1) && dict.find(s.substr(j+1, i-j)) != dict.end())
		    flag[i] = true;

	return flag[s.length() - 1];

    }


};
