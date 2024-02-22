import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ai, aim1, input;
		long nm;

		do {
			nm = 1;
			input = br.readLine();
			if (input.compareTo("END") == 0) {
				break;
			}
			ai = input;
			while (true) {
				aim1 = Integer.toString(ai.length());
				if (ai.compareTo(aim1)==0)
					break;
				else {
					nm++;
					ai = aim1;
				}
			}
			System.out.println(nm);
		} while (true);
	}
}