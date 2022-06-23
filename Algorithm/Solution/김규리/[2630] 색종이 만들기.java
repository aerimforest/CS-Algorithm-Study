import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    // white, blue = 색종이 색
    static int white = 0;
    static int blue = 0;
    static int[][] paper;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        //입력값으로 색종이 세팅하기
        paper = new int[n][n];
        for(int row=0; row<n; row++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int col=0; col<n; col++){
                paper[row][col] = Integer.parseInt(st.nextToken());
            }
        }
        partition(0,0, n);
        System.out.println(white);
        System.out.println(blue);
    }

    public static void partition(int row, int col, int size){
        // 색을 체크했는데 true가 나오면 -> 0이면 white, 1이면 blue +1
        if (colorCheck(row, col, size)){
            if (paper[row][col] == 0) {
                white++;
            } else {
                blue++;
            } return;
        }
        // 재귀함수 호출
        int downSize = size/2;
        partition(row, col, downSize); //2사분면
        partition(row+downSize, col, downSize); //1사분면
        partition(row, col+downSize, downSize); //3사분면
        partition(row+downSize, col+downSize, downSize); //4사문변
    }

    public static boolean colorCheck(int row, int col, int size){
        int color = paper[row][col];

        for (int i = row; i < row+size; i++){
            for (int j = col; j < col+size; j++){
                if (paper[i][j] != color){
                    return false;
                }
            }
        }
        return true;
    }
}