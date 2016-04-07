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
            Messung patient0 = new Messung(35, "Herr Test");
            Messung patient1 = new Messung(38, "Herr Muster");

            Console.WriteLine("Name: {0}; Temperatur: {1}°C", patient0.Name, patient0.Temperature);
            Console.WriteLine("Name: {0}; Temperatur: {1}°C", patient1.Name, patient1.Temperature);

            if (patient0.Fieber)
                Console.WriteLine("{0} hat Fieber", patient0.Name);
            else
                Console.WriteLine("{0} hat kein Fieber", patient0.Name);

            if (patient1.Fieber)
                Console.WriteLine("{0} hat Fieber", patient1.Name);
            else
                Console.WriteLine("{0} hat kein Fieber", patient1.Name);

            if (patient0.Steigend(patient1))
                Console.WriteLine("{1} hat hoehere Temperatur als {0}", patient0.Name, patient1.Name);
            else
                Console.WriteLine("{0} hat hoehere Temperatur als {1}", patient0.Name, patient1.Name);

            Console.ReadLine();
        }
    }
}
