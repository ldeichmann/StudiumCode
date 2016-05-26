using System;


namespace GatesSwitchesDelegates
{
    /// <summary>
    /// Gate represents a logic gate with two input ports and one output port
    /// </summary>
    public abstract class Gate
    {


        public Inport[] ports = null;
        private InputSwitch[] switches = null;

        /// <summary>
        /// Type of the gate
        /// </summary>
        public abstract string Type
        {
            get;
        }

        public Gate(params bool[] inports)
        {
            ports = new Inport[inports.Length];
            
            for (int i = 0; i < ports.Length; i++ )
            {
                ports[i] = new Inport(inports[i]);
            }
        }
       public abstract bool OutPort
        {
            get;
        }

        /// <summary>
        /// String representation consists of both input values and output value
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            String s = "";

            for (int i = 0; i < ports.Length; i++)
            {
                
                s += ports[i].State + " " + Type + " ";
            }

            s += OutPort + "\n";
            return s;
        }

        public class Inport {
            public Inport(bool state)
            {
                State = state;
            }

            private bool state;
            public bool State
            {
                get 
                {
                    return state;
                }
                set
                {
                    this.state = value;
                }
            }

            public void connectPort(TFlipFlop to)
            {
                to.FlipFlogToggled += PortChanged;
            }

            public void PortChanged(TFlipFlop to)
            {
                state = to.State;
            }
            public void PortChanged(Gate g)
            {
                state = g.OutPort; 
            }


        }

    }
}
