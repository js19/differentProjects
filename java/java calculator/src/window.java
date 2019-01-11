import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class window {

    private JFrame frame;
    private JTextField textArea;
    private char operandType;
    private int numOne;
    private int numTwo;

    public void createWindow(){
        frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize();
        setTitle();
        addButtons();
        showWindow();
    }

    private void addButtons(){
        JPanel panel = new JPanel(new GridLayout(4,4, 4, 5));
        panel.setMaximumSize(new Dimension(600,400));

        textArea = new JTextField();
        Font font = textArea.getFont().deriveFont(Font.PLAIN, 50f);
        textArea.setFont(font);
        textArea.setEditable(false);
        textArea.setHorizontalAlignment(JTextField.RIGHT);

        Button button;
        for(int i = 9; i >= 0; i--){
            button = new Button();
            button.setLabel(String.valueOf(i));
            button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    calculate(e);
                }
            });
            button.setPreferredSize(new Dimension(100, 100));
            panel.add(button);
        }

        Button plus;
        Button minus;
        Button multiply;
        Button divide;
        Button equal;
        Button clear;
        plus = operatorButtons("+");
        minus = operatorButtons("-");
        multiply = operatorButtons("*");
        divide = operatorButtons("/");
        equal = operatorButtons("=");
        clear = operatorButtons("c");

        Panel operators = new Panel(new GridLayout(4,2, 4, 5));
        operators.add(clear);
        operators.add(plus);
        operators.add(minus);
        operators.add(multiply);
        operators.add(divide);
        operators.add(equal);


        Panel container = new Panel();
        container.setLayout(new GridLayout(1, 2, 4, 5));
        container.add(panel);
        container.add(operators);

        frame.add(textArea, BorderLayout.NORTH);
        frame.add(container, BorderLayout.SOUTH);
        frame.pack();

    }

    private Button operatorButtons(String label){
        Button newButton = new Button();
        newButton.setLabel(label);
        newButton.setPreferredSize(new Dimension(100, 100));
        newButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                checkButton(e);
            }
        });
        return newButton;
    }

    public void calculate(ActionEvent e){
        Button sourceButton = (Button)e.getSource();
        textArea.replaceSelection(sourceButton.getActionCommand());
    }

    private void showWindow(){
        frame.setVisible(true);
    }

    private void checkButton(ActionEvent e){
        Button sourceButton = (Button)e.getSource();
        switch(sourceButton.getActionCommand()){
            case "+":
                storeNumOne();
                operandType = 'a';
                break;
            case "*":
                storeNumOne();
                operandType = 'm';
                break;
            case "-":
                storeNumOne();
                operandType = 's';
                break;
            case "/":
                storeNumOne();
                operandType = 'd';
                break;
            case "=":
                calculateNums(operandType);
                break;
            case "c":
                textArea.setText("");
        }
    }

    private void storeNumOne(){
        numOne = Integer.parseInt(textArea.getText());
        textArea.setText("");
    }

    private void setSize(){
        frame.setSize(600, 600);
    }

    private void setTitle() {
        frame.setTitle("Calculator");
    }

    private void calculateNums(char operandType){
        numTwo = Integer.parseInt(textArea.getText());
        calculation cal = new calculation(numOne, numTwo);
        boolean divide = false;
        int num = 0;
        double numD = 0;
        switch(operandType){
            case 'a':
                 num = cal.addNumbers();
                break;
            case 's':
                num = cal.subtractNumbers();
                break;
            case 'd':
                numD = cal.divideNumber();
                divide = true;
                break;
            case 'm':
                num = cal.multiplyNumbers();
                break;
        }

        if(!divide){
            textArea.setText(String.valueOf(num));
        }else{
            textArea.setText(String.valueOf(numD));
        }
    }

}
