class Solution {
    public String longestPalindrome(String s) {
        
        int n = s.length();
        boolean isPal[][] = new boolean[n+5][n+5];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                isPal[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++){
            isPal[i][i] = true;
        }

        int maxx = 1;
        int maxI = 0;
        int maxJ = 0;
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                isPal[i][i+1] = true;
                maxx = 2;
                maxI = i;
                maxJ = i+1;
            }
        }

        for(int gap = 2; gap < n; gap++){
            for(int i = 0, j = i+gap; j < n; j++, i++){

                if(s.charAt(i) == s.charAt(j) && isPal[i+1][j-1]){
                    isPal[i][j] = true;
                }

                if(isPal[i][j]){
                    maxx = gap+1;
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        return s.substring(maxI, maxJ);
    }
}