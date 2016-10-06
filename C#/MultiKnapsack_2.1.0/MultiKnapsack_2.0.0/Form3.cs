using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MultiKnapsack
{
    public partial class Form3 : Form
    {
        
        public Form3(ListBox.ObjectCollection items)
        {
            InitializeComponent();
            tabela.Items.AddRange(items);
            
            this.Text = "Tabela pobranych produktów";
        }
    }
}
