//Jan-Tjorve Sobieski
// Praktikum 02

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02
{
    class Program
    {
 

        static void Main(string[] args)
        {

            DateTime dt = new DateTime();
            Messung patient0 = new Messung(34, "Herr Test");
            Messung patient1 = new Messung(39, "Herr Muster", DateTime.Now);


            Console.WriteLine("Name: {0}; Temperatur: {1}°C; Zeit: {2}", patient0.Name, patient0.Temperature, patient0.Time);
            Console.WriteLine("Name: {0}; Temperatur: {1}°C; Zeit: {2}", patient1.Name, patient1.Temperature, patient1.Time);

            if (patient0.Fieber)
                Console.WriteLine("{0} hat Fieber mit {1}", patient0.Name, patient0.Temperature);
            else
                Console.WriteLine("{0} hat kein Fieber", patient0.Name, patient1.Temperature);

            if (patient1.Fieber)
                Console.WriteLine("{0} hat Fieber", patient1.Name);
            else
                Console.WriteLine("{0} hat kein Fieber", patient1.Name);

            if (Messung.Steigend(patient0, patient1))
                Console.WriteLine("{1} hat hoehere Temperatur als {0}", patient0.Name, patient1.Name);
            else
                Console.WriteLine("{0} hat hoehere Temperatur als {1}", patient0.Name, patient1.Name);

            Console.WriteLine("{0}; falscher Zeitwert{1}", DateTime.Now, DateTime.UtcNow);

            Console.ReadLine();
        }
    }
}
