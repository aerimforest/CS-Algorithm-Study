import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static char[][] star;
    static void print_star(int x, int y, int len){
        // 종료조건
        if(len == 1){
            star[x][y] = '*';
            return;
        }
        //반으로 줄인 크기만큼 똑같이 만듬
        int new_len = len/2;
        print_star(x, y, new_len);
        print_star(x+new_len, y, new_len);
        print_star(x, y+new_len, new_len);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); //입력값
        int size = (int)Math.pow(2, n);

        //(1)빈 배열 만들기
        star = new char[size][size];
        for(int i=0; i<size; i++){
            Arrays.fill(star[i], ' '); //2차원 배열을 ' '으로 초기화
        }

        //(2)배열에 별 넣기
        print_star(0,0, size);

        //(3)배열 별 출력하기
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<size; i++){
            //size-i 로 안 하고 size로만 하면 뒤에 빈 값들이 나와서 출력 형태가 잘못된 것이라고 나옴
            for(int j=0; j<size-i; j++){
                sb.append(star[i][j]);
            }
            //마지막 \n은 제외
            if(i != size-1) sb.append("\n");
        }
        System.out.print(sb);
    }
}