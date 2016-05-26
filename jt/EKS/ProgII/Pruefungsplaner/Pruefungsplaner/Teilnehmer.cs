public class Teilnehmer
{
    public int MatrikelNummer { get; set; }

    private int Versuch { get; set; }

    public Teilnehmer(int matrikelNummer, int versuch)
    {
        this.MatrikelNummer = matrikelNummer;
        this.Versuch = versuch;
    }
}

