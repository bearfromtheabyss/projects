namespace MultiKnapsack
{
    partial class Form2
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            this.sortedListBox = new System.Windows.Forms.ListBox();
            this.button1 = new System.Windows.Forms.Button();
            this.plecakListBox = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.summary = new System.Windows.Forms.ListBox();
            this.button2 = new System.Windows.Forms.Button();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // sortedListBox
            // 
            this.sortedListBox.ColumnWidth = 100;
            this.sortedListBox.FormattingEnabled = true;
            this.sortedListBox.ItemHeight = 16;
            this.sortedListBox.Location = new System.Drawing.Point(13, 30);
            this.sortedListBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.sortedListBox.Name = "sortedListBox";
            this.sortedListBox.ScrollAlwaysVisible = true;
            this.sortedListBox.Size = new System.Drawing.Size(513, 196);
            this.sortedListBox.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(13, 484);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(196, 57);
            this.button1.TabIndex = 1;
            this.button1.Text = "Wykonaj algorytm wieloplecakowy";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // plecakListBox
            // 
            this.plecakListBox.FormattingEnabled = true;
            this.plecakListBox.ItemHeight = 16;
            this.plecakListBox.Location = new System.Drawing.Point(13, 254);
            this.plecakListBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.plecakListBox.Name = "plecakListBox";
            this.plecakListBox.Size = new System.Drawing.Size(513, 196);
            this.plecakListBox.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(117, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Dodane produkty";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 235);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(106, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Dodane plecaki";
            // 
            // summary
            // 
            this.summary.FormattingEnabled = true;
            this.summary.ItemHeight = 16;
            this.summary.Location = new System.Drawing.Point(532, 30);
            this.summary.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.summary.Name = "summary";
            this.summary.ScrollAlwaysVisible = true;
            this.summary.Size = new System.Drawing.Size(563, 420);
            this.summary.TabIndex = 5;
            // 
            // button2
            // 
            this.button2.AccessibleRole = System.Windows.Forms.AccessibleRole.None;
            this.button2.Location = new System.Drawing.Point(215, 484);
            this.button2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(196, 57);
            this.button2.TabIndex = 6;
            this.button2.Text = "Pokaż tabelę";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // progressBar
            // 
            this.progressBar.BackColor = System.Drawing.SystemColors.Control;
            this.progressBar.Location = new System.Drawing.Point(421, 484);
            this.progressBar.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(674, 57);
            this.progressBar.TabIndex = 7;
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.WorkerReportsProgress = true;
            this.backgroundWorker1.WorkerSupportsCancellation = true;
            this.backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(529, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(226, 17);
            this.label3.TabIndex = 8;
            this.label3.Text = "Wynik algorytmu kilkuplecakowego";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1112, 571);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.summary);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.plecakListBox);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.sortedListBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form2";
            this.Text = "Podsumowanie";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox sortedListBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ListBox plecakListBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox summary;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.ProgressBar progressBar;
        public System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Label label3;
    }
}