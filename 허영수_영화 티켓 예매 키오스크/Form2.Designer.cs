namespace kiosk
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
            components = new System.ComponentModel.Container();
            timer1 = new System.Windows.Forms.Timer(components);
            lblClock = new Label();
            label1 = new Label();
            splitContainer1 = new SplitContainer();
            label2 = new Label();
            label3 = new Label();
            btn_back1 = new Button();
            groupBox1 = new GroupBox();
            domainUpDown1 = new DomainUpDown();
            lb_movie = new Label();
            label10 = new Label();
            label9 = new Label();
            label6 = new Label();
            btn_seat = new Button();
            btn_select = new Button();
            label8 = new Label();
            label7 = new Label();
            label12 = new Label();
            lb_result = new Label();
            label11 = new Label();
            label5 = new Label();
            pictureBox1 = new PictureBox();
            numericUpDown3 = new NumericUpDown();
            label4 = new Label();
            numericUpDown2 = new NumericUpDown();
            numericUpDown1 = new NumericUpDown();
            listView2 = new ListView();
            listView1 = new ListView();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).BeginInit();
            SuspendLayout();
            // 
            // timer1
            // 
            timer1.Tick += timer1_Tick;
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
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(81, 316);
            label1.Name = "label1";
            label1.Size = new Size(60, 25);
            label1.TabIndex = 2;
            label1.Text = "CGV";
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
            splitContainer1.Panel2.Controls.Add(btn_back1);
            splitContainer1.Panel2.Controls.Add(groupBox1);
            splitContainer1.Panel2.Controls.Add(listView2);
            splitContainer1.Panel2.Controls.Add(listView1);
            splitContainer1.Size = new Size(915, 656);
            splitContainer1.SplitterDistance = 48;
            splitContainer1.SplitterWidth = 1;
            splitContainer1.TabIndex = 4;
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
            // btn_back1
            // 
            btn_back1.BackColor = Color.Blue;
            btn_back1.Font = new Font("맑은 고딕", 11.25F, FontStyle.Bold, GraphicsUnit.Point);
            btn_back1.ForeColor = Color.White;
            btn_back1.Location = new Point(367, 527);
            btn_back1.Name = "btn_back1";
            btn_back1.Size = new Size(170, 45);
            btn_back1.TabIndex = 2;
            btn_back1.Text = "취소하기";
            btn_back1.UseVisualStyleBackColor = false;
            btn_back1.Click += btn_back1_Click;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(domainUpDown1);
            groupBox1.Controls.Add(lb_movie);
            groupBox1.Controls.Add(label10);
            groupBox1.Controls.Add(label9);
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(btn_seat);
            groupBox1.Controls.Add(btn_select);
            groupBox1.Controls.Add(label8);
            groupBox1.Controls.Add(label7);
            groupBox1.Controls.Add(label12);
            groupBox1.Controls.Add(lb_result);
            groupBox1.Controls.Add(label11);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(pictureBox1);
            groupBox1.Controls.Add(numericUpDown3);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(numericUpDown2);
            groupBox1.Controls.Add(numericUpDown1);
            groupBox1.Font = new Font("맑은 고딕", 11.25F, FontStyle.Bold, GraphicsUnit.Point);
            groupBox1.ForeColor = Color.White;
            groupBox1.Location = new Point(367, 27);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(536, 440);
            groupBox1.TabIndex = 1;
            groupBox1.TabStop = false;
            // 
            // domainUpDown1
            // 
            domainUpDown1.Items.Add("");
            domainUpDown1.Location = new Point(78, 52);
            domainUpDown1.Name = "domainUpDown1";
            domainUpDown1.Size = new Size(120, 27);
            domainUpDown1.TabIndex = 10;
            domainUpDown1.Text = "좀비딸";
            // 
            // lb_movie
            // 
            lb_movie.AutoSize = true;
            lb_movie.Location = new Point(18, 54);
            lb_movie.Name = "lb_movie";
            lb_movie.Size = new Size(39, 20);
            lb_movie.TabIndex = 9;
            lb_movie.Text = "영화";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(151, 200);
            label10.Name = "label10";
            label10.Size = new Size(95, 20);
            label10.TabIndex = 8;
            label10.Text = "인당 9000원";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(151, 151);
            label9.Name = "label9";
            label9.Size = new Size(104, 20);
            label9.TabIndex = 8;
            label9.Text = "인당 11000원";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(151, 102);
            label6.Name = "label6";
            label6.Size = new Size(104, 20);
            label6.TabIndex = 8;
            label6.Text = "인당 15000원";
            // 
            // btn_seat
            // 
            btn_seat.BackColor = Color.Blue;
            btn_seat.ForeColor = Color.Lime;
            btn_seat.Location = new Point(43, 377);
            btn_seat.Name = "btn_seat";
            btn_seat.Size = new Size(170, 44);
            btn_seat.TabIndex = 7;
            btn_seat.Text = "좌석";
            btn_seat.UseVisualStyleBackColor = false;
            btn_seat.Click += btn_seat_Click;
            // 
            // btn_select
            // 
            btn_select.BackColor = Color.Blue;
            btn_select.ForeColor = Color.Lime;
            btn_select.Location = new Point(43, 326);
            btn_select.Name = "btn_select";
            btn_select.Size = new Size(170, 45);
            btn_select.TabIndex = 6;
            btn_select.Text = "선택";
            btn_select.UseVisualStyleBackColor = false;
            btn_select.Click += btn_select_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(18, 200);
            label8.Name = "label8";
            label8.Size = new Size(54, 20);
            label8.TabIndex = 5;
            label8.Text = "어린이";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(18, 149);
            label7.Name = "label7";
            label7.Size = new Size(54, 20);
            label7.TabIndex = 5;
            label7.Text = "청소년";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(151, 240);
            label12.Name = "label12";
            label12.Size = new Size(15, 20);
            label12.TabIndex = 4;
            label12.Text = "-";
            // 
            // lb_result
            // 
            lb_result.AutoSize = true;
            lb_result.Location = new Point(151, 274);
            lb_result.Name = "lb_result";
            lb_result.Size = new Size(15, 20);
            lb_result.TabIndex = 4;
            lb_result.Text = "-";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(18, 240);
            label11.Name = "label11";
            label11.Size = new Size(74, 20);
            label11.TabIndex = 3;
            label11.Text = "상영 시간";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(18, 274);
            label5.Name = "label5";
            label5.Size = new Size(59, 20);
            label5.TabIndex = 3;
            label5.Text = "총 가격";
            // 
            // pictureBox1
            // 
            pictureBox1.Image = Properties.Resources.zombie;
            pictureBox1.Location = new Point(258, 44);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(261, 329);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.TabIndex = 2;
            pictureBox1.TabStop = false;
            // 
            // numericUpDown3
            // 
            numericUpDown3.AutoSize = true;
            numericUpDown3.Location = new Point(78, 198);
            numericUpDown3.Name = "numericUpDown3";
            numericUpDown3.Size = new Size(52, 27);
            numericUpDown3.TabIndex = 0;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(18, 102);
            label4.Name = "label4";
            label4.Size = new Size(39, 20);
            label4.TabIndex = 1;
            label4.Text = "성인";
            // 
            // numericUpDown2
            // 
            numericUpDown2.AutoSize = true;
            numericUpDown2.Location = new Point(78, 149);
            numericUpDown2.Name = "numericUpDown2";
            numericUpDown2.Size = new Size(52, 27);
            numericUpDown2.TabIndex = 0;
            // 
            // numericUpDown1
            // 
            numericUpDown1.AutoSize = true;
            numericUpDown1.Location = new Point(78, 100);
            numericUpDown1.Name = "numericUpDown1";
            numericUpDown1.Size = new Size(52, 27);
            numericUpDown1.TabIndex = 0;
            // 
            // listView2
            // 
            listView2.FullRowSelect = true;
            listView2.GridLines = true;
            listView2.Location = new Point(42, 248);
            listView2.Name = "listView2";
            listView2.Size = new Size(290, 193);
            listView2.TabIndex = 0;
            listView2.UseCompatibleStateImageBehavior = false;
            listView2.SelectedIndexChanged += listView2_SelectedIndexChanged;
            // 
            // listView1
            // 
            listView1.FullRowSelect = true;
            listView1.GridLines = true;
            listView1.Location = new Point(42, 27);
            listView1.Name = "listView1";
            listView1.Size = new Size(290, 193);
            listView1.TabIndex = 0;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.SelectedIndexChanged += listView1_SelectedIndexChanged;
            listView1.DoubleClick += listView1_DoubleClick;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(915, 656);
            Controls.Add(splitContainer1);
            Controls.Add(label1);
            Name = "Form2";
            Text = "Form2";
            Load += Form2_Load;
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown3).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown2).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private Label lblClock;
        private Label label1;
        private SplitContainer splitContainer1;
        private Label label2;
        private Label label3;
        private ListView listView1;
        private GroupBox groupBox1;
        private Label label4;
        private NumericUpDown numericUpDown1;
        private PictureBox pictureBox1;
        private Label label5;
        private Label label8;
        private Label label7;
        private Label lb_result;
        private NumericUpDown numericUpDown3;
        private NumericUpDown numericUpDown2;
        private Button btn_select;
        private Button btn_seat;
        private Label label10;
        private Label label9;
        private Label label6;
        private ListView listView2;
        private Button btn_back1;
        private DomainUpDown domainUpDown1;
        private Label lb_movie;
        private Label label12;
        private Label label11;
    }
}