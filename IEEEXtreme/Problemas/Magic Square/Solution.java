import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {

	public static void main(String[] args) throws IOException {
		int sum = 0, antisum = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] matrix = new int[n][n];
		String[] sfila;
		int[] brows = new int[(2 * n) + 2];
		int cantnotsum = 0;
		for (int i = 0; i < n; i++) {
			sfila = br.readLine().split(" ");
			for (int k = 0; k < sfila.length; k++) {
				matrix[i][k] = Integer.parseInt(sfila[k]);
			}
		}

		// System.out.println(Arrays.deepToString(matrix));
		for (int i = 0; i < n; i++) {
			sum += matrix[i][i];
		}
		for (int i = (n - 1); i >= 0; i--) {
			antisum += matrix[n - 1 - i][i];
		}
		// System.out.println(sum);
		// System.out.println(antisum);
		if (sum != antisum) {
			brows[cantnotsum] = 0;
			cantnotsum++;
		}

		int sumafila;
		int sumacols;

		for (int i = 0; i < n; i++) {
			sumafila = 0;
			sumacols = 0;
			for (int k = 0; k < n; k++) {
				sumafila += matrix[i][k];
				sumacols += matrix[k][i];
			}
			if (sumafila != sum) {
				brows[cantnotsum] = (i + 1);
				cantnotsum++;
			}
			if (sumacols != sum) {
				brows[cantnotsum] = -(i + 1);
				cantnotsum++;
			}
			// System.out.println(sumafila);
			// System.out.println(sumacols);

		}
		int ans[] = new int[cantnotsum];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = brows[i];
		}
		if (cantnotsum > 0) {
			System.out.println(cantnotsum);
			Arrays.sort(ans);
			for (int i = 0; i < cantnotsum; i++) {
				System.out.println(ans[i]);
			}
		} else {
			System.out.println(0);
		}
	}
}