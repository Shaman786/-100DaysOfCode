//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int NthTerm(int N){
		    int ans=INT_MAX;
		    int i=N;
		    while(i>0)
		    {
		        if(check_prime(i))
		        {
		            ans=min(ans,N-i);
		            break;
		        }i--;
		    }
		    
		    // Code here
		}
		int j=N;
		while(j<=100000)
		{
		    if(check_prime(j))
		    {
		        ans=min(ans,j-N);
		        break;
		}j++;}return ans;

};
// Nth > prime 

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends