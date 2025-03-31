public class Pizzaria {
    String sabor;
    float valor;

    public Pizzaria(String nome, float preco) {
        sabor = nome;
        valor = preco;
    }

    public static void main(String[] args) {
        Pizzaria pizza1 = new Pizzaria("Calabresa", 30);

        System.out.println("Sabor 1 escolhido:");
        System.out.println("Sabor: " + pizza1.sabor);
        System.out.println("Preco :" + pizza1.valor);
    }
}
