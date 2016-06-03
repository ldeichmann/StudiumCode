using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _10
{

    //Ein grauer, gerade mal vierunddreissigstoeckiger Klotz. Ueber dem Hauptportal der Hinweis CITY-BRUETER UND KONDITIONIERUNGSCENTER LONDON und auf einem Wappen der Wahlspruch des Weltstaats: KOLLEKTIVITAET, IDENTITAET, STABILITAET.
    ///// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        int mostOccurrence = -1;
        char mostOccurringChar = ' ';

        public char MostOccurringCharInString(string charString)
        {

            foreach (char currentChar in charString)
            {
                int foundCharOccreence = 0;
                if (currentChar == ' ' || currentChar == ',' || currentChar == '.') continue;
                foreach (char charToBeMatch in charString)
                {
                    if (currentChar == charToBeMatch)
                        foundCharOccreence++;
                }
                if (mostOccurrence < foundCharOccreence)
                {
                    mostOccurrence = foundCharOccreence;
                    mostOccurringChar = currentChar;
                }
            }
            return mostOccurringChar;
        }

        public MainWindow()
        {
            InitializeComponent();


            // Set the Multiline property to true.
            //txtbox1.Multiline = true;
            //// Add vertical scroll bars to the TextBox control.
            //textBox1.ScrollBars = ScrollBars.Vertical;
            //// Allow the RETURN key in the TextBox control.
            //textBox1.AcceptsReturn = true;
            //// Allow the TAB key to be entered in the TextBox control.
            //textBox1.AcceptsTab = true;
            //// Set WordWrap to true to allow text to wrap to the next line.
            //textBox1.WordWrap = true;
            //// Set the default text of the control.

        }

        private void Button_Click_1(object sender, RoutedEventArgs e) // decrypt
        {
        }

        private void Button_Click(object sender, RoutedEventArgs e) //encrypt
        {
            List l = new List();
            string s = txtbox1.Text;
            int ecnt = 0;
            string newS = "";

            s = s.Replace("ä", "ae");
            s = s.Replace("ö", "oe");
            s = s.Replace("ü", "ue");
            s = s.Replace("Ä", "Ae");
            s = s.Replace("Ö", "Oe");
            s = s.Replace("Ü", "Ue");
            s = s.Replace("ß", "ss");

            char maxChar = MostOccurringCharInString(s);

            ecnt = (int)'e' - (int)maxChar;

            foreach (char c in s)
            {
                if ((int)c + ecnt > 122)
                    newS = newS + "" + (char)(c + (ecnt - 26));
                else if((int)c + ecnt > 90 && (int)c < 97)
                    newS = newS + "" + (char)(c + (ecnt - 26));

                else if((int)c >= 65 && (int)c <= 90 || (int)c >=97 && (int)c <= 122)
                    newS = newS + "" + (char)(c + ecnt);
                else 
                    newS = newS + "" + (char)c;
            }
            txtbox1.Text = newS;

            //MessageBox.Show("Aldous Huxley\nSchöne Neue Welt");
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
