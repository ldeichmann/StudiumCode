﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gate
{
    class AndGatter:Gatter
    {
        public AndGatter (bool inPort1 = false, bool inPort2 = false) : 
            base (inPort1,inPort2)
        {

        }

        public override string Type
        {
            get
            {
                return "AND";
            }
        }

        public override bool OutPort
        {
            get
            {
                return InPort1 && InPort2;
            }
        }
        public AndGatter()
        {

        }
    }
}
