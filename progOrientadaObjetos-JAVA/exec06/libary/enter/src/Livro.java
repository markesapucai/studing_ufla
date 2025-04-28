public class Livro {
    private String titulo;
    private String autor;
    private int anoPublicacao;
    private boolean disponivel;

    Livro(String titulo, String autor, int anoPublicacao, boolean disponivel) {
        this.titulo = titulo;
        this.autor = autor;
        this.anoPublicacao = anoPublicacao;
        this.disponivel = disponivel;
    }

    public boolean isDisponivel() {
        return disponivel;
    }

    public void emprestar() {
        if (disponivel) {
            disponivel = false;
            System.out.println(titulo + " foi emprestado.");
        } else {
            System.out.println(titulo + " não está disponível para empréstimo.");
        }
    }

    public void devolver() {
        disponivel = true;
        System.out.println(titulo + " foi devolvido.");
    }

    @Override
    public String toString() {
        return "Título: " + titulo + ", Autor: " + autor + ", Ano: " + anoPublicacao + ", Disponível: " + disponivel;
    }

}
