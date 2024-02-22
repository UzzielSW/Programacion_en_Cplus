import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.util.Arrays;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String base = br.readLine();

        String casos = br.readLine();

        int num = Integer.parseInt(casos);

        for (int i = 0; i < num; i++) {
            String pURL = br.readLine();
            byte[] bas = encodeUTF8(base);
            byte[] div = encodeUTF8(pURL);
            byte[] xor = xorWithKey(div, bas);
            byte[] xor8 = Arrays.copyOfRange(xor, xor.length - 8, xor.length);
            String res = bytesToHex(xor8);
            long temp1 = Long.parseLong(res, 16);
            String cosa = fromBase10(temp1);
            System.out.println(base + "/" + cosa);
        }
    }

    final protected static char[] hexArray = "0123456789ABCDEF".toCharArray();

    public static String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = hexArray[v >>> 4];
            hexChars[j * 2 + 1] = hexArray[v & 0x0F];
        }
        return new String(hexChars);
    }

    private static final Charset UTF8_CHARSET = Charset.forName("UTF-8");

    static byte[] encodeUTF8(String string) {
        return string.getBytes(UTF8_CHARSET);
    }

    private static byte[] xorWithKey(byte[] a, byte[] key) {
        byte[] out = new byte[a.length];
        for (int i = 0; i < a.length; i++) {
            out[i] = (byte) (a[i] ^ key[i % key.length]);
        }
        return out;
    }

    public static final String ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static final long BASE = ALPHABET.length();

    public static String fromBase10(long i) {
        StringBuilder sb = new StringBuilder("");
        while (i > 0) {
            i = fromBase10(i, sb);
        }
        return sb.reverse().toString();
    }

    private static long fromBase10(long i, final StringBuilder sb) {
        long rem = i % BASE;
        sb.append(ALPHABET.charAt((int) rem));
        return (i / BASE);
    }

}