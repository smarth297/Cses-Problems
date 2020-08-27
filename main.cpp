#include <bits/stdc++.h>

using namespace std;

// TOP DOWN APPROACH---- TO MATRIX CHAIN MULTIPLICATION
// WE CAN BREAK THE PROBLEM INTO SMALLER SUBPROBLEMS
// ONE TOWARDS LEFT AND OHER TOWARDS RIGHT

//int dp[100][100];
//int mcm(int *arr,int i,int j)
//{
//    if(i==j)
//        return 0;
//    if(dp[i][j]!=-1)
//        return dp[i][j];
//
//        int ans=INT_MAX;
//
//    for(int k=i;k<j;k++)
//        ans=min(ans,mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);// 1ST CALL GETS ANS FROM LEFT CALL 2ND CALL GETS ANS FROM RIGHT CALL
//                                                // ABOVE ONE TELLS THAT FINAL MATRIX WILL BE OF I X J
//
//        dp[i][j]=ans;
//        return ans;
//
//}

// BOTTOM UP APPROACH TO MATRIX CHAIN MULTIPLICATION

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        memset(dp,-1,sizeof(dp));
    cout<<mcm(arr,1,n-1);
}
