using System;


namespace GatesSwitchesDelegates
{
    /// <summary>
    /// Gate represents a logic gate with two input ports and one output port
    /// </summary>
    public abstract class Gate
    {

        //variablen fuer Gate Delegates
        public delegate void delegateHandlerForGates(Gate g);

        public delegateHandlerForGates GateToggled;


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
                ports[i] = new Inport(inports[i], this);
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

            if (this is NotGate) s += Type + " ";
            s += ports[ports.Length-1].State + " = " + OutPort + "\n";
            return s;
        }

        // Helper Klasse Inport die einen ein InputSwitch darstellt
        public class Inport {

            //tmp Variable um den Zustand vom Gate mit zu uebergeben beim Instanzieren eines Gates mit Inports
            private Gate tmpGate;

            // Standard Konstruktor
            public Inport(bool state, Gate g)
            {
                State = state;
                tmpGate = g;
            }

            // Attribut state
            private bool state;
            public bool State
            {
                get 
                {
                    return state;
                }
                // Setter der bei aenderung des Temporaeren Gates den GateEventhandler toggled
                set
                {
                    this.state = value;
                    if (tmpGate != null && tmpGate.GateToggled != null)
                        tmpGate.GateToggled(tmpGate);
                }
            }

            //Methoden werden registriert wenn flipflops mit Gates bzw Gates mit Gates verbunden werden
            //1. ueberladung von connectport um 
            public void connectPort(TFlipFlop to)
            {
                to.FlipFlogToggled += PortChanged;
            }

            //2. ueberladung von connectport um switches mit Gates zu connecten
            public void connectPort(Gate g)
            {
                g.GateToggled += PortChanged;
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
