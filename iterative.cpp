#include <iostream>
#include <vector>
#include <chrono>   
using namespace std;

int gap =2;

int misMatch(char a,char b){
    vector<int> vol(26,0);
    string vols = "aeiou";
    for(char ch: vols){
        vol[ch-'a'] = 1;
    }
    if(vol[a] == vol[b]){
        return 1;
    }else{
        return 3;
    }
}

int main()
{

    string word1;
    string word2;
    cout<<"enter the word 1 "<<endl;
    cin>>word1;
    cout<<"Enter the word 2 "<<endl;
    cin>>word2;
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = (i + j)*gap;
            }
            else if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] =  min(min(gap + dp[i][j - 1], gap + dp[i - 1][j]), misMatch(word1[i-1],word2[j-1]) + dp[i - 1][j - 1]);
            }
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "Execution time: " << duration.count() << " seconds\n";

    cout << dp[n][m] << " answer " << endl;
    
    return 0;
}
