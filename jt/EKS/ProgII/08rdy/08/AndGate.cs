
namespace GatesSwitchesDelegates
{
    public class AndGate : Gate
    {
        public override string Type {
            get 
            { 
                return "AND"; 
            }
        }

        public AndGate(params bool[] inports) : base(inports) { }

        public override bool OutPort
        {
            get
            {
                int cnt = 0;
                for (int i = 0; i < ports.Length; i++)
                {
                    if (ports[i].State)
                        cnt++;

                }
                if (cnt == ports.Length)
                    return true;
                else
                    return false;
            }
        }
    }
}
