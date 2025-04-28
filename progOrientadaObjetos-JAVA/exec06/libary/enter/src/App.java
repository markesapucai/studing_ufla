public class App {
    public static void main(String[] args) throws Exception {
        //Criar biblioteca
        Biblioteca b1 = new Biblioteca();
        Livro l1 = new Livro("O mundo é uma casca de noz", "Stphen Hawking", 1996, true);
        Livro l2 = new Livro("A arte da guerra", "Spin zun", 1523, true);
        Livro l3 = new Livro("A sutil arte de ligar o foda-se", "Mark Kampson", 1972, true);
        
        // add alguns livros
        b1.adicionarLivro(l1);
        b1.adicionarLivro(l2);
        b1.adicionarLivro(l3);

        // criar um leitor
        Leitor p1 = new Leitor("Jenifer", "jenifer123@gmail.com");

        p1.emprestarLivro(l1);
        b1.listarLivrosDisponivel();


        // leitor pegar livros emprestad e devlver, mostrando estado da bblioteca antes e depois
    }
}
