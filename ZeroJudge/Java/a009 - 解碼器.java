
import java.util.Scanner;

public class Java_Solve{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        String s;
        while (cin.hasNext())
        {
            s = cin.nextLine();
            int len = s.length();
            for (int i = 0; i < len; i++)
                s += (char) (s.charAt(i) - 7);
            s = s.substring(len, s.length());
            System.out.println(s);
        }

    }
}
