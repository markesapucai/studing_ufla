import java.util.ArrayList;

public class Leitor {
    private String nome;
    private String email;
    private ArrayList<Livro> livrosEmprestados = new ArrayList<>();

    public Leitor(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    public void emprestarLivro(Livro livro) {
        if (livro.isDisponivel()) {
            livro.emprestar();
            livrosEmprestados.add(livro);
        } else {
            System.out.println("Livro indisponível para empréstimo.");
        }
    }

    public void devolverLivro(Livro livro) {
        if (livrosEmprestados.contains(livro)) {
            livro.devolver();
            livrosEmprestados.remove(livro);
        } else {
            System.out.println("Este livro não está com o leitor.");
        }
    }

    public void listarLivrosEmprestados() {
        System.out.println(nome + " pegou emprestados:");
        for (Livro livro : livrosEmprestados) {
            System.out.println(livro);
        }
    }
}
