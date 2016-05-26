//Jan-Tjorve Sobieski
//in Zusammenarbeit mit Dennis Ott und Arne Wagner

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    	/// <summary>
	/// Schiebespiel. Aus Wikipedia:
	/// Das 15-Puzzle, auch 14-15-Puzzle, Schiebepuzzle, Schiebefax oder Ohne-Fleiß-kein-Preis-Spiel genannt, 
	/// ist ein Geduldsspiel. Es wurde zwischen 1870 und 1880 in den Vereinigten Staaten vom Postangestellten 
	/// Noyes Palmer Chapman erfunden. Das Spiel besteht aus 15 Kacheln, von 1 bis 15 durchnummeriert, die 
	/// auf den 16 Feldern eines Vier-mal-vier-Quadrats angebracht sind. Ein Feld (das „Loch“) bleibt also frei. 
	/// Eine (vertikal oder horizontal) benachbarte Kachel kann jeweils in das freie Feld hineingeschoben werden. 
	/// Die Aufgabe besteht nun darin, durch Verschieben der Kacheln die Zahlen von 1 bis 15 aufsteigend anzuordnen.
	/// </summary>
	class Schiebespiel
	{
		private int[,] spielfeld = new int[4, 4];

		/// <summary>
		/// Initialisiert das Spielfeld
		///     1   2   3
		///  4  5   6   7
		///  8  9   10  11
		/// 12  13  14  15
		/// </summary>
		public Schiebespiel ()
		{
            int cnt = 0;
            for (int i = 0; i < spielfeld.GetLength(0); i++)
            {
                for (int j = 0; j < spielfeld.GetLength(1); j++)
                {
                    spielfeld[i, j] = cnt;
                    cnt++;
                }
            }
		}

		/// <summary>
		/// Gibt das aktuelle Spielfeld auf der Console aus
		/// </summary>
		public void Print ()
		{
            for (int i = 0; i < spielfeld.GetLength(0); i++)
            {
                for (int j = 0; j < spielfeld.GetLength(1); j++)
                {
                    if(spielfeld[i,j] <=9)
                        Console.Write("0{0} ", spielfeld[i, j]);
                    else
                        Console.Write("{0} ", spielfeld[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
		}

		/// <summary>
		/// Fuehrt einen Zug aus. Dazu wird die Kachel mit der übergebenen Position in 
		/// das freie Feld verschoben.
		/// </summary>
		/// <returns><c>true</c>, falls der Zug möglich war <c>false</c> sonst.</returns>
		/// <param name="x">Die x-Koodinate der zu verschiebenden Kachel.</param>
		/// <param name="y">Die x-Koodinate der zu verschiebenden Kachel.</param>
        /// Initialisiert das Spielfeld
        ///     1   2   3
        ///  4  5   6   7
        ///  8  9   10  11
        /// 12  13  14  15
		public bool MacheZug (int x, int y)
		{
            //Fall dass x /y ausserhalb des Spielfelds ist
            if (x > 3 || x < 0|| y > 3 || y < 0)
                return false;
            // Fall dass Kachel mit null auf x/y liegt
            if (spielfeld[x, y] == 0)
                return false;

            //Alle anderen Faelle / Also wenn Kachel einen oben/unten/rechts/links verschoben werden soll
            if (x-1 >= 0 && spielfeld[x - 1, y] == 0)
            {
                spielfeld[x - 1, y] = spielfeld[x, y];
                spielfeld[x, y] = 0;
                return true;
            }

            if (x+1 <= 0 && spielfeld[x+1 , y] == 0)
            {
                spielfeld[x+1, y] = spielfeld[x, y];
                spielfeld[x, y] = 0;
                return true;
            }

            if (y-1 >= 0 && spielfeld[x , y-1] == 0)
            {
                spielfeld[x, y-1] = spielfeld[x, y];
                spielfeld[x, y] = 0;
                return true;
            }

            if (y+1 <= 0 && spielfeld[x , y+1] == 0)
            {
                spielfeld[x, y+1] = spielfeld[x, y];
                spielfeld[x, y] = 0;
                return true;
            }
            else return false;
	    }
	}

	/// <summary>
	/// Das Springerproblem ist die Frage, ob es für ein Schachbrett der Groesse 8x8 
	/// eine Zugfolge (Weg) fuer einen Springer gibt, die alle Felder GENAU EINMAL zu besucht und ggf. 
	/// eine solche Zugfolge zu finden.
	/// Diese Klasse dient dazu eine solche Zugfolge zu finden.
	/// Achtung: Die Lösung des Springerproblems durch "brute force" ausprobieren
	/// kann lange dauern. Vermeiden Sie in Ihrer Implementierung von Loese
	/// Ausgaben auf der Konsole und testen Sie das Programm zuerst mit einem kleineren
	/// Schachbrett (6x6).
	/// </summary>
	class Springerproblem
	{
		/// <summary>
		/// Schachbrett speichert, ob der Springer das Feld schon besucht hat (Wert ungleich Null)
		/// und in welchem Zug seines Weges er das Feld besucht hat.  
		/// Beispiel: 
		/// 0 0 0 0 0 0 0 0 
		/// 0 0 0 0 0 0 0 0 
		/// 0 0 0 0 0 0 0 0 
		/// 0 0 0 0 0 0 0 0 
		/// 0 3 0 0 0 0 0 0 
		/// 0 0 0 0 0 0 0 0 
		/// 0 0 2 0 0 0 0 0 
		/// 1 0 0 0 0 0 0 0 
		/// stellt drei Springerzüge dar, beginnend unten links
		/// </summary>
		private int[,] schachbrett = new int[8, 8];

		/// <summary>
		/// Anzahl der bereits gemachten Zuege 
		/// </summary>
		private int zuege = 0;

		/// <summary>
		/// Loest das Springerproblem. Für eine gegebene Position prüft die Methode,
		/// ob es eine Zugfolge für Springer von der aktuellen Position aus gibt, die alle
		/// noch unbesuchten Felder des Schachbretts besucht. Bei dem ersten
		/// Aufruf aus der Main-Methode heraus sind noch alle Felder unbesucht.
		/// Die Methode arbeitet rekursiv und probiert alle Zugfolgen bis eine Folge gefunden
		/// wurde, die alle Felder besucht.
		/// </summary>
		/// <param name="x">x Koordinate der aktuellen Springerposition</param>
		/// <param name="y">y Koordinate der aktuellen Springerposition</param>
		public bool Loese (int x, int y)
		{
            zuege++;
            schachbrett[x, y] = zuege;

            if (notOutOfBound((x+2), (y-1)))
            {
                if (schachbrett[x + 2, y - 1] == 00)
                {
                    schachbrett[x + 2, y - 1] = zuege;
                    Loese(x + 2, y - 1);
                }
            }

            if(notOutOfBound( (x-2) ,(y-1))) {
                if (schachbrett[x - 2, y - 1] == 00)
                {
                    schachbrett[x - 2, y - 1] = zuege;
                    Loese(x - 2, y - 1);
                }
            }

            if(notOutOfBound( (x+2) ,(y+1))) {
                if (schachbrett[x + 2, y + 1] == 00)
                {
                    schachbrett[x + 2, y + 1] = zuege;
                    Loese(x + 2, y + 1);
                }
            }

            if(notOutOfBound( (x-2) ,(y+1))) {
                if (schachbrett[x - 2, y + 1] == 00)
                {
                    schachbrett[x - 2, y + 1] = zuege;
                    Loese(x - 2, y + 1);
                }
            }


            if(notOutOfBound( (x+1) ,(y+2))) {
                if (schachbrett[x + 1, y + 2] == 00)
                {
                    schachbrett[x + 1, y + 2] = zuege;
                    Loese(x + 1, y + 2);
                }
            }

            if(notOutOfBound( (x-1) ,(y+2))) {
                if (schachbrett[x - 1, y + 2] == 00)
                {
                    schachbrett[x - 1, y + 2] = zuege;
                    Loese(x - 1, y + 2);
                }
            }

            if(notOutOfBound( (x-1) ,(y-2))) {
                if (schachbrett[x - 1, y - 2] == 00)
                {
                    schachbrett[x - 1, y - 2] = zuege;
                    Loese(x - 1, y - 2);
                }
            }

            if(notOutOfBound( (x+1) ,(y-2))) {
                if (schachbrett[x + 1, y - 2] == 00)
                {
                    schachbrett[x + 1, y - 2] = zuege;
                    Loese(x + 1, y - 2);
                }
            }
            
            //return wenn Algorithmus erfolgreich -> wenn Springer auf allen Feldern war
            if (zuege == 36) return true;
            zuege--;
            schachbrett[x, y] = 0;
            return false;
		}

        //helper Funktion um zu Ueberpruefen ob x/y ausserhalb des Arrays sind
        public bool notOutOfBound(int x, int y)
        {
            if (x >= 0 && x < 6 && y >= 0 && y < 6)
                return true;
            else
                return false;
        }

		/// <summary>
		/// Gibt das aktuelle Schachbrett auf der Konsole aus
		/// </summary>
		public void Print ()
		{
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++)
					Console.Write (" {0:D2} ", schachbrett [i, j]);
				Console.WriteLine ();
			}
		}
	}

	/// <summary>
	/// Auswahldialog fuer Blatt 5
	/// </summary>
	class Program
	{
		public static void spieleSchiebeSpiel ()
		{
			int x, y;
			Schiebespiel spiel = new Schiebespiel ();
			Console.Clear ();
			Console.WriteLine ("Schiebespiel");
			do {
				spiel.Print ();
				Console.WriteLine ("Zu verschiebendes Teil eingeben");
				Console.WriteLine ("Zeile (0-3) (-1 fuer Ende)");
				x = Convert.ToInt32 (Console.ReadLine ());
				if (x == -1)
					break;
				Console.WriteLine ("Spalte (0-3) (-1 fuer Ende)");
				y = Convert.ToInt32 (Console.ReadLine ());
				Console.Clear ();
				if (!spiel.MacheZug (x, y))
					Console.WriteLine ("Ungueltiger Zug");
			} while (x >= 0 && y >= 0);
		}

		public static void Main (string[] args)
		{
			ConsoleKeyInfo input;
			do {
				Console.Clear ();
				Console.WriteLine ("Aufgabenblatt 5 (Prog II KIM/ESA)");
				Console.WriteLine ("1) Schiebespiel");
				Console.WriteLine ("2) Springerproblem");
				Console.WriteLine ("x) Ende");
				input = Console.ReadKey ();
				if (input.Key == ConsoleKey.D1) {
					spieleSchiebeSpiel ();
				}
				if (input.Key == ConsoleKey.D2) {
					Console.WriteLine ("Loese Springer-Problem... Bitte warten");
					Springerproblem springerProblem = new Springerproblem ();
					Console.WriteLine (springerProblem.Loese (4, 3));
					springerProblem.Print ();
					Console.ReadLine();
				}
			} while (input.Key != ConsoleKey.X);
		}
	}
}


