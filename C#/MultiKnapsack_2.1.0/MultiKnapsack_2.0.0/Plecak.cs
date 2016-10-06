using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiKnapsack
{
    public class Plecak
    {
       public double W;
       public int objetosc;
       public string nazwa;
        public Plecak(string nazwa, double W, int objetosc)
        {
            this.W = W;
            this.nazwa = nazwa;
            this.objetosc = objetosc;
        }
    }
}
