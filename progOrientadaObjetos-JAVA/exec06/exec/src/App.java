import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Questao q1 = new Questao();
        Scanner entrada = new Scanner(System.in);
        System.out.println(q1.consultarEnunciado());
        System.out.println(q1.gabarito(entrada.nextInt()));
        entrada.close();
    }
}
