import java.util.Scanner;

public class Java_Solve {

	public static void main(String[] args) {
        
		Scanner cin = new Scanner(System.in);

		int[][] arr = new int[100][100];

		while (cin.hasNext()) {
			int n, m;
			n = cin.nextInt();
			m = cin.nextInt();

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					arr[i][j] = cin.nextInt();

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n - 1; j++)
					System.out.printf("%d ", arr[j][i]);
				System.out.printf("%d\n", arr[n - 1][i]);
			}
		}
	}
}