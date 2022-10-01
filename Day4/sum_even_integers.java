/*Write a Java program that calculates and shows the sum of all even integers from 0 to n,
where n is specified by the user via keyboard. Assume that n is an integer greater than 0.*/

import java.util.Scanner;
import java.lang.Math;

public class sum_even_integers {
    static int fun(int n) {
        int i, sum = 0;
        for (i = 2; i <= n; i += 2) {
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("Enter any number: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Sum of all even numbers from 1 to " + n + " is: " + fun(n));
    }
}