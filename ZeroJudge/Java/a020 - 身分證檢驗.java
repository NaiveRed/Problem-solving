import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int[] arr ={ 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28,29, 32, 30, 31, 33 };
        while (cin.hasNext()) {
            String str = cin.next();

            int sum = str.charAt(9) - '0';
            for (int i = 8; i > 0; i--)
                sum += (9 - i) * (str.charAt(i) - '0');
            sum += arr[str.charAt(0) - 'A']/ 10 + arr[str.charAt(0) - 'A'] % 10 * 9;

            System.out.println(sum % 10 == 0 ? "real" : "fake");
        }

    }

}
