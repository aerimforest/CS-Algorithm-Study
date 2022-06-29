import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int num = 1;
        int result = 0;
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<str.length(); i++){
            switch (str.charAt(i)){
                case '(':
                    stack.push('(');
                    num *= 2;
                    break;

                case '[':
                    stack.push('[');
                    num *=3;
                    break;

                case ')':
                    //괄호가 잘못되어 있는 경우 처리
                    if (stack.empty() || stack.peek() != '('){
                        result = 0;
                        break;
                    }
                    //괄호가 마무리 된 경우 결과에 반영
                    if (str.charAt(i-1) == '('){
                        result += num;
                    }
                    //사용한 괄호는 스택에서 비움
                    stack.pop();
                    num /= 2;
                    break;

                case ']':
                    //괄호가 잘못되어 있는 경우 처리
                    if (stack.empty() || stack.peek() != '['){
                        result = 0;
                        break;
                    }
                    //괄호가 마무리 된 경우 결과에 반영
                    if (str.charAt(i-1) == '['){
                        result += num;
                    }
                    //사용한 괄호는 스택에서 비움
                    stack.pop();
                    num /= 3; //다시 1로 초기화
                    break;
            }
        }
        if(!stack.empty()){
            System.out.println(0);
        } else {
            System.out.println(result);
        }
    }
}