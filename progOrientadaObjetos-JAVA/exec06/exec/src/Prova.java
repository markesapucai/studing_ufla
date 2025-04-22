import java.util.Scanner;

public class Prova {
    private Questao q = new Questao();
    private Scanner entrada = new Scanner(System.in);
    private int cont = 0;
    
    private void coletarResp() {
        boolean resul = q.gabarito(entrada.nextInt());
        if (resul) {
            cont++;
            System.out.println("Você tentou " + cont + " vez(es) e acertou a questão");

        } else if(!resul) {
            cont++;
            System.out.println("Você ganhou mais uma chance! Digite outra resposta para a questão:");
            if (cont < 10) {
                coletarResp();
            } else {
                System.out.println("Você tentou " + cont + " vez(es) e errou a questão");
            }           
            
        }
        entrada.close();
    }
    
    public void aplicar() {
        System.out.println(q.consultarEnunciado());
        coletarResp();
    }
}
