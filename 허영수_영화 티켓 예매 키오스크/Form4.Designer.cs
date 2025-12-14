namespace kiosk
{
    partial class Form4
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
            label15 = new Label();
            lbl_children = new Label();
            lbl_teenager = new Label();
            lbl_adult = new Label();
            domainUpDown2 = new DomainUpDown();
            lb_movie = new Label();
            label10 = new Label();
            label9 = new Label();
            label6 = new Label();
            label8 = new Label();
            label7 = new Label();
            label14 = new Label();
            lb_result2 = new Label();
            label12 = new Label();
            label13 = new Label();
            label5 = new Label();
            label11 = new Label();
            btn_pay = new Button();
            label4 = new Label();
            btn_back2 = new Button();
            pictureBox1 = new PictureBox();
            label1 = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
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
            splitContainer1.Panel2.Controls.Add(label15);
            splitContainer1.Panel2.Controls.Add(lbl_children);
            splitContainer1.Panel2.Controls.Add(lbl_teenager);
            splitContainer1.Panel2.Controls.Add(lbl_adult);
            splitContainer1.Panel2.Controls.Add(domainUpDown2);
            splitContainer1.Panel2.Controls.Add(lb_movie);
            splitContainer1.Panel2.Controls.Add(label10);
            splitContainer1.Panel2.Controls.Add(label9);
            splitContainer1.Panel2.Controls.Add(label6);
            splitContainer1.Panel2.Controls.Add(label8);
            splitContainer1.Panel2.Controls.Add(label7);
            splitContainer1.Panel2.Controls.Add(label14);
            splitContainer1.Panel2.Controls.Add(lb_result2);
            splitContainer1.Panel2.Controls.Add(label12);
            splitContainer1.Panel2.Controls.Add(label13);
            splitContainer1.Panel2.Controls.Add(label5);
            splitContainer1.Panel2.Controls.Add(label11);
            splitContainer1.Panel2.Controls.Add(btn_pay);
            splitContainer1.Panel2.Controls.Add(label4);
            splitContainer1.Panel2.Controls.Add(btn_back2);
            splitContainer1.Panel2.Controls.Add(pictureBox1);
            splitContainer1.Panel2.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            splitContainer1.Panel2.ForeColor = Color.White;
            splitContainer1.Size = new Size(915, 656);
            splitContainer1.SplitterDistance = 48;
            splitContainer1.SplitterWidth = 1;
            splitContainer1.TabIndex = 8;
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
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(489, 106);
            label15.Name = "label15";
            label15.Size = new Size(64, 21);
            label15.TabIndex = 25;
            label15.Text = "label15";
            // 
            // lbl_children
            // 
            lbl_children.AutoSize = true;
            lbl_children.Location = new Point(489, 252);
            lbl_children.Name = "lbl_children";
            lbl_children.Size = new Size(64, 21);
            lbl_children.TabIndex = 24;
            lbl_children.Text = "label13";
            // 
            // lbl_teenager
            // 
            lbl_teenager.AutoSize = true;
            lbl_teenager.Location = new Point(490, 201);
            lbl_teenager.Name = "lbl_teenager";
            lbl_teenager.Size = new Size(64, 21);
            lbl_teenager.TabIndex = 24;
            lbl_teenager.Text = "label13";
            // 
            // lbl_adult
            // 
            lbl_adult.AutoSize = true;
            lbl_adult.Location = new Point(490, 154);
            lbl_adult.Name = "lbl_adult";
            lbl_adult.Size = new Size(64, 21);
            lbl_adult.TabIndex = 24;
            lbl_adult.Text = "label13";
            // 
            // domainUpDown2
            // 
            domainUpDown2.ForeColor = Color.Black;
            domainUpDown2.Location = new Point(562, 332);
            domainUpDown2.Name = "domainUpDown2";
            domainUpDown2.Size = new Size(120, 29);
            domainUpDown2.TabIndex = 23;
            // 
            // lb_movie
            // 
            lb_movie.AutoSize = true;
            lb_movie.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            lb_movie.ForeColor = Color.White;
            lb_movie.Location = new Point(426, 106);
            lb_movie.Name = "lb_movie";
            lb_movie.Size = new Size(42, 21);
            lb_movie.TabIndex = 22;
            lb_movie.Text = "영화";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label10.ForeColor = Color.White;
            label10.Location = new Point(571, 252);
            label10.Name = "label10";
            label10.Size = new Size(100, 21);
            label10.TabIndex = 19;
            label10.Text = "인당 9000원";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(571, 201);
            label9.Name = "label9";
            label9.Size = new Size(109, 21);
            label9.TabIndex = 20;
            label9.Text = "인당 11000원";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.White;
            label6.Location = new Point(571, 154);
            label6.Name = "label6";
            label6.Size = new Size(109, 21);
            label6.TabIndex = 21;
            label6.Text = "인당 15000원";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label8.ForeColor = Color.White;
            label8.Location = new Point(426, 252);
            label8.Name = "label8";
            label8.Size = new Size(58, 21);
            label8.TabIndex = 17;
            label8.Text = "어린이";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label7.ForeColor = Color.White;
            label7.Location = new Point(426, 201);
            label7.Name = "label7";
            label7.Size = new Size(58, 21);
            label7.TabIndex = 18;
            label7.Text = "청소년";
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.ForeColor = Color.White;
            label14.Location = new Point(574, 297);
            label14.Name = "label14";
            label14.Size = new Size(17, 21);
            label14.TabIndex = 16;
            label14.Text = "-";
            // 
            // lb_result2
            // 
            lb_result2.AutoSize = true;
            lb_result2.Font = new Font("맑은 고딕", 18F, FontStyle.Bold, GraphicsUnit.Point);
            lb_result2.ForeColor = Color.White;
            lb_result2.Location = new Point(574, 419);
            lb_result2.Name = "lb_result2";
            lb_result2.Size = new Size(24, 32);
            lb_result2.TabIndex = 16;
            lb_result2.Text = "-";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label12.ForeColor = Color.White;
            label12.Location = new Point(426, 334);
            label12.Name = "label12";
            label12.Size = new Size(80, 21);
            label12.TabIndex = 15;
            label12.Text = "결제 수단";
            // 
            // label13
            // 
            label13.AutoSize = true;
            label13.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label13.ForeColor = Color.White;
            label13.Location = new Point(426, 297);
            label13.Name = "label13";
            label13.Size = new Size(74, 21);
            label13.TabIndex = 15;
            label13.Text = "상영시간";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("맑은 고딕", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.White;
            label5.Location = new Point(426, 419);
            label5.Name = "label5";
            label5.Size = new Size(94, 32);
            label5.TabIndex = 15;
            label5.Text = "총 가격";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("맑은 고딕", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label11.ForeColor = Color.White;
            label11.Location = new Point(426, 154);
            label11.Name = "label11";
            label11.Size = new Size(42, 21);
            label11.TabIndex = 14;
            label11.Text = "성인";
            // 
            // btn_pay
            // 
            btn_pay.BackColor = Color.Blue;
            btn_pay.Location = new Point(512, 527);
            btn_pay.Name = "btn_pay";
            btn_pay.Size = new Size(170, 45);
            btn_pay.TabIndex = 5;
            btn_pay.Text = "결제하기";
            btn_pay.UseVisualStyleBackColor = false;
            btn_pay.Click += btn_pay_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("맑은 고딕", 26.25F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Lime;
            label4.Location = new Point(473, 38);
            label4.Name = "label4";
            label4.Size = new Size(90, 47);
            label4.TabIndex = 4;
            label4.Text = "결제";
            // 
            // btn_back2
            // 
            btn_back2.BackColor = Color.Blue;
            btn_back2.Location = new Point(196, 527);
            btn_back2.Name = "btn_back2";
            btn_back2.Size = new Size(170, 45);
            btn_back2.TabIndex = 3;
            btn_back2.Text = "뒤로가기";
            btn_back2.UseVisualStyleBackColor = false;
            btn_back2.Click += btn_back2_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.Location = new Point(30, 46);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(336, 377);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.TabIndex = 0;
            pictureBox1.TabStop = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(81, 316);
            label1.Name = "label1";
            label1.Size = new Size(60, 25);
            label1.TabIndex = 7;
            label1.Text = "CGV";
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // Form4
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(915, 656);
            Controls.Add(splitContainer1);
            Controls.Add(label1);
            Name = "Form4";
            Text = "Form4";
            Load += Form4_Load;
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
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
        private PictureBox pictureBox1;
        private Button btn_back2;
        private Button btn_pay;
        private Label label4;
        private Label lb_movie;
        private Label label10;
        private Label label9;
        private Label label6;
        private Label label8;
        private Label label7;
        private Label lb_result2;
        private Label label5;
        private Label label11;
        private DomainUpDown domainUpDown2;
        private Label label12;
        private Label lbl_children;
        private Label lbl_teenager;
        private Label lbl_adult;
        private Label label14;
        private Label label13;
        private Label label15;
    }
}