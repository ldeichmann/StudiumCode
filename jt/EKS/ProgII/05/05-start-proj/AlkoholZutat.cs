using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    
    class AlkoholZutat : Zutat
    {
        //abgeleiteter Konstruktor fuer AlkoholZutat
        public AlkoholZutat(int mengeInCL, string name) : base (mengeInCL, "CL", name)
        {
            
        }

        //overwritten jumbofizieren Methode fuer Alkoholzutat
        public override void Jumbofizieren()
        {
            Menge = (int)((double)Menge * 3.0 / 2.0);
        }
    }
}
