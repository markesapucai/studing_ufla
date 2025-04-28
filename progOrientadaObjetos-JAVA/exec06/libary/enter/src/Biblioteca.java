import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Livro> livrosDisponiveis = new ArrayList<>();

    public void adicionarLivro(Livro livro) {
        livrosDisponiveis.add(livro);
    }

    public void listarLivrosDisponivel() {
        System.out.println("Livros disponíveis:");
        for (Livro livro : livrosDisponiveis) {
            if (livro.isDisponivel()) {
                System.out.println(livro);
            }
        }
    }

    public ArrayList<Livro> getLivrosDisponiveis() {
        return livrosDisponiveis;
    }
}
