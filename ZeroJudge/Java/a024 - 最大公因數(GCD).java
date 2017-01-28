import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int a, b;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            a = cin.nextInt();
            b = cin.nextInt();

            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }

            System.out.println(a);
        }
    }

}
