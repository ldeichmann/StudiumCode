using System;


namespace GatesSwitchesDelegates
{
    /// <summary>
    /// Gate represents a logic gate with two input ports and one output port
    /// </summary>
    public abstract class Gate
    {
        //Array fuer Ports
        public Inport[] ports = null;

        /// <summary>
        /// Type of the gate
        /// </summary>
        public abstract string Type
        {
            get;
        }

        //Konstruktor der Alle eingegeben Ports ins Klassenarray 'ports' schiebt
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

            for (int i = 0; i < ports.Length-1; i++)
            {
                
                s += ports[i].State + " " + Type + " ";
            }

            s += ports[ports.Length-1].State + " = " + OutPort + "\n";
            return s;
        }

        // Helper Klasse Inport die einen ein Input Schalter  darstellt
        public class Inport {

            // Standard Konstruktor
            public Inport(bool state)
            {
                State = state;
            }

            // Attribut state
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

            //Methoden werden registriert wenn flipflops mit Gates bzw Gates mit Gates verbunden werden
            public void connectPort(TFlipFlop to)
            {
                to.FlipFlogToggled += PortChanged;
            }

            //Methoden werden aufgerufen wenn ein FlipFlop/Gate geaendert wird
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
