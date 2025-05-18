class Solution {
public:
    long long minimumSteps(string s) {
        long long moves=0;
        vector<int>arr;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
            arr.push_back(i);
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1' && !arr.empty() && j<arr.size())
            {
                if(i < arr[j])
                {
                moves+=abs(i-arr[j]);
                   j++;
                }
            }
        }
        return moves;
        
    }
};
