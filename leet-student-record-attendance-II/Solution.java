import java.util.Scanner;

class Solution {

    public int dp[][][];
    public static int MOD = 1000000007;

    public int checkRecord(int n, int a, int l){

        if(dp[n][a][l] == -1){

            if(n == 0){
                dp[n][a][l] = 1;
            } else {

                dp[n][a][l] = 0;
                if(a < 1){
                    dp[n][a][l] += checkRecord(n-1, a+1, 0);
                    dp[n][a][l] %= MOD;
                }
                if(l < 2){
                    dp[n][a][l] += checkRecord(n-1, a, l+1);
                    dp[n][a][l] %= MOD;
                }
                dp[n][a][l] += checkRecord(n-1, a, 0);
                dp[n][a][l] %= MOD;
            }
        }
        return dp[n][a][l];
    }

    public int checkRecord(int n) {

        dp = new int[n+10][2][3];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return checkRecord(n, 0, 0);
    }

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        Solution sol = new Solution();
        System.out.println(sol.checkRecord(n));
    }
}