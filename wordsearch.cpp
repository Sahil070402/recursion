//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
bool search(int i, int j,int n,int m,vector<vector<char>>& board,string&word,int k ){
    if(k==word.size()){
        return true;
    }
    char ch= board[i][j];
    board[i][j] = '.';
    bool a,b,c,d;
   
    if(i-1>=0&&board[i-1][j]==word[k]){
        if(search(i-1,j,n,m,board,word,k+1))return true;
    }
     if(j-1>=0&&board[i][j-1]==word[k]){
        if(search(i,j-1,n,m,board,word,k+1))return true;
    }
     if(i+1<n&&board[i+1][j]==word[k]){
        if(search(i+1,j,n,m,board,word,k+1))return true;
    }
     if(j+1<m&&board[i][j+1]==word[k]){
        if(search(i,j+1,n,m,board,word,k+1))return true;
    }
    board[i][j] = ch;
    return false;

}
    bool wordSearch(vector<vector<char>>& board, string word) {
          int n = board.size();
        int m = board[0].size();
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,n,m,board,word,1)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends