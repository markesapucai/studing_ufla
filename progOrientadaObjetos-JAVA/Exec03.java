import java.util.Scanner;

public class Exec03 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Entre com um valor positivo: ");
        double num = entrada.nextDouble();
        System.err.println();
        double tolerancia = 0.0001;
        double xInicial = num / 2;

        double x; 
        double diferenca;
        do {
            x = (xInicial + (num / xInicial)) / 2;
            diferenca = (xInicial - x);
            xInicial = x;
        } while(diferenca >= tolerancia); 
        
        System.err.println("A raiz quadrada de " + num + " eh igual a " + x);


        entrada.close();
    }
}
