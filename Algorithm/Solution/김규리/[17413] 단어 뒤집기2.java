import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static Stack<Character> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 공백을 기준으로 문자열을 만듬
        StringTokenizer st = new StringTokenizer(br.readLine(), "<>", true);

        while(st.hasMoreTokens()){
            String token = st.nextToken();

            if(Objects.equals(token, "<")){
                System.out.print("<" + st.nextToken());
            } else if(Objects.equals(token, ">")){
                System.out.print(">");
            } else {
                StringTokenizer st2 = new StringTokenizer(token);
                StringBuilder sb = new StringBuilder();

                while(st2.hasMoreTokens()){
                    char[] arr = st2.nextToken().toCharArray();
                    for(char c : arr){
                        stack.push(c);
                    }
                    while(!stack.empty()){
                        sb.append(stack.pop());
                    }
                    sb.append(" ");
                }
                //맨 마지막 빈칸은 없애줌
                sb.deleteCharAt(sb.length()-1);
                System.out.print(sb);
            }
        }
    }
}