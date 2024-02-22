import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int N = 0;
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        String[] sl = new String[N];
        for (int i = 0; i < N; i++) {
            sl[i] = in.next();
        }
        int[] line = new int[N];
        for (int i = 0; i < N; i++) {
            try {
                line[i] = Integer.parseInt(sl[i]);
            } catch (NumberFormatException e) {
            }
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum = sum + line[i];
            if (sum < 0)
                sum = 0;
        }
        System.out.println(sum);
        in.close();
    }
}