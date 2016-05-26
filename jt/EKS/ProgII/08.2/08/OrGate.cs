

namespace GatesSwitchesDelegates
{
    public class OrGate : Gate
    {
        public override string Type
        {
            get
            {
                return "OR";
            }
        }

        public OrGate(params bool[] inports) : base(inports) { }

        //gibt true zurueck wenn nur ein port true ist
        public override bool OutPort
        {
            get
            {
                for (int i = 0; i < ports.Length; i++)
                {
                    if (ports[i].State)
                        return true;
                }
                return false;

            }
        }
    }
}
