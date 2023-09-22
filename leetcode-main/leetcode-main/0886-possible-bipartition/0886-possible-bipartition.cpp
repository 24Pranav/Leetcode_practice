class Solution {
public:
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<int> adj[n + 1];
		//graph adj generation using given vector<vector<int>>dislikes
		for (auto i : dislikes)
		{
			adj[i[0]].push_back(i[1]);
			adj[i[1]].push_back(i[0]);
		}
		//graph coloring using 2 color
		//color are 0 & 1
		vector<int>color(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == -1)
			{
				if (!possibleToColor(i, 1, adj, color))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool possibleToColor(int node, int newcolor, vector<int> adj[], vector<int>&color)
	{
		color[node] = newcolor;
		for (auto i : adj[node])
		{
			if (color[i] == -1)
			{
				possibleToColor(i, 1 - newcolor, adj, color);
			}
			else if (color[i] == color[node])
			{
				return false;
			}
		}
		return true;
    }
};