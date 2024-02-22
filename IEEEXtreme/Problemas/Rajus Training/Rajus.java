import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Rajus {

	public static int getIndex(int e, int[] v) {
		int index = 0;
		for (int i = 0; i < v.length; i++) {
			if (v[i] == e)
				index = i;
		}
		return index;
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] nmparts = br.readLine().split(" ");
		int n = Integer.parseInt(nmparts[0]);
		int m = Integer.parseInt(nmparts[1]);
		String[] suparts;
		int[][] psu = new int[m][2];
		for (int i = 0; i < m; i++) {
			suparts = br.readLine().split(" ");
			psu[i][0] = Integer.parseInt(suparts[0]);
			psu[i][1] = Integer.parseInt(suparts[1]);
		}

		String[] spParts = br.readLine().split(" ");
		int[] studyPlan = new int[spParts.length];
		for (int i = 0; i < spParts.length; i++) {
			studyPlan[i] = Integer.parseInt(spParts[i]);
		}

		String passed = "YES";
		for (int i = 0; i < m; i++) {
			if (getIndex(psu[i][0], studyPlan) > getIndex(psu[i][1], studyPlan)) {
				passed = "NO";
				break;
			}
		}
		System.out.println(passed);

	}
}