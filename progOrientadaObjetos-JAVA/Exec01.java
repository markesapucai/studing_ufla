import java.util.Scanner;

public class Exec01 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int codigo;
        int quantidade;
        double valorBruto;
        double preco = 0;
        double desconto = 0;
        double precoDesconto = 0;

        System.out.print("Entre com o codigo: ");
        codigo = entrada.nextInt(); // 5
        System.out.print("Entre com a quantidade: ");
        quantidade = entrada.nextInt(); // 40
        System.out.println();

        if (codigo >= 1 && codigo <= 10) {
            preco = 10;
        } else if (codigo >= 11 && codigo <= 20) {
            preco = 15;
        } else if (codigo >= 21 && codigo <= 30) {
            preco = 20;
        } else if (codigo >= 31 && codigo <= 40) {
            preco = 30;
        }

        valorBruto = quantidade * preco;

        if (valorBruto < 250) {
            desconto = 0.05;
        } else if (valorBruto >= 250 && valorBruto <= 500) {
            desconto = 0.1;
        } else if (valorBruto > 500) {
            desconto = 0.15;
        }

        precoDesconto = desconto * valorBruto;

        System.out.println("Peco unitario: " + preco);
        System.out.println("Valor Bruto: " + valorBruto);
        System.out.println("Valor do desconto: " + precoDesconto);
        System.out.println("Preco final: " + (valorBruto - precoDesconto));
        entrada.close();
    }
}