import java.util.Scanner;

class Solution {
    public String removeDuplicateLetters(String s) {
        
        int[] freq = new int[26];
        for(int i = 0; i < 26; i++){
            freq[i] = 0;
        } 
        int pos = 0;
        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i)-'a']++;
        }
        for(int i = 0; i < s.length(); i++){

            if(s.charAt(i) < s.charAt(pos)){
                pos = i;
            }
            if(--freq[s.charAt(i)-'a'] == 0){
                break;
            }
        }

        return ((s.length() == 0) ? "" : s.charAt(pos) 
        + removeDuplicateLetters(s.substring(pos+1).replaceAll("" + s.charAt(pos), "")));
    }

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        String s = in.next();
        Solution sol = new Solution();
        System.out.println(sol.removeDuplicateLetters(s));
    }
}