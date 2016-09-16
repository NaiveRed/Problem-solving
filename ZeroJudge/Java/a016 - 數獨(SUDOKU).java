
import java.util.Scanner;

public class Java_Solve
{

    public static void main(String[] args)
    {

        int[][] arr = new int[9][9];
        Scanner cin = new Scanner(System.in);

        int i, j;
        boolean[] num = new boolean[10];

        while (cin.hasNext())
        {

            boolean ans = true;

            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    arr[i][j] = cin.nextInt();

            // row
            for (i = 0; i < 9 && ans; i++)
            {
                for (j = 0; j < 10; j++)
                    num[j] = false;
                for (j = 0; j < 9; j++)
                {
                    if (num[arr[i][j]])
                    {
                        ans = false;
                        break;
                    }

                    num[arr[i][j]] = true;
                }
            }

            // col
            for (i = 0; i < 9 && ans; i++)
            {
                for (j = 0; j < 10; j++)
                    num[j] = false;
                for (j = 0; j < 9; j++)
                {

                    if (num[arr[j][i]])
                    {
                        ans = false;
                        break;
                    }

                    num[arr[j][i]] = true;
                }
            }

            // grid
            for (i = 0; i < 9 && ans; i++)
            {

                for (j = 0; j < 10; j++)
                    num[j] = false;

                int r = (i / 3) * 3, c = (i % 3) * 3;
                for (int k = r; k < r + 3; k++)
                    for (j = c; j < c + 3; j++)
                    {

                        if (num[arr[k][j]])
                        {
                            ans = false;
                            break;
                        }

                        num[arr[k][j]] = true;
                    }
            }

            System.out.println(ans ? "yes" : "no");
        }
    }
}
