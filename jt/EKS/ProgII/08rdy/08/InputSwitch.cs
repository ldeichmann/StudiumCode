namespace GatesSwitchesDelegates
{
    public class InputSwitch
    {
        public delegate void SwitchToggleHandler(InputSwitch sender);

        public SwitchToggleHandler SwitchToggled;

        private bool state = false;

        public bool State {
            get
            {
                return state;
            }
            set
            {
                state = value;
                if (SwitchToggled != null)
                    SwitchToggled(this);
            }
        }


        public void toggle()
        {
            State = !State;
        }

    }
}
