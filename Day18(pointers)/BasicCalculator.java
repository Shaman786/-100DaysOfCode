// Basic Calculator Using Swings

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class BasicCalculator extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    
    
    
    
    

    

        private JButton btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn0;
    private JButton btnPlus, btnMinus, btnMultiply, btnDivide, btnEquals, btnClear;
    private doubl

                add(btnDivide);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        add(btnEquals);
        add(btnClear);
        setSize(350, 450);
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == btn1) {
            tfDisplay.setText(tfDisplay.getText().concat("1"));
        }

        if (e.getSource() == btn2) {
            tfDisplay.setText(tfDisplay.getText().concat("2"));
        }

        if (e.getSource() == btn3) {
            tfDisplay.setText(tfDisplay.getText().concat("3"));
        }

        if (e.getSource() == btn4) {
            tfDisplay.setText(tfDisplay.getText().concat("4"));
        }

        if (e.getSource() == btn5) {
            tfDisplay.setText(tfDisplay.getText().concat("5"));
        }

        if (e.getSource() == btn6) {
            tfDisplay.setText(tfDisplay.getText().concat("6"));
        }

        if (e.getSource() == btn7) {
            tfDisplay.setText(tfDisplay.getText().concat("7"));
        }

        if (e.getSource() == btn8) {
            tfDisplay.setText(tfDisplay.getText().concat("8"));
        }

        if (e.getSource() == btn9) {
            tfDisplay.setText(tfDisplay.getText().concat("9"));
        }

        if (e.getSource() == btn0) {
            tfDisplay.setText(tfDisplay.getText().concat("0"));
        }

        if (e.getSource() == btnPlus) {
            num1 = Double.parseDouble(tfDisplay.getText());
            addc = 1;
            tfDisplay.setText("");
        }

        if (e.getSource() == btnMinus) {
            num1 = Double.parseDouble(tfDisplay.getText());
            subc = 1;
            tfDisplay.setText("");
        }

        if (e.getSource() == btnMultiply) {
            num1 = Double.parseDouble(tfDisplay.getText());
            mulc = 1;
            tfDisplay.setText("");
        }

        if (e.getSource() == btnDivide) {
            num1 = Double.parseDouble(tfDisplay.getText());
            divc = 1;
            tfDisplay.setText("");
        }

        if (e.getSource() == btnEquals) {
            num2 = Double.parseDouble(tfDisplay.getText());

            if (addc > 0) {
                result = num1 + num2;
                tfDisplay.setText(Double.toString(result));
                addc = 0;
            }

            if (subc > 0) {
                result = num1 - num2;
                tfDisplay.setText(Double.toString(result));
                subc = 0;
            }

            if (mulc > 0) {
                result = num1 * num2;
                tfDisplay.setText(Double.toString(result));
                mulc = 0;
            }

            if (divc > 0) {
                result = num1 / num2;
                tfDisplay.setText(Double.toString(result));
                divc = 0;
     

  
    
        }

        if (e.getSource() == btnClear) {
            tfDisplay.setText("");
        }
    }

    public static void main(String[] args) {
        new BasicCalculator();
    }
}