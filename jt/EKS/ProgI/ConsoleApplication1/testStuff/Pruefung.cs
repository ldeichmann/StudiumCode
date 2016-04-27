using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testStuff
{
    class Pruefung
    {
        private int[] teilnehmer = new int[30];
        private int anzahlTeilnehmer = 0;

        public int[] Teilnehmer { get; private set; }

        public void Anmelden(int Mnr)
        {
            teilnehmer[anzahlTeilnehmer] = Mnr;
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
                if (teilnehmer[i] != 0)
                    Console.WriteLine("{0}", teilnehmer[i]);
                else
                    Console.WriteLine("{0}", teilnehmer[i]);
            }
        }

        public void ListeAusgeben2()
        {
            foreach (int MatrikelNr in teilnehmer)
            {
                if (MatrikelNr != 0)
                    Console.WriteLine("{0}", MatrikelNr);
                else
                    Console.WriteLine("{0}", MatrikelNr);
            }
        }
    }


}
