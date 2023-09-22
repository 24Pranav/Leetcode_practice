//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j, int oc, int nc)
    {
        if(i<0 || i==image.size() || j<0 || j==image[0].size())
        return;
        if(image[i][j]!=oc)
        return;
        image[i][j]=nc;
        dfs(image,i,j-1,oc,nc);
        dfs(image,i,j+1,oc,nc);
        dfs(image,i-1,j,oc,nc);
        dfs(image,i+1,j,oc,nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        // Code here
        int oc=image[sr][sc];
        if(oc==nc)
        return image;
        dfs(image,sr,sc,oc,nc);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends