

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

            //set
            //{
            //    if (GateToggled != null)
            //        GateToggled(this);
            //}
        }
    }
}
