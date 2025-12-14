namespace kiosk
{
    partial class Form3
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
            components = new System.ComponentModel.Container();
            splitContainer1 = new SplitContainer();
            lblClock = new Label();
            label2 = new Label();
            label3 = new Label();
            btn_cancel = new Button();
            btn_reservation1 = new Button();
            panel1 = new Panel();
            label1 = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            SuspendLayout();
            // 
            // splitContainer1
            // 
            splitContainer1.Dock = DockStyle.Fill;
            splitContainer1.Location = new Point(0, 0);
            splitContainer1.Name = "splitContainer1";
            splitContainer1.Orientation = Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            splitContainer1.Panel1.BackColor = Color.FromArgb(64, 64, 64);
            splitContainer1.Panel1.Controls.Add(lblClock);
            splitContainer1.Panel1.Controls.Add(label2);
            splitContainer1.Panel1.Controls.Add(label3);
            // 
            // splitContainer1.Panel2
            // 
            splitContainer1.Panel2.AutoScroll = true;
            splitContainer1.Panel2.BackColor = Color.DimGray;
            splitContainer1.Panel2.Controls.Add(btn_cancel);
            splitContainer1.Panel2.Controls.Add(btn_reservation1);
            splitContainer1.Panel2.Controls.Add(panel1);
            splitContainer1.Size = new Size(915, 656);
            splitContainer1.SplitterDistance = 48;
            splitContainer1.SplitterWidth = 1;
            splitContainer1.TabIndex = 6;
            // 
            // lblClock
            // 
            lblClock.AutoSize = true;
            lblClock.ForeColor = Color.White;
            lblClock.Location = new Point(765, 19);
            lblClock.Name = "lblClock";
            lblClock.Size = new Size(0, 15);
            lblClock.TabIndex = 3;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.ForeColor = Color.White;
            label2.Location = new Point(765, 19);
            label2.Name = "label2";
            label2.Size = new Size(0, 15);
            label2.TabIndex = 1;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Red;
            label3.Location = new Point(12, 9);
            label3.Name = "label3";
            label3.Size = new Size(60, 25);
            label3.TabIndex = 0;
            label3.Text = "CGV";
            // 
            // btn_cancel
            // 
            btn_cancel.BackColor = Color.Blue;
            btn_cancel.ForeColor = Color.Lime;
            btn_cancel.Location = new Point(203, 504);
            btn_cancel.Name = "btn_cancel";
            btn_cancel.Size = new Size(194, 71);
            btn_cancel.TabIndex = 8;
            btn_cancel.Text = "취소하기";
            btn_cancel.UseVisualStyleBackColor = false;
            btn_cancel.Click += btn_cancel_Click;
            // 
            // btn_reservation1
            // 
            btn_reservation1.BackColor = Color.Blue;
            btn_reservation1.ForeColor = Color.Lime;
            btn_reservation1.Location = new Point(514, 504);
            btn_reservation1.Name = "btn_reservation1";
            btn_reservation1.Size = new Size(194, 71);
            btn_reservation1.TabIndex = 8;
            btn_reservation1.Text = "예매하기";
            btn_reservation1.UseVisualStyleBackColor = false;
            btn_reservation1.Click += btn_reservation1_Click;
            // 
            // panel1
            // 
            panel1.Location = new Point(70, 26);
            panel1.Name = "panel1";
            panel1.Size = new Size(729, 444);
            panel1.TabIndex = 0;
            panel1.Click += panel1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(81, 316);
            label1.Name = "label1";
            label1.Size = new Size(60, 25);
            label1.TabIndex = 5;
            label1.Text = "CGV";
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(915, 656);
            Controls.Add(splitContainer1);
            Controls.Add(label1);
            Name = "Form3";
            Text = "Form3";
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private SplitContainer splitContainer1;
        private Label lblClock;
        private Label label2;
        private Label label3;
        private Label label1;
        private System.Windows.Forms.Timer timer1;
        private Panel panel1;
        private Button btn_reservation1;
        private Button btn_cancel;
    }
}