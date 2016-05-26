using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05
{
    class NonAlkoholZutat : Zutat
    {
        public NonAlkoholZutat(int mengeInCL, string name) : base (mengeInCL, "CL", name)
        {
            
        }

        public override void Jumbofizieren()
        {
            throw new NotImplementedException();
        }
    }
}
