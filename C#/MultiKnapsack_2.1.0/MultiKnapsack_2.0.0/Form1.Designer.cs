namespace MultiKnapsack
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.produktWaga = new System.Windows.Forms.TextBox();
            this.produktCena = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.produktListBox = new System.Windows.Forms.ListBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.plecakWaga = new System.Windows.Forms.TextBox();
            this.plecakListBox = new System.Windows.Forms.ListBox();
            this.label9 = new System.Windows.Forms.Label();
            this.produktNazwa = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.plecakNazwa = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.label2 = new System.Windows.Forms.Label();
            this.produktobjetosc = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.plecakObjetosc = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // produktWaga
            // 
            this.produktWaga.Location = new System.Drawing.Point(93, 57);
            this.produktWaga.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.produktWaga.Name = "produktWaga";
            this.produktWaga.Size = new System.Drawing.Size(108, 22);
            this.produktWaga.TabIndex = 1;
            // 
            // produktCena
            // 
            this.produktCena.Location = new System.Drawing.Point(93, 112);
            this.produktCena.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.produktCena.Name = "produktCena";
            this.produktCena.Size = new System.Drawing.Size(108, 22);
            this.produktCena.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(43, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Waga";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(43, 112);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 17);
            this.label3.TabIndex = 5;
            this.label3.Text = "Cena";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.Location = new System.Drawing.Point(35, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(168, 17);
            this.label4.TabIndex = 6;
            this.label4.Text = "Konfiguracja produktu";
            // 
            // produktListBox
            // 
            this.produktListBox.FormattingEnabled = true;
            this.produktListBox.ItemHeight = 16;
            this.produktListBox.Location = new System.Drawing.Point(248, 14);
            this.produktListBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.produktListBox.Name = "produktListBox";
            this.produktListBox.Size = new System.Drawing.Size(495, 148);
            this.produktListBox.TabIndex = 7;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(32, 149);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(175, 46);
            this.button1.TabIndex = 8;
            this.button1.Text = "Dodaj produkt do koszyka";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(31, 334);
            this.button2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(177, 46);
            this.button2.TabIndex = 16;
            this.button2.Text = "Dodaj plecak do listy";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(29, 206);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(170, 17);
            this.label5.TabIndex = 15;
            this.label5.Text = "Konfiguracja plecaków";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(34, 269);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(45, 17);
            this.label8.TabIndex = 12;
            this.label8.Text = "Waga";
            // 
            // plecakWaga
            // 
            this.plecakWaga.Location = new System.Drawing.Point(93, 266);
            this.plecakWaga.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.plecakWaga.Name = "plecakWaga";
            this.plecakWaga.Size = new System.Drawing.Size(108, 22);
            this.plecakWaga.TabIndex = 5;
            // 
            // plecakListBox
            // 
            this.plecakListBox.FormattingEnabled = true;
            this.plecakListBox.ItemHeight = 16;
            this.plecakListBox.Location = new System.Drawing.Point(248, 182);
            this.plecakListBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.plecakListBox.Name = "plecakListBox";
            this.plecakListBox.Size = new System.Drawing.Size(495, 148);
            this.plecakListBox.TabIndex = 17;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(37, 34);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(50, 17);
            this.label9.TabIndex = 19;
            this.label9.Text = "Nazwa";
            // 
            // produktNazwa
            // 
            this.produktNazwa.Location = new System.Drawing.Point(93, 30);
            this.produktNazwa.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.produktNazwa.Name = "produktNazwa";
            this.produktNazwa.Size = new System.Drawing.Size(108, 22);
            this.produktNazwa.TabIndex = 0;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(29, 240);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(50, 17);
            this.label10.TabIndex = 21;
            this.label10.Text = "Nazwa";
            // 
            // plecakNazwa
            // 
            this.plecakNazwa.Location = new System.Drawing.Point(93, 240);
            this.plecakNazwa.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.plecakNazwa.Name = "plecakNazwa";
            this.plecakNazwa.Size = new System.Drawing.Size(108, 22);
            this.plecakNazwa.TabIndex = 4;
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12.8F, System.Drawing.FontStyle.Bold);
            this.button3.Location = new System.Drawing.Point(248, 334);
            this.button3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(229, 62);
            this.button3.TabIndex = 24;
            this.button3.Text = "Dalej";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12.8F, System.Drawing.FontStyle.Bold);
            this.button4.Location = new System.Drawing.Point(692, 342);
            this.button4.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(51, 46);
            this.button4.TabIndex = 25;
            this.button4.Text = "R";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 17);
            this.label2.TabIndex = 26;
            this.label2.Text = "Objetosc";
            // 
            // produktobjetosc
            // 
            this.produktobjetosc.Location = new System.Drawing.Point(93, 85);
            this.produktobjetosc.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.produktobjetosc.Name = "produktobjetosc";
            this.produktobjetosc.Size = new System.Drawing.Size(108, 22);
            this.produktobjetosc.TabIndex = 2;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(15, 297);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 17);
            this.label6.TabIndex = 28;
            this.label6.Text = "Objetosc";
            // 
            // plecakObjetosc
            // 
            this.plecakObjetosc.Location = new System.Drawing.Point(93, 292);
            this.plecakObjetosc.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.plecakObjetosc.Name = "plecakObjetosc";
            this.plecakObjetosc.Size = new System.Drawing.Size(108, 22);
            this.plecakObjetosc.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(779, 414);
            this.Controls.Add(this.plecakObjetosc);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.produktobjetosc);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.plecakNazwa);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.produktNazwa);
            this.Controls.Add(this.plecakListBox);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.plecakWaga);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.produktListBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.produktCena);
            this.Controls.Add(this.produktWaga);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox produktWaga;
        private System.Windows.Forms.TextBox produktCena;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox produktListBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox plecakWaga;
        private System.Windows.Forms.ListBox plecakListBox;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox produktNazwa;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox plecakNazwa;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox produktobjetosc;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox plecakObjetosc;
    }
}

