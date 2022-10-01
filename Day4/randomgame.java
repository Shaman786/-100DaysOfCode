import java.util.Random;
import java.util.Scanner;

public class randomgame {
    private static char randomChar() {
        Random r = new Random();
        return (char) (r.nextInt(26) + 'A');
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0;
        char ch = randomChar();
        System.out.println("Guess the letter");
        char guess = sc.next().charAt(0);

        while (guess != ch) {
            System.out.println("Guess the letter");
            guess = sc.next().charAt(0);
            count++;
        }
        System.out.println("You guessed it right in " + count + " tries" + " The letter was " + ch);
    }
}