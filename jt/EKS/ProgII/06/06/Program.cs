using System;

namespace Blatt9
{
	/// <summary>
	/// Blatt 9 
	/// </summary>
	class Prog2Planer
	{
		public static void Main (string[] args)
		{
			Terminplan plan = new Terminplan ();
			string input;
			do {
				input = Console.ReadLine ();
				if (input != String.Empty)
					plan.Add (new Termin (input));
			} while (input != String.Empty);

			plan.PlaneProg2 ();

			foreach (Termin termin in plan) {
				Console.WriteLine (termin);
			}

            Console.ReadLine();
		}
	}
}
