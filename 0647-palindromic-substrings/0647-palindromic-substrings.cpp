class Solution {
public:

    bool ispal(string &s)
    {
        int i=0;
        int j=(int)s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {

        int n=(int)s.size();
        int cnt=0;

        for(int i=0;i<n;i++)
        {for(int j=i;j<n;j++)
        {string substrs=s.substr(i,j-i+1);
        if(ispal(substrs))
        {
            cnt++;
        }
        
        
        }
        }
        return cnt;

        
    }
};