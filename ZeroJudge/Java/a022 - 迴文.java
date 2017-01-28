import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            char[] arr = cin.nextLine().toCharArray();
            int len = arr.length, i;

            for (i = 0; i < len / 2; i++)
                if (arr[i] != arr[len - i - 1])
                    break;
            System.out.println(i == len / 2 ? "yes" : "no");
        }

    }

}
