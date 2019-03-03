public class main {

    public static void findDifferenceOfSums(String[] args){
        int sumOfSquares = 0;
        int squareOfSum = 0;
        sumOfSquares = getSumOfSquares();
        squareOfSum = getSquareOfSums();
        printDifference(sumOfSquares, squareOfSum);
    }

    private static int getSumOfSquares(){
        int sos = 0;
        int product;

        for(int i = 1; i <= 100; i++){
            product = i * i;
            sos += product;
        }
        return sos;
    }

    public static int getSquareOfSums(){
        int sos = 0;

        for(int i = 1; i <= 100; i++){
            sos += i;
        }
        sos = sos * sos;
        return sos;
    }

    public static void printDifference(int sumOfSquares, int squareOfSum){
        System.out.println(squareOfSum - sumOfSquares);
    }
}
