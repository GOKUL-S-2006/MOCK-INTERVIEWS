key idea:
    -> Find the zeros fron the last and store the indicies in array (arr)
    ->check if current s[i]=="1" and i<arr[j] then add the steps to swap with that zero(abs(i-arr[j])) make j<arr.size()


Better solution: TC->O(2N) and SC-> O(N)
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

Key idea:
      -> Find the last zero that before one indicies and move that indicies one place ahead because we are going to place that upcoming zero in that place or we can say that we need to stand the first one 
      ->Thats why we are starting from lastzerobeforeone=0
       -> after finding the last  indicies  of continuous zero start from there
       -> If you find any zero just add minmove+=abs(j-lastzerobeforeone); and move lastzerobeforeone++ because there only we are going to place the next zero 
       

optimal solution:TC-> O(N) and SC->O(1)

long long minimumSteps(string s) {
      
       int n=s.size();
      
       long long minmoves=0;
      
       int lastzerobeforeone=0;
       
       int i=0;
      
       for(i=0;i<n;i++){
          if(s[i]=='1')break;
          lastzerobeforeone++;
       }

       for(int j=i;j<n;j++){
              if(s[j]=='0'){
                   minmoves+=abs(j-lastzerobeforeone);
                   lastzerobeforeone++;
              }
       }

       return minmoves;
    }
