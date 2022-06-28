import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int result = 0; //수익
    static int day = 0; //퇴사까지 남은 시간
    static int[][] schedule;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int cols = Integer.parseInt(st.nextToken());
        int rows = Integer.parseInt(st.nextToken());
        char[][] floor = new char[cols][rows];

        //바닥장식 입력 세팅
        for (int i=0; i < cols; i++){
            String row = br.readLine();
            for (int j=0; j<rows; j++){
                floor[i][j] = row.charAt(j);
            }
        }

        int cnt = 0;
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows; j++){
                if(floor[i][j] == '-'){
                    cnt++;
                    while (j < rows && floor[i][j] == '-'){
                        j++;
                    }
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(floor[j][i] == '|'){
                    cnt++;
                    while(j < cols && floor[j][i] == '|'){
                        j++;
                    }
                }
            }
        }

        System.out.println(cnt);
    }
}