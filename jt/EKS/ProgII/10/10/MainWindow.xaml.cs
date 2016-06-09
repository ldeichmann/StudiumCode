//Jan-Tjorve Sobieski
//Programmieren Praktikum 10
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
        public char MostOccurringCharInString(string inString)
        {
            int mostOccurrence = -1;
            char mostOccurringChar = ' ';
            foreach (char currentChar in inString)
            {
                int foundCharOccreence = 0;
                if (currentChar == ' ' || currentChar == ',' || currentChar == '.' || currentChar == '!' || currentChar == '?') continue; // ignore Special Characters
                foreach (char charToBeMatch in inString)  // cycle through all characters
                {
                    if (currentChar == charToBeMatch) // if character was found again occurence++
                        foundCharOccreence++;
                }
                if (mostOccurrence < foundCharOccreence) // if another charachter is found more often
                {
                    mostOccurrence = foundCharOccreence;
                    mostOccurringChar = currentChar;
                }
            }
            return mostOccurringChar;
        }

        private string rot(string s, int offset) // rotate all Characters to the right but no special characters
        {
            int ecnt = offset;
            string newS = "";
            foreach (char c in s)
            {
                if ((int)c + ecnt > 122)
                    newS = newS + "" + (char)(c + (ecnt - 26));
                else if ((int)c + ecnt > 90 && (int)c < 97)
                    newS = newS + "" + (char)(c + (ecnt - 26));

                else if ((int)c >= 65 && (int)c <= 90 || (int)c >= 97 && (int)c <= 122)
                    newS = newS + "" + (char)(c + ecnt);
                else
                    newS = newS + "" + (char)c;
            }

            return newS;
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

        private void Button_Click_1(object sender, RoutedEventArgs e) // decrypt with offset
        {
            string s = txtbox1.Text;
            string parser = txtbox2.Text;
            int offset = int.Parse(parser);
            txtbox1.Text = rot(s, offset);
        }

        private void Button_Click(object sender, RoutedEventArgs e) //encrypt first search for the mostOccuring Char in the Textbox
        {
            string s = txtbox1.Text;
            int ecnt = 0;

            s = s.Replace("ä", "ae");                               // Replace all german Chars
            s = s.Replace("ö", "oe");
            s = s.Replace("ü", "ue");
            s = s.Replace("Ä", "Ae");
            s = s.Replace("Ö", "Oe");
            s = s.Replace("Ü", "Ue");
            s = s.Replace("ß", "ss");

            char maxChar = MostOccurringCharInString(s);  // find most occuring char
            ecnt = (int)'e' - (int)maxChar;               // set offset E-Counter
            txtbox1.Text = rot(s, ecnt);                 // change txtbox

            //MessageBox.Show("Aldous Huxley\nSchöne Neue Welt");
        }

        private void button1_Click(object sender, RoutedEventArgs e) // - Button for Offset Counter
        {
            string parser = txtbox2.Text;
            int offset = int.Parse(parser);
            offset--;
            txtbox2.Text = Convert.ToString(offset);
        }

        private void button_Click_2(object sender, RoutedEventArgs e) // + Button for Offset Counter
        {
            string parser = txtbox2.Text;
            int offset = int.Parse(parser);
            offset++;
            txtbox2.Text = Convert.ToString(offset);
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void txtbox2_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
