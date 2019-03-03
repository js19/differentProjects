import java.math.BigInteger;
import java.util.*;

public class stringPermutations {


    public static void main(String args[]){

        //Given 2 strings, write a method to decide if one
        //is a permutation of the other. (Not using any sorting algorithms)

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String string1 = sc.nextLine();
        System.out.print("Enter another string: ");
        String string2 = sc.nextLine();
        String output = "are not";

        if(checkPermutaion(string1, string2)){
            output = "are";
        }
        System.out.println("The strings " + output + " permutations");
        return;
    }

    //n^2 approch (worse case)
    public static boolean checkPermutaion(String string1, String string2) {

        int string1Length = string1.length();
        int string2Length = string2.length();
        boolean hasCharacter;

        //strings have to be the same length
        if(string1Length != string2Length){
            return false;
        }

        //loop through both strings, check if character is present in other string.
        //nested for-loops = n ^ # of times nested = n^2
        for(int i = 0; i < string1Length; i++){
            hasCharacter = false;
            for(int j = 0; j < string2Length; j++){
                if(string1.charAt(i) == string2.charAt(j)){
                    hasCharacter = true;
                    continue;
                }
            }
            if(!hasCharacter){
                return false;
            }
        }
        return true;
    }

    //We can achieve a run time of better runtime of n, but will accomplish that
    //at a later date.
}
