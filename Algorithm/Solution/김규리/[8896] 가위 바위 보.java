import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] win;
    static boolean[] alive = new boolean[10]; //살아있는 로봇 저장 배열
    static int[] rsp = new int[3]; // 0:주먹, 1:가위, 2:보

    static void game(int n) throws IOException {
        char str[][] = new char[n][]; //로봇 문자열 저장 배열

        //로봇 문자열 저장
        for(int i=0; i<n; i++){
            str[i] = br.readLine().toCharArray();
        }

        int row = str.length;
        int col = str[0].length;

        for(int i=0; i<row; i++){
            for(int j=0; j< col; j++) {
                rsp[j] = 0; //0으로 초기화
            }
            for(int j=0; j< col; j++){
                if(!alive[j])
                // 각 테스트 케이스마다 무엇을 냈는지 확인인
                if(str[j][i] == 'R') rsp[0] += 1;
                else if(str[j][i] == 'S') rsp[1] += 1;
                else if(str[j][i] == 'P') rsp[2] += 1;
                System.out.print(str[i][j] + " ");
            } System.out.println();
        }c
    }

    public static void main(String[] args) throws IOException {
        Arrays.fill(alive, true);
        int test = Integer.parseInt(br.readLine()); //테스트 케이스 입력값
        win = new int[test];

        for(int i=0; i<test; i++){
            int robot = Integer.parseInt(br.readLine()); //로봇 수 입력값



            game(robot);
        }

    }
}