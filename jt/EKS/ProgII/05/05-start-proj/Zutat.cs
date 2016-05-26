using System;

public abstract class Zutat
{
    //Konstruktor
    public Zutat(int menge, string einheit, string name)
    {
        Menge = menge;
        Einheit = einheit;
        Name = name;
    }
    
    // abstrakte jumbofizieren fuer alle Zutaten
    public abstract void Jumbofizieren();

    //overwritten toString Methode zur Ausgabe
    public override string ToString()
    {
        return "Zutat: " + Name + "; Menge: " + Menge + "; in: " + Einheit + "\n";
    }


    //Attribute und Properties
    private int menge;

    public int Menge
    {
        get
        {
            return menge;
        }
        set
        {
            menge = value;
        }
    }

    private string einheit;

    public string Einheit
    {
        get
        {
            return einheit;
        }
        set
        {
            einheit = value;
        }
    }

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