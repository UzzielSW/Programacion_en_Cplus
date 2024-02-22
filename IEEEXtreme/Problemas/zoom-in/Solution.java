import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());// largo string
        int m = Integer.parseInt(br.readLine());// numero de strings o filas
        int k = Integer.parseInt(br.readLine());// letras
        String descriptions[][] = new String[k][m];
        String letras[] = new String[k];
        for (int i = 0; i < k; i++) {
            letras[i] = br.readLine();
            for (int j = 0; j < m; j++) {
                descriptions[i][j] = br.readLine();
            }
        }
        int x = Integer.parseInt(br.readLine());
        String let;
        int index = 0;
        for (int i = 0; i < x; i++) {// palabras
            // let = br.readLine().split("(?!^)");
            let = br.readLine();
            int y = let.length();
            for (int j = 0; j < m; j++) {// filas hacia abajo
                for (int h = 0; h < y; h++) {// filas hacia la derecha
                    index = Arrays.asList(letras).indexOf(String.valueOf(let.charAt(h)));
                    System.out.print(descriptions[index][j]);
                }
                System.out.println();
            }
        }
    }
}