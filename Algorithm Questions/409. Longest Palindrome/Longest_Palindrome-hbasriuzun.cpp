//Problem
//https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
    
    int i, longest=0 ,tek=0 ,temp=0;
    map<char,int> s_map;

    for ( i = 0; i < s.size(); i++){
        s_map[s[i]]++;
    }

    for (auto it = s_map.begin() ; it != s_map.end(); ++it){
        //if(it->second % 2==0){
            temp=it->second;
            while(temp/2 != 0){
                longest+=2;
                temp-=2;
            }

        
        if(it->second%2==1 && tek != 1)
            tek++;
    }
    longest+=tek;
    return longest;
        
    }
};