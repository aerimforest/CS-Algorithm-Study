import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static Integer[] arr ;
    static Integer[] dp;
    static int arr_size;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        //테스트 케이스의 수
        int test_num = Integer.parseInt(br.readLine());

        for(int i=0; i<test_num; i++){
            // 배열의 크기
            arr_size = Integer.parseInt(br.readLine());
            arr = new Integer[arr_size];
            dp = new Integer[arr_size];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j <arr_size; j++) {
                // 배열에다 토큰을 하나씩 불러서 입력해줌
                arr[j] = Integer.parseInt(st.nextToken());
            }
            sb.append(recur()+"\n");
        }
        System.out.println(sb);
    }

    static int recur() {
        int max = dp[0] = arr[0];

        for(int i=1; i<arr_size; i++){
            dp[i] = Math.max(dp[i-1] + arr[i], arr[i]) ;
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
