import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        System.out.println(recur(N, 0));
    }

    static int recur(int N, int count) {
        //종료조건
        if (N < 2) {
            return count;
        }
        //(0) 나누고 나머지만큼 (3) 연산을 진행됨 -> count 에 합함
        //(1) 3로 나누어 떨어지는 경우 -> recur(N / 3, count + 1 + (N % 3));
        //(2) 2로 나누어 떨어지는 경우 -> recur(N / 2, count + 1 + (N % 2));
        return Math.min(recur(N / 2, count + 1 + (N % 2)), recur(N / 3, count + 1 + (N % 3)));

    }
}