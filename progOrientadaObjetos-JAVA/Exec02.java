import java.util.Scanner;

public class Exec02 {

    public static double lerNumero(Scanner scanner, String mensagem){
        System.out.print(mensagem);
        return scanner.nextDouble();
    }

    public static int fazerConta(double joao, double pedro){
        int cont = 0;
        while(joao < pedro) {
            joao += (joao * 0.025);
            pedro += (pedro * 0.005);
            cont++;
        }

        return cont;
    }
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        double valorJoao = lerNumero(entrada, "Entre com o valor investido pelo Joao: "); // 1000 * 0,025
        double valorPedro = lerNumero(entrada, "Entre com o valor investido pelo Joao: "); // 3000 * 0,005
        System.err.println();
        int quantidade = fazerConta(valorJoao, valorPedro);
        System.out.println("Quantidade de meses necessarios: " + quantidade);
        entrada.close();
    }
}
