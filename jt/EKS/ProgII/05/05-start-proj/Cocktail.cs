using System;

public class Cocktail
{   
    //Array um Zutaten zu speichern
    Zutat[] zutatenArray = new Zutat[15];

    //Jumbofizieren Methode ruft jumbofizieren fuer alle Zutaten einzeln auf
    public void Jumbofizieren()
    {
        foreach (Zutat i in zutatenArray)
        {
            if(i != null)
                i.Jumbofizieren();
        }
    }

    //overwritten toString Methode zur Ausgabe
    public override string ToString()
    {
        string str = "Cocktail: " + Name + " besteht aus : \n";
        for (int i = 0; i < zutatenArray.Length; i++ )
        {
            if (zutatenArray[i] == null) break;
            str = str + (i+1) + ". " + zutatenArray[i];
        }
        return str;
    }


    //Zutat zu einem Cocktail hinzufuegen
    public void PlusZutat(Zutat zutat)
    {
        for (int i = 0; i < zutatenArray.Length; i++)
        {
            if (zutatenArray[i] == null)
            {
                zutatenArray[i] = zutat;
                return;
            }

        } 
    }


    //Attribute und Properties
    private string name;

    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }

}