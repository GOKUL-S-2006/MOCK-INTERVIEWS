key idea:
    -> Find the zeros fron the last and store the indicies in array (arr)
    ->check if current s[i]=="1" and i<arr[j] then add the steps to swap with that zero(abs(i-arr[j])) make j<arr.size()


class Solution {
public:
    long long minimumSteps(string s) {
       
        long long moves=0;
        //To store zero indices location
        vector<int>arr;
      
        //Iterating from last and finding zeros and storing there indicies
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
