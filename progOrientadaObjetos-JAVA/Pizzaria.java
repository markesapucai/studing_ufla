public class Pizzaria {
    //atributos
    String sapori[] = {"Margherita", "Marinara", "Quattro Formaggi", "Diavola"};
    char misurare[] = {'P', 'M', 'G'};
    float prezzo;
    int tempoMin;

    //construtores
    public Pizzaria(float prezzo, int tempoMin) {
        this.prezzo = prezzo;
        this.tempoMin = tempoMin;
    }

    //metodos
    void showOptions() {
        for(int i = 0; i < sapori.length; i++) {
            System.out.println((i+1) + ". " + sapori[i]);
        }
    }

    float flavorReference(int flavor) {
        float value = 0;

        if(flavor == 1) {
            value = 45.00f;
        } else if(flavor == 2) {
            value = 50.00f;
        } else if(flavor == 3) {
            value = 65.00f;
        } else if(flavor == 4) {
            value = 60.00f;
        } 
        return value;
    }

    float sizeReference(char size) {
        size = Character.toUpperCase(size); 
        float value = 0;
    
        if (size == 'P') {
            value = 0.85f;
        } else if (size == 'M') {
            value = 1f;
        } else if (size == 'G') {
            value = 1.15f;
        }
    
        return value;
    }
    

    float calculate(float flavor, float size) {
        prezzo = flavor * size;
        return prezzo;
    }
}

