import java.util.Scanner;

public class App {
    public static void main(String[] args) {
    Scanner dataEntry = new Scanner(System.in);
    Pizzaria pizza = new Pizzaria(0, 0);

    System.out.println("Welcome to our Pizzaria, Lets start by choosing the flavor");
    pizza.showOptions();

    System.out.println("Type the reference number for your chosen flavor");
    int flavorChoice = dataEntry.nextInt();

    System.out.println("Nice choice! Now tell us about the size! (just type: P, M, G)");
    char sizeChoice = dataEntry.next().charAt(0); 

    float flavorValue = pizza.flavorReference(flavorChoice);
    float sizeValue = pizza.sizeReference(sizeChoice);

    float calculate = pizza.calculate(flavorValue, sizeValue);

    System.out.println("Your Pizza cost: R$" + calculate + "and in 50min will be ready" );

    dataEntry.close();
    }
}
