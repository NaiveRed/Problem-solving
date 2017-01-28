import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        BigInteger n;
        while (cin.hasNext()) {
            n = cin.nextBigInteger();
            switch (cin.next().charAt(0)) {
            case '+':
                n = n.add(cin.nextBigInteger());
                break;
            case '-':
                n = n.subtract(cin.nextBigInteger());
                break;
            case '*':
                n = n.multiply(cin.nextBigInteger());
                break;
            case '/':
                n = n.divide(cin.nextBigInteger());
            }
            System.out.println(n.toString());
        }
    }

}
