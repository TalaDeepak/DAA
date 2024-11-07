#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int gap =2;

int misMatch(char a,char b) {
	vector<int> vol(26,0);
	string vols = "aeiou";
	for(char ch: vols) {
		vol[ch-'a'] = 1;
	}
	if(vol[a-'a'] == vol[b-'a']) {
		return 1;
	} else {
		return 3;
	}
}

int main()
{

	string word1 = "name";
	string word2 = "naem";
// 	cout<<"enter the word 1 "<<endl;
// 	cin>>word1;
// 	cout<<"Enter the word 2 "<<endl;
// 	cin>>word2;
	int n = word1.size();
	int m = word2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1,0));

	for(int i = 0; i <= n; i++) {
		dp[i][0] = i * gap;
	}
	for(int j = 0; j <= m; j++) {
		dp[0][j] = j * gap;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
		    int z = word1[i-1] == word2[j-1]  ? 0 : misMatch(word1[i-1],word2[j-1]);
			int cost1 = dp[i-1][j-1] + z;
			int cost2 = dp[i-1][j] + gap;
			int cost3 = dp[i][j-1] + gap;

			dp[i][j] = min(cost1,min(cost2,cost3));

		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{

			cout << dp[i][j] << " " ;
		}
		cout<<endl;
	}


	return 0;
}
