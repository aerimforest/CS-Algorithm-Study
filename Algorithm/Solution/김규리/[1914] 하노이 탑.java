import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        BigInteger bi = new BigInteger("2"); //2의 n 제곱이 매우 커질 수도 있기 때문에
        BigInteger c = bi.pow(n).subtract(BigInteger.ONE); //이동횟수 계산
        System.out.println(c); //이동횟수 우선 출력

        // n 이 20 이하인 경우에만 재귀함수 호출
        if(n<=20){
            Hanoi(n,1,2,3);
            System.out.println(sb);
        }
    }

    // n = 원판의 개수, start = 출발지, mid = 경유지, to = 도착지
    public static void Hanoi(int n, int start, int mid, int to){
        //종료조건
        if (n==1) {
            sb.append(start + " " + to + "\n");
            return;
        }
        // 원반 n-1개를 start -> mid 이동
        Hanoi(n-1, start, to, mid);
        // n번째 원반을 start -> to 이동
        sb.append(start + " " + to + "\n");
        // 원반 n-2개를 mid -> to 이동
        Hanoi(n-1, mid, start, to);
    }
}