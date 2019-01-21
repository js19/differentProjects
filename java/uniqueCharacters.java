import java.math.BigInteger;
import java.util.*;

public class main {


    public static void main(String args[]){
        //Implement an algorithm to determine if a string has all unique characters.
        //What if you could only use an Array or Hash-table.

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String userInput = sc.nextLine();


        hasUniqueCharactersArray(userInput);
        hasUniqueCharactersHashTable(userInput);

        return;
    }

    //runs in n^2
    public static void hasUniqueCharactersArray(String input){
        int stringLength = input.length();
        ArrayList<Character> characters = new ArrayList<Character>();

        for(char c : input.toCharArray()){ 
            for (int i = 0; i < characters.size(); i++) {
                if (c == characters.get(i)) {
                    System.out.println("False");
                    return;
                }
            }
          	characters.add(c);
        }
        System.out.println("True");
        return;
    }

    //runs in nlogn containsKey = logn
    public static void hasUniqueCharactersHashTable(String input){
        Map<Character, Integer> characters = new Hashtable<Character, Integer>();
        for(char c : input.toCharArray()){
            if(characters.containsKey(c)){
                System.out.println("False");
                return;
            }
            characters.put(c, 1);
        }
        System.out.println("True");
        return;
    }
}
