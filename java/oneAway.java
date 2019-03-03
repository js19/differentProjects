import java.math.BigInteger;
import java.util.*;

public class oneAway {
    //One Away
    //check if two strings/words are 1 or 0 edits away from each other
    public static void main(String args[]){
        String s1 = "pale";
        String s2 = "ple";
        String s3 = "pales";
        String s4 = "bale";
        String s5 = "bake";

        System.out.println(oneAwayNaive(s1, s2));
        System.out.println(oneAwayNaive(s1, s3));
        System.out.println(oneAwayNaive(s1, s4));
        System.out.println(oneAwayNaive(s1, s5));
    }

    //runtime O(n)
    private static boolean oneAwayNaive(String s1, String s2) {

        int maxLength = s1.length() >= s2.length() ? s1.length() : s2.length();
        int minLength = s1.length() < s2.length() ? s1.length() : s2.length();
        int count = 0;

        String maxString = s1.length() > s2.length() ? s1 : s2;
        String minString = s1.length() <= s2.length() ? s1 : s2;

        HashMap<Character, Integer> characterPositionMap = new HashMap<>();

        if(maxLength - minLength > 1){ return false; }

        //O(n)
        for(int i = 0; i < maxLength; i++){
            characterPositionMap.put(maxString.charAt(i), i);
        }

        //O(n)
        for(int j = 0; j < minLength; j++) {
            if (characterPositionMap.containsKey(minString.charAt(j))) {
                if(characterPositionMap.get(minString.charAt(j)) != j && characterPositionMap.get(minString.charAt(j)) != j + 1){
                    count++;
                }
            }else{
                count++;
            }
        }

        if(count > 1) { return false; }

        return true;
    }
}
