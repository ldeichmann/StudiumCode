using System;
using System.Text.RegularExpressions;

namespace Blatt9
{
	/// <summary>
	/// Klasse repraesentiert einen Termin
	/// </summary>
	public class Termin : IComparable<Termin>
	{
		/// <summary>
		/// Startzeitpunkt des Termins in Minuten seit Mitternacht
		/// </summary>
		/// <value>Startzeit</value>
		public int Start { get; set; }

		/// <summary>
		/// Stoppzeitpunkt des Termins in Minuten seit Mitternacht
		/// </summary>
		/// <value>Stoppzeitpunkt</value>
		public int Stop { get; set; }

		/// <summary>
		/// Beschreibung des Termins
		/// </summary>
		/// <value>Beschreibung</value>
		public string Info { get; set; }

		public Termin ()
		{
		}

		/// <summary>
		/// Initialisiert eine neue Instanz eines Termins.
		/// </summary>
		/// <param name="start">Startzeitpunkt in Minuten seit Mitternacht.</param>
		/// <param name="stop">Stoppzeitpunkt in Minuten seit Mitternacht.</param>
		/// <param name="info">Beschreibung des Termins.</param>
		public Termin (int start, int stop, string info)
		{

			this.Start = start;
			this.Stop = stop;
			this.Info = info;
		}

		/// <summary>
		/// Initialisiert eine neue Instanz eines Termins aus einem String. 
		/// Das Format ist dabei hh:mm hh:mm Beschreibung.
		/// Beispiel: 10:00 11:30 Programmierung I
		/// Fuehrende Nullen bei Stundenangaben koennen weggelassen werden.
		/// Falls der uebergebene String nicht ausgewertet werden kann, wird ein 
		/// Termin von 0:00 bis 0:00 ohne Beschreibung erzeugt.
		/// </summary>
		/// <param name="terminString">Termin als String</param>
		public Termin (string terminString)
		{
			Match m = Regex.Match (terminString, @"(\d+)\:(\d+)\s(\d+)\:(\d+)\s(\w+)");
			if (!m.Success)
				return;
			Start = Convert.ToInt32 (m.Groups [1].Value) * 60 + Convert.ToInt32 (m.Groups [2].Value);
			Stop = Convert.ToInt32 (m.Groups [3].Value) * 60 + Convert.ToInt32 (m.Groups [4].Value);
			Info = m.Groups [5].Value;
		}

		/// <summary>
		/// Gibt einen <see cref="System.String"/> zurueck, der den aktuellen
		///  <see cref="Blatt9.Termin"/> repraesentiert.
		/// </summary>
		/// <returns>Ein <see cref="System.String"/>, der den aktuellen <see cref="Blatt9.Termin"/> darstellt.</returns>
		public override string ToString ()
		{
			return string.Format ("{0:D2}:{1:D2} {2:D2}:{3:D2} {4}", Start / 60, Start % 60, Stop / 60, Stop % 60, Info);
		}


        public int CompareTo(Termin t)
        {
            if(this.Start < t.Start && this.Stop <= this.Stop)
                return -1;

            if(this.Start == t.Start && this.Stop == t.Stop)
                return 0;
            else
                return 1;
        }


	}
}

