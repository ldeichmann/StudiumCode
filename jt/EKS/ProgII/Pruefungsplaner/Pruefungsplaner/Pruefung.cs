using System;

public class Pruefung
{
    private Teilnehmer[] teilnehmerListe = new Teilnehmer[30];
    private int anzahlTeilnehmer = 0;
    private string name;

    public Pruefung(string name)
    {
        this.name = name;
    }

    public string Name
    {
        get
        {
            return this.name;
        }
    }

    public void Anmelden(int matrikelnummer, int versuch)
    {
        teilnehmerListe[anzahlTeilnehmer] =
            new Teilnehmer(matrikelnummer, versuch);
        anzahlTeilnehmer++;
    }

    public void ListeAusgeben()
    {
        foreach (Teilnehmer teilnehmer in teilnehmerListe)
            if (teilnehmer != null)
                Console.WriteLine("{0}", teilnehmer.MatrikelNummer);
            else
                Console.WriteLine("{0}", "frei");
    }
}


