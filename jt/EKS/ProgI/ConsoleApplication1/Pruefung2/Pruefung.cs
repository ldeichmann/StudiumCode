using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pruefung2
{
    class Pruefung
    {
        private Teilnehmer[] teilnehmer = new Teilnehmer[30];
        private int anzahlTeilnehmer = 0;

        public int[] Teilnehmer { get; private set; }

        //public Pruefung2(){

        //}
        public void Anmelden(int Mnr, int versuch)
        {
            teilnehmer[anzahlTeilnehmer] = new Teilnehmer(Mnr, versuch);
            anzahlTeilnehmer++;
        }

        public override string ToString()
        {
            return base.ToString();
        }

        public void ListeAusgeben()
        {
            for (int i = 0; i < teilnehmer.Length; i++)
            {
                if (teilnehmer[i].Mnr != 0)
                    Console.WriteLine("{0}", teilnehmer[i].Mnr);
                else
                    Console.WriteLine("{0}", teilnehmer[i].Mnr);
            }
        }

        public void ListeAusgeben2()
        {
            foreach (int MatrikelNr in Teilnehmer)
            {
                if (MatrikelNr != 0)
                    Console.WriteLine("{0}", MatrikelNr);
                else
                    Console.WriteLine("{0}", MatrikelNr);
            }
        }
    }
}
