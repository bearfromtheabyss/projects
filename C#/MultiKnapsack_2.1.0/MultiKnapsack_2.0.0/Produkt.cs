using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiKnapsack
{
    public class Produkt
    {
        public int cena, waga, objetosc;
        public string nazwa;
        public int pos = 0;
        public int ile;
        public double stosunek;
        public int dodany;
        public static int overallProductsCount = 0;
        public Produkt(int cena, int waga, string nazwa, int objetosc,int ile)
        {
            this.cena = cena;
            this.waga = waga;
            this.nazwa = nazwa;
            this.objetosc = objetosc;
            this.ile = ile;
            overallProductsCount++;
        }
    }
}
