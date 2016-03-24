using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01
{
    class Program
    {
        static void Main(string[] args)
        {
            Kugel kugel1 = new Kugel(17);
            Kugel kugel2 = new Kugel(28);

            if (kugel1.istKleinerGleich(kugel2) == true)
                System.Console.WriteLine("kugel1 ist kleiner oder gleich kugel2");
            else
                System.Console.WriteLine("kugel2 ist kleiner oder gleich kugel1");


            System.Console.WriteLine(kugel1.KugelRadius);
            System.Console.WriteLine(kugel2.KugelRadius);

            System.Console.WriteLine(kugel1.BerechneVolumen());
            System.Console.WriteLine(kugel2.BerechneVolumen());

            System.Console.WriteLine(kugel1.BerechneOberflaeche());
            System.Console.WriteLine(kugel2.BerechneOberflaeche());

            kugel1.Aufblasen();
            kugel2.Aufblasen();

            System.Console.WriteLine(kugel1.BerechneVolumen());
            System.Console.WriteLine(kugel2.BerechneVolumen());

            System.Console.WriteLine(kugel1.BerechneOberflaeche());
            System.Console.WriteLine(kugel2.BerechneOberflaeche());

            System.Console.ReadLine();
        }
    }
}
