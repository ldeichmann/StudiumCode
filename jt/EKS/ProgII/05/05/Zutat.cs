using System;

public abstract class Zutat
{
    public Zutat(int menge, string einheit, string name)
    {
        Menge = menge;
        Einheit = einheit;
        Name = name;
    }

    public abstract void Jumbofizieren();

    public string ToString()
    {
        throw new System.Exception("Not implemented");
    }

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