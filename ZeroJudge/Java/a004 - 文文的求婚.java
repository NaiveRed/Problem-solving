
import java.util.Scanner;

public class Java_Solve
{

    public static void main(String[] args)
    {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext())
        {
            int year = cin.nextInt();
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                System.out.println("閏年");
            else
                System.out.println("平年");
        }
    }
}
