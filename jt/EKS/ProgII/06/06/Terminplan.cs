//Jan-Tjorve Sobieski
//in Zusammenarbeit mit Dennis Ott

using System;
using System.Collections;
using System.Collections.Generic;

namespace Blatt9
{
	/// <summary>
	/// Terminplan fuer einen Tag
	/// </summary>
	public class Terminplan:IEnumerable<Termin>
	{

		/// <summary>
		/// Erzeugt einen leeren Terminplan.
        /// 
        //private LinkedList<Termin> plan = null;
        List<Termin> plan = new List<Termin>();
	    // </summary>
		public Terminplan ()
		{
		}

        //Funktion findet groessten Timeslot in Terminplan
        public void PlaneProg2()
        {
            plan.Sort();

            //Temp variablen und tmp Array, welches einen Platz groesser ist um auch progII zu speichern
            int tmpcnt = 0;
            Termin[] tmpTermin = new Termin[plan.Count+1];
            int tmpSlot = 0;
            int biggestSlot = 0;
            int SlotStart = 0;
            int SlotStop = 0;

            //Liste in Array packen zur einfacheren suche des groessten freien Zeitslots
            foreach (Termin t in plan)
            {
               tmpTermin[tmpcnt] = t;
               tmpcnt++;
            }
            
            //Suchen des groessten Timeslots
            for (int i = 0; i < tmpTermin.Length ; i++)
            {
                //Abbruchbedingung wenn Liste leer ist
                if (tmpTermin[i] == null) return;
                //Abbruchbedingung wenn wir beim letzen Timeslot sind
                if ((i + 1 == tmpTermin.Length-1)) break;
                //Setzen von temporaeren slot
                tmpSlot = tmpTermin[i + 1].Start - tmpTermin[i].Stop;
                //Suche nach groessten Slots
                if (tmpSlot > biggestSlot)
                {
                    biggestSlot = tmpSlot;
                    SlotStart = tmpTermin[i].Stop;
                    SlotStop = tmpTermin[i+1].Start;
                }
            }
               
            //Neuen Termin hinzufuegen
            plan.Add(new Termin(SlotStart, SlotStop, "ProgII"));
            
            //Liste nochmal sortieren
            plan.Sort();

            
       }

        // Funtkion fuegt ein Termin in Terminplan
        internal void Add(Termin termin)
        {
            //Abfrage ob sich Termin ueberhaupt in defienerter Zeit befindet
            if (termin.Start < 480 || termin.Stop > 1080)
                throw new IndexOutOfRangeException("Termin nicht in Vorgegebener Zeit");
            //Termin in Liste hinzufuegen
            plan.Add(termin);
            //Liste sortieren
            //plan.Sort();
        }


        //Interfaces fuer foreach loops
        public IEnumerator<Termin> GetEnumerator()
        {
            return plan.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return plan.GetEnumerator();
        }
    }
}

