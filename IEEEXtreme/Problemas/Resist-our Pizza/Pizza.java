import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;

public class Pizza {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] parts = input.split(" ");
		int combinations;

		combinations = Integer.parseInt(parts[0]);
		int slices[] = new int[combinations];
		String[] ctoppings;
		@SuppressWarnings("unchecked")
		LinkedList<String>[] toppings = new LinkedList[combinations];
		int k = 0;
		for (int i = 1; i < parts.length; i++) {
			if ((i % 2) == 0) {
				ctoppings = parts[i].split(",");
				toppings[k] = new LinkedList<String>();
				for (int m = 0; m < ctoppings.length; m++) {
					toppings[k].add(ctoppings[m]);
				}
				k++;
			} else {
				slices[k] = Integer.parseInt(parts[i]);
			}
		}
		System.out.println("Combinations: " + combinations + "\nSlices: "
				+ Arrays.toString(slices));
		for (int j = 0; j < toppings.length; j++) {
			System.out.println("Toppings" + Arrays.toString(toppings[j].toArray()));
		}
	}
}