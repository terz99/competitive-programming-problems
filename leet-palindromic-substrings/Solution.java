import java.util.Scanner;

class Solution {
    public int countSubstrings(String s) {

        int n = s.length();
        int dp[][] = new int[n+5][n+5];
        boolean isPal[][] = new boolean[n+5][n+5];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
                isPal[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++){
            isPal[i][i] = true;
        }
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                isPal[i][i+1] = true;
                dp[i][i+1] = 1;
            }
        }

        for(int gap = 2; gap < n; gap++){
            for(int i = 0; i < n-gap; i++){

                int j = gap + i;
                
                if(s.charAt(i) == s.charAt(j) && isPal[i+1][j-1]){
                    isPal[i][j] = true;
                }

                if(isPal[i][j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1 - dp[i+1][j-1];
                } else {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
            }
        }

        return dp[0][n-1] + n;
    }
    
    public static void main(String[] args) {
        
        String s;
        Scanner in = new Scanner(System.in);
        s = in.next();
        in.close();
        Solution sol = new Solution();
        int res = sol.countSubstrings(s);
        System.out.println(res);
    }
}