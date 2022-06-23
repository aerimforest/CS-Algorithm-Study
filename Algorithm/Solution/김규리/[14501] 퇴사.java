import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int result = 0;
    static int max = 0;
    static int[][] schedule;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        //입력 값으로 이차원배열 세팅
        schedule = new int[n][2];
        for(int day=0; day<n; day++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int mon=0; mon<2; mon++){
                schedule[day][mon] = Integer.parseInt(st.nextToken());
            }
        }

        for(int index=0; index<n; index++){
            //재귀를 이용한 완전탐색
            System.out.println("~~~~~~~"+index+"~~~~~~");
            maxMoney(schedule[index][1], index, n);
            if(result > max){
                max = result;
            }
            result = 0; //초기화
        }
        System.out.println(max);
    }

    public static void maxMoney(int moeny, int start, int size){
        System.out.println("start : " + start + " result : " + moeny);
        start = start + schedule[start][0];
        if (start >= size) {
            return;
        } else if (start + schedule[start][0] >= size){
            return;
        }
        result = moeny + schedule[start][1];
        maxMoney(result, start, size);
    }
}