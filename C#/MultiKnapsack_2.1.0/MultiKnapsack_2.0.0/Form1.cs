using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
namespace MultiKnapsack
{

    public partial class Form1 : Form
    {
        List<Plecak> listPlecakow = new List<Plecak>();
        List<Produkt> listProdukt = new List<Produkt>();
        List<Produkt> pomoc = new List<Produkt>();
        int licznik = 0;
        int clear = 0;
        bool prawda = false;
        public Form1()
        {
            InitializeComponent();
            this.Text = "CMB Multiknapsack Solver";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if(String.IsNullOrWhiteSpace(produktWaga.Text) || String.IsNullOrWhiteSpace(produktCena.Text) || String.IsNullOrWhiteSpace(produktNazwa.Text))
                {
                    produktNazwa.Text = "a";
                    produktCena.Text = "10";
                    produktWaga.Text = "10";
                    produktobjetosc.Text = "10";
                    throw new FieldEmpty();
                }
                
            }
            catch(FieldEmpty)
            {
                MessageBox.Show("Wykryto puste pola. Ustalam wartości domyślne waga: 10, cena: 10, nazwa: a");
            }
                int pomWaga = Convert.ToInt32(produktWaga.Text);
                int pomCena = Convert.ToInt32(produktCena.Text);
                int pomObjetosc = Convert.ToInt32(produktobjetosc.Text);
                string pomNazwa = Convert.ToString(produktNazwa.Text);
                //if(pomWaga.Equals)
            
            
            Produkt nowy = new Produkt(pomCena, pomWaga, pomNazwa, pomObjetosc,0);

            listProdukt.Add(nowy);
            if (pomoc.Count == 0)
            {
                pomoc.Add(nowy);
            }
            this.produktListBox.Items.Clear();

            foreach (Produkt element in pomoc)
            {
                if (element.nazwa == nowy.nazwa && element.cena == nowy.cena && element.objetosc == nowy.objetosc && element.waga == nowy.waga)
                {
                    element.ile++;
                    prawda = true;
                    break;
                }
                else
                {
                    prawda = false;
                }
            }
                if (!prawda)
                {
                    nowy.ile++;
                    pomoc.Add(nowy);
                    prawda = true;
                }

            if (clear == 0)
                produktListBox.Items.Add("Nazwa" + "\t" + "Waga" + "\t" + "Cena" + "\t" + "Objetosc" + "\t" + "Ile");
            foreach (Produkt tmp in pomoc)
            {
                
                produktListBox.Items.Add(tmp.nazwa + "\t" + tmp.waga + "\t" + tmp.cena + "\t" + tmp.objetosc + "\t" + tmp.ile);
                clear++;
            }
            clear = 0;
           

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //List<Produkt> SortedList = listProdukt.OrderByDescending(o => o.stosunek).ToList();
            Form2 sortedList = new Form2(listProdukt, listPlecakow);
            sortedList.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.plecakListBox.Items.Clear();
            plecakListBox.Items.Add("Nazwa" + "\t\t" + "Waga"+"\t\t"+"Objetosc");
            try
            {
                if(String.IsNullOrWhiteSpace(plecakWaga.Text) || String.IsNullOrWhiteSpace(plecakNazwa.Text))
                {
                    plecakWaga.Text = "50";
                    plecakNazwa.Text = "P";
                    plecakObjetosc.Text = "20";
                    throw new FieldEmpty();
                }
            }
            catch (FieldEmpty)
            {
                MessageBox.Show("Wykryto puste pola. Ustalam wartości domyślne: Nazwa: P Waga: 50");
            }
            int maxWaga = Convert.ToInt32(plecakWaga.Text);
            int maxObjetosc = Convert.ToInt32(plecakObjetosc.Text);
            string nazwa = plecakNazwa.Text;
            try
            {
                if (licznik < 5)
                {
                    Plecak nowy = new Plecak(nazwa, maxWaga,maxObjetosc);
                    listPlecakow.Add(nowy);
                    licznik++;
                }
                else
                    throw new ZaDuzo();
            }
            catch (ZaDuzo)
            {
                MessageBox.Show("Próbujesz dodać zbyt dużo Plecaków. Max. 5");
            }
            foreach (Plecak p in listPlecakow)
            {
                plecakListBox.Items.Add(p.nazwa + "\t\t" + p.W.ToString()+"\t\t"+p.objetosc);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            listPlecakow.Clear();
            listProdukt.Clear();
            plecakListBox.Items.Clear();
            produktListBox.Items.Clear();
        }

    }
}

