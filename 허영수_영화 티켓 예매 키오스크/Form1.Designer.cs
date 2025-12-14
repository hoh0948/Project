namespace kiosk
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            splitContainer1 = new SplitContainer();
            lblClock = new Label();
            label1 = new Label();
            btn_cancel = new Button();
            btn_reservation = new Button();
            panel1 = new Panel();
            textBox1 = new RichTextBox();
            groupBox1 = new GroupBox();
            label6 = new Label();
            label5 = new Label();
            label4 = new Label();
            label3 = new Label();
            label2 = new Label();
            btn_noise = new Button();
            btn_fantastic = new Button();
            btn_f1 = new Button();
            btn_dokza = new Button();
            btn_zombie = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            panel1.SuspendLayout();
            groupBox1.SuspendLayout();
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
            splitContainer1.Panel1.Controls.Add(label1);
            // 
            // splitContainer1.Panel2
            // 
            splitContainer1.Panel2.AutoScroll = true;
            splitContainer1.Panel2.BackColor = Color.DimGray;
            splitContainer1.Panel2.Controls.Add(btn_cancel);
            splitContainer1.Panel2.Controls.Add(btn_reservation);
            splitContainer1.Panel2.Controls.Add(panel1);
            splitContainer1.Panel2.Controls.Add(groupBox1);
            splitContainer1.Size = new Size(915, 656);
            splitContainer1.SplitterDistance = 48;
            splitContainer1.SplitterWidth = 1;
            splitContainer1.TabIndex = 0;
            // 
            // lblClock
            // 
            lblClock.AutoSize = true;
            lblClock.ForeColor = Color.White;
            lblClock.Location = new Point(765, 19);
            lblClock.Name = "lblClock";
            lblClock.Size = new Size(0, 15);
            lblClock.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(60, 25);
            label1.TabIndex = 0;
            label1.Text = "CGV";
            // 
            // btn_cancel
            // 
            btn_cancel.BackColor = Color.Blue;
            btn_cancel.Font = new Font("맑은 고딕", 11.25F, FontStyle.Bold, GraphicsUnit.Point);
            btn_cancel.ForeColor = Color.White;
            btn_cancel.Location = new Point(533, 526);
            btn_cancel.Name = "btn_cancel";
            btn_cancel.Size = new Size(194, 71);
            btn_cancel.TabIndex = 2;
            btn_cancel.Text = "취소하기";
            btn_cancel.UseVisualStyleBackColor = false;
            btn_cancel.Click += btn_cancel_Click;
            // 
            // btn_reservation
            // 
            btn_reservation.BackColor = Color.Blue;
            btn_reservation.Font = new Font("맑은 고딕", 11.25F, FontStyle.Bold, GraphicsUnit.Point);
            btn_reservation.ForeColor = Color.White;
            btn_reservation.Location = new Point(200, 526);
            btn_reservation.Name = "btn_reservation";
            btn_reservation.Size = new Size(194, 71);
            btn_reservation.TabIndex = 2;
            btn_reservation.Text = "예매하기";
            btn_reservation.UseVisualStyleBackColor = false;
            btn_reservation.Click += btn_reservation_Click;
            // 
            // panel1
            // 
            panel1.Controls.Add(textBox1);
            panel1.Location = new Point(25, 282);
            panel1.Name = "panel1";
            panel1.Size = new Size(865, 238);
            panel1.TabIndex = 1;
            // 
            // textBox1
            // 
            textBox1.Dock = DockStyle.Fill;
            textBox1.Location = new Point(0, 0);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(865, 238);
            textBox1.TabIndex = 0;
            textBox1.Text = "";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(btn_noise);
            groupBox1.Controls.Add(btn_fantastic);
            groupBox1.Controls.Add(btn_f1);
            groupBox1.Controls.Add(btn_dokza);
            groupBox1.Controls.Add(btn_zombie);
            groupBox1.ForeColor = Color.White;
            groupBox1.Location = new Point(12, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(896, 249);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "현재 상영작";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label6.Location = new Point(774, 215);
            label6.Name = "label6";
            label6.Size = new Size(58, 21);
            label6.TabIndex = 1;
            label6.Text = "노이즈";
            label6.Click += label2_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label5.Location = new Point(536, 215);
            label5.Name = "label5";
            label5.Size = new Size(179, 21);
            label5.TabIndex = 1;
            label5.Text = "판타스틱4: 새로운 출발";
            label5.Click += label2_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label4.Location = new Point(402, 215);
            label4.Name = "label4";
            label4.Size = new Size(87, 21);
            label4.TabIndex = 1;
            label4.Text = "F1 더 무비";
            label4.Click += label2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label3.Location = new Point(203, 215);
            label3.Name = "label3";
            label3.Size = new Size(134, 21);
            label3.TabIndex = 1;
            label3.Text = "전지적 독자 시점";
            label3.Click += label2_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label2.Location = new Point(75, 215);
            label2.Name = "label2";
            label2.Size = new Size(58, 21);
            label2.TabIndex = 1;
            label2.Text = "좀비딸";
            label2.Click += label2_Click;
            // 
            // btn_noise
            // 
            btn_noise.BackgroundImage = (Image)resources.GetObject("btn_noise.BackgroundImage");
            btn_noise.BackgroundImageLayout = ImageLayout.Stretch;
            btn_noise.Location = new Point(728, 40);
            btn_noise.Name = "btn_noise";
            btn_noise.Size = new Size(150, 160);
            btn_noise.TabIndex = 0;
            btn_noise.UseVisualStyleBackColor = true;
            btn_noise.Click += btn_noise_Click;
            // 
            // btn_fantastic
            // 
            btn_fantastic.BackgroundImage = (Image)resources.GetObject("btn_fantastic.BackgroundImage");
            btn_fantastic.BackgroundImageLayout = ImageLayout.Stretch;
            btn_fantastic.Location = new Point(550, 40);
            btn_fantastic.Name = "btn_fantastic";
            btn_fantastic.Size = new Size(150, 160);
            btn_fantastic.TabIndex = 0;
            btn_fantastic.UseVisualStyleBackColor = true;
            btn_fantastic.Click += btn_fantastic_Click;
            // 
            // btn_f1
            // 
            btn_f1.BackgroundImage = (Image)resources.GetObject("btn_f1.BackgroundImage");
            btn_f1.BackgroundImageLayout = ImageLayout.Stretch;
            btn_f1.Location = new Point(371, 40);
            btn_f1.Name = "btn_f1";
            btn_f1.Size = new Size(150, 160);
            btn_f1.TabIndex = 0;
            btn_f1.UseVisualStyleBackColor = true;
            btn_f1.Click += btn_f1_Click;
            // 
            // btn_dokza
            // 
            btn_dokza.BackgroundImage = (Image)resources.GetObject("btn_dokza.BackgroundImage");
            btn_dokza.BackgroundImageLayout = ImageLayout.Stretch;
            btn_dokza.Location = new Point(203, 40);
            btn_dokza.Name = "btn_dokza";
            btn_dokza.Size = new Size(150, 160);
            btn_dokza.TabIndex = 0;
            btn_dokza.UseVisualStyleBackColor = true;
            btn_dokza.Click += btn_dokza_Click;
            // 
            // btn_zombie
            // 
            btn_zombie.BackgroundImage = (Image)resources.GetObject("btn_zombie.BackgroundImage");
            btn_zombie.BackgroundImageLayout = ImageLayout.Stretch;
            btn_zombie.Location = new Point(28, 40);
            btn_zombie.Name = "btn_zombie";
            btn_zombie.Size = new Size(150, 160);
            btn_zombie.TabIndex = 0;
            btn_zombie.UseVisualStyleBackColor = true;
            btn_zombie.Click += btn_zombie_Click;
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(64, 64, 64);
            ClientSize = new Size(915, 656);
            Controls.Add(splitContainer1);
            Name = "Form1";
            Text = "CGV";
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            panel1.ResumeLayout(false);
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private SplitContainer splitContainer1;
        private Label label1;
        private System.Windows.Forms.Timer timer1;
        private Label lblClock;
        private GroupBox groupBox1;
        private Button btn_noise;
        private Button btn_fantastic;
        private Button btn_f1;
        private Button btn_dokza;
        private Button btn_zombie;
        private Label label2;
        private Label label6;
        private Label label5;
        private Label label4;
        private Label label3;
        private Panel panel1;
        private Button btn_cancel;
        private Button btn_reservation;
        private RichTextBox textBox1;
    }
}
