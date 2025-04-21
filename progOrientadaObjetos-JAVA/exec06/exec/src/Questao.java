import java.util.Random;

public class Questao {
    //atributos 
    private int num1, num2, resul;
    private Random numeroAleatorio = new Random( );
    

    //calcula
    public Questao() {
        num1 = numeroAleatorio.nextInt(10);
        num2 = numeroAleatorio.nextInt(10);
        resul = num1 * num2;
    }

    //coleta resposta
    public String consultarEnunciado() {
       return "Quanto é " + num1 + " * " + num2 + "?";
    }

    public boolean gabarito(int resposta) {
        return resul == resposta;
    }
}
