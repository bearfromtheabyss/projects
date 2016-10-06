using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Threading;


namespace MultiKnapsack
{
    public partial class Form2 : Form
    {
        private List<Produkt> _produktList = new List<Produkt>();
        private List<Plecak> _plecakList = new List<Plecak>();
        private List<Double> listBool = new List<double>();
        private List<Double> listKtory = new List<double>();
        public Form2(List<Produkt> list, List<Plecak> pomListPlecak)
        {
            InitializeComponent();
            _produktList = list;
            _plecakList = pomListPlecak;
            sortedListBox.Items.Add("Nazwa" + "\t" + "Waga" + "\t" + "Cena" + "\t" + "Objetosc");
            foreach (Produkt element in _produktList)
            {
                sortedListBox.Items.Add(element.nazwa + "\t" + element.waga + "\t" + element.cena + "\t" + element.objetosc + "\t");
            }
            plecakListBox.Items.Add("Nazwa" + "\t" + "Max. waga" + "\t" + "Max.Objetosc");

            foreach (Plecak p in _plecakList)
            {
                plecakListBox.Items.Add(p.nazwa + "\t" + p.W.ToString() + "\t\t" + p.objetosc.ToString());
            }
            progressBar.Hide();
            this.Text = "Podsumowanie";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            backgroundWorker1.RunWorkerAsync();
            backgroundWorker1.ProgressChanged += new ProgressChangedEventHandler(backgroundWorker1_ProgressChanged);
            progressBar.Show();
            progressBar.ForeColor = Color.Blue;
        }
        private void Knapsack()
        {
            List<Plecak> descendingKanps = _plecakList.OrderByDescending(o => o.W).ToList();
            List<Produkt> descendingProducts = _produktList.OrderByDescending(o => o.cena).ToList();
            int N = descendingProducts.Count;
            double maxVal = 0;
            int percentage = 100 / descendingKanps.Count;
            int off = 1;
            int perc = 1;
            Produkt najlepszy = null;
            double calkowitaCena = 0;
            foreach (Plecak p in descendingKanps)
            {
                double maxWeight = p.W;
                double maxV = p.objetosc;
                List<Produkt> addedProducts = new List<Produkt>();
                double[,] V = new double[N + 1, (int)p.W + 1];
                for (int r = 0; r <= N; r++)
                {
                    for (int c = 0; c <= p.W; c++)
                    {
                        V[r, c] = 0;
                    }
                }
                for (int i = 0; i <= N; i++)
                {
                    if (descendingProducts.Any())
                    {
                        for (int wt = 0; wt <= p.W; wt++)
                        {
                            try
                            {
                                if (descendingProducts[i - off].waga < wt + 1)
                                {
                                    try
                                    {
                                        V[i, wt] = Math.Max(descendingProducts[i - off].cena + V[i - off, wt - descendingProducts[i - off].waga], V[i - off, wt]);
                                        najlepszy = descendingProducts.Find(o => (o.cena == V[i, wt]));
                                        listBool.Add(V[i, wt]);
                                        if (najlepszy != null && najlepszy.waga <= maxWeight && najlepszy.objetosc <= maxV)
                                        {
                                            addedProducts.Add(najlepszy);
                                            maxWeight -= najlepszy.waga;
                                            maxV -= najlepszy.objetosc;
                                            descendingProducts.Remove(najlepszy);
                                        }
                                    }
                                    catch (IndexOutOfRangeException)
                                    { }
                                }
                                else
                                {
                                    V[i, wt] = V[i - 1, wt];
                                    listBool.Add(V[i, wt]);
                                }
                            }
                            catch (ArgumentOutOfRangeException)
                            { }
                        }
                    }
                }
                maxVal = 0;

                for (int ps = 0; ps < addedProducts.Count; ps++)
                {
                    summary.Invoke(new Action(() => //dispatch to UI Thread
                    {

                        summary.Items.Add("Do plecaka: " + p.nazwa.ToString() + " włożono: " + addedProducts[ps].nazwa.ToString());
                    }));
                    maxVal += addedProducts[ps].cena;
                    calkowitaCena += addedProducts[ps].cena;
                    for (int dp = 0; dp < descendingProducts.Count; dp++)
                    {
                        if (descendingProducts[dp] == addedProducts[ps])
                        {
                            descendingProducts.RemoveAt(dp);
                            off++;
                        }
                    }
                }
                backgroundWorker1.ReportProgress(perc * percentage);
                perc++;
                summary.Invoke(new Action(() => //dispatch to UI Thread
                {
                    if (maxVal != 0)
                    {
                        summary.Items.Add("Maksymalna wartość dla plecaka: " + p.nazwa + " to: " + maxVal);
                    }
                    else
                        summary.Items.Add("Plecak " + p.nazwa + " jest pusty! Żaden produkt nie spełnił wymagań, lub nie ma już nic do dodania...");
                }));

            }
            //summary.Invoke(new Action(() =>
            //    summary.Items.Add("Całkowita wartość pobranych elementów we wszystkich plecakach: " + calkowitaCena)
            //));
        }
        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            Knapsack();
        }
        private void backgroundWorker1_ProgressChanged(object sender,
        ProgressChangedEventArgs e)
        {
            progressBar.Value = e.ProgressPercentage;
            this.Text = "Postęp: " + e.ProgressPercentage.ToString() + "%";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ListBox box = new ListBox();
            for (int i = 0; i < listBool.Count; i++)
            {
                box.Items.Add(i + "\t\t" + listBool[i]);
            }

            Form3 tabela = new Form3(box.Items);
            tabela.Show();
            //MessageBox.Show("Tabela wkrótce");
        }
    }
}

