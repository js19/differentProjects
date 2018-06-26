public class calculation {

    private int num1;
    private int num2;


    calculation(int one, int two){
        this.num1 = one;
        this.num2 = two;
    }

    public int addNumbers(){
     int addedTogether;
     addedTogether = num1 + num2;
     return addedTogether;
    }
    public double divideNumber(){
        double divided;
        divided = (float)num1 / (float)num2;
        return divided;
    }
    public int multiplyNumbers(){
        int multiply;
        multiply = num1 * num2;
        return multiply;
    }
    public int subtractNumbers(){
        int subtract;
        subtract = num1 - num2;
        return subtract;
    }
}
