using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gate
{
    public abstract class Gatter
    {
        public bool InPort1{  get; set;}
        public bool InPort2 { get; set; }
        public abstract bool OutPort { get; set; } //= false; 

        public abstract string Type { get { return "Gatter"; } } 

        public Gatter(bool in1, bool in2) {
            InPort1 = in1;
            InPort2 = in2;
        }

        public Gatter()
        {

        }

        public override string ToString()
        {
            return Type + ":" + InPort1 + " " + InPort2 + " = " + OutPort;
        }

    }
}
