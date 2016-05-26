using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    class NonAlkoholZutat : Zutat
    {
        //abgeleiteter Konstruktor fuer NonAlkoholZutat
        public NonAlkoholZutat(int mengeInCL, string name) : base (mengeInCL, "CL", name)
        {
            
        }

        //overwritten jumbofizieren Methode fuer Alkoholzutat
        public override void Jumbofizieren()
        {
            Menge = Menge * 2;
        }
    }
}
