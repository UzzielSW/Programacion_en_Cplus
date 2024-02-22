import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {

	public static int[] makeBinaryArray(int size, int n) {
		int[] result = new int[size];
		String binaryString = Integer.toBinaryString(n);
		String[] stringParts = binaryString.split("");
		int z = size - 1;
		for (int i = (stringParts.length - 1); i >= 1; i--) {
			result[z] = Integer.parseInt(stringParts[i]);
			z--;
		}
		return result;
	}

	public static int[] makeBinaryArray(int size, long n) {
		int[] result = new int[size];
		String binaryString = Long.toBinaryString(n);
		String[] stringParts = binaryString.split("");
		int z = size - 1;
		for (int i = (stringParts.length - 1); i >= 1; i--) {
			result[z] = Integer.parseInt(stringParts[i]);
			z--;
		}
		return result;
	}

	public static void imprimir(int iterations, int[] nextCells) {
		int ndig = String.valueOf(iterations).length();
		int nspaces = 4 - ndig;
		System.out.print(iterations);
		for (int m = 0; m < nspaces; m++)
			System.out.print(" ");
		System.out.print("-");

		for (int k = 0; k < nextCells.length; k++) {
			if (nextCells[k] == 0)
				System.out.print(" ");
			else
				System.out.print("*");
		}
		System.out.print("-\n");
	}

	public static int nextCell(int[][] tt, int left, int middle, int right) {
		int result = 0;
		//System.out.println("l: " + left + " m: " + middle + " r: " + right);
		for (int k = 0; k < 8; k++) {
			if ((tt[k][0] == left) && (tt[k][1] == middle)&& (tt[k][2] == right))
				result = k;
		}
		// System.out.println(result);
		return result;
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] parts = input.split(" ");
		int[] rule = makeBinaryArray(8, Integer.parseInt(parts[0]));
		int max = Integer.parseInt(parts[1]);
		int[] cells = makeBinaryArray(Integer.parseInt(parts[2]),
				Long.parseLong(parts[3]));

		int[][] tt = new int[8][3];

		int step = 4;
		int count;
		for (int i = 0; i < 3; i++) {
			count = 2 * step;
			for (int k = 0; k < 8; k++) {
				if (count > step)
					tt[k][i] = 1;
				else
					tt[k][i] = 0;
				count--;
				if (count == 0)
					count = 2 * step;
			}
			step /= 2;
		}

		int[] nextCells = new int[cells.length];

		int iterations = 1;
		imprimir(iterations, cells);
		iterations++;
		do {
			nextCells=new int[cells.length];
			for (int i = 0; i < cells.length; i++) {
				if ((i - 1) < 0) {
					nextCells[i] = rule[nextCell(tt, 0, cells[i], cells[i + 1])];
				} else if ((i + 1) == (cells.length)) {
					nextCells[i] = rule[nextCell(tt, cells[i - 1], cells[i], 0)];
				} else {
					nextCells[i] = rule[nextCell(tt, cells[i - 1], cells[i], cells[i + 1])];
				}
			}
			//System.out.println("c: " + Arrays.toString(cells) + "nc: "+ Arrays.toString(nextCells));
			imprimir(iterations, nextCells);
			iterations++;
			if ((iterations > max) || (Arrays.equals(nextCells, cells)))
				break;
			else
				cells = nextCells;
		} while (true);

//		System.out.println(Arrays.deepToString(tt));
//		System.out.println(Arrays.toString(rule));
//		System.out.println(Arrays.toString(cells));

	}
}
