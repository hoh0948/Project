using System.Drawing;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace kiosk
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            StartClock();

        }
        private void StartClock()
        {
            UpdateClock();

            timer1.Tick += timer1_Tick;
            timer1.Start();
            textBox1.Multiline = true;
        }
        
        private void timer1_Tick(object sender, EventArgs e)
        {
            UpdateClock();
        }
        private void UpdateClock()
        {
            lblClock.Text = DateTime.Now.ToString("yyyy.MM.dd hh:mm:sstt", CultureInfo.CreateSpecificCulture("en-US"));
        }

        private void btn_zombie_Click(object sender, EventArgs e)
        {
            string str = "";

            if (textBox1 != null)
            {
                textBox1.Clear();

                str += string.Format("제목 : 좀비딸\n");
                str += string.Format("장르 : 코미디, 호러, 드라마\n");
                str += string.Format("감독 : 필감성\n");
                str += string.Format("출연 : 조정석, 이정은, 조여정, 윤경호, 최유리\n");
                str += string.Format("원작 : 이윤창의 웹툰, 2022년 EBS 애니메이션\n");
                str += string.Format("줄거리 : 동물 조련사 이정환(조정석)이 좀비 바이러스에 감연된 딸 수아(최유리)를 보호하며 해안 마을로 피신, 딸을 훈련시키는 이야기를 코믹하고 감동적으로 그린다.\n");
                str += string.Format("상영 시간 : 2025.07.30 ~ 2025. 08.05\n");
                str += string.Format("특징 : 가족애와 다름을 포용하는 메시지, 조정석의 코믹 연기\n");
                str += string.Format("현재 상영중");

                textBox1.Text = str;
            }
            else
            {
                MessageBox.Show("textBox1이 초기화되지 않았습니다.");
            }
        }

        private void btn_dokza_Click(object sender, EventArgs e)
        {
            string str = "";
            if (textBox1 != null)
            {
                textBox1.Clear();
                str += string.Format("제목 : 전지적 독자 시점\n");
                str += string.Format("장르 : 판타지, 액션\n");
                str += string.Format("감독 : 김병우\n");
                str += string.Format("출연진 : 안효섭, 이민호, 채수빈, 신승호, 나나, 지수, 권은성 등\n");
                str += string.Format("개봉일 : 2025.07.23\n");
                str += string.Format("줄거리 : 평범한 회사원 김독자는 10년간 연재된 웹소설 '멸망한 세계에서 살아남는 세가지 방법'의 유일한 독자다. 소설이 완결된 날, 그 세계가 현실로 바뀌며 김독자는 소설의 내용을 이용해 주인공 유중혁과 동료들과 함께 멸망한 세상에서 살아남기 위해 싸운다.\n");
                str += string.Format("특징 : 포스트 아포칼립스 설정, RPG게임 요소(코인, 시나리오, 성좌 등) 도입, 화려한 CG와 액션\n");
                str += string.Format("현재 상영중\n");

                textBox1.Text = str;
            }
            else
            {
                MessageBox.Show("textBox1이 초기화되지 않았습니다.");
            }
        }

        private void btn_f1_Click(object sender, EventArgs e)
        {
            string str = "";
            if (textBox1 != null)
            {
                textBox1.Clear();
                str += string.Format("제목 : F1 더 무비\n");
                str += string.Format("장르 : 드라마, 스포츠, 액션\n");
                str += string.Format("감독 : 조셉 코신스키\n");
                str += string.Format("출연진 : 브래드 피트, 댐슨 이드리스, 하비에르 바르뎀 등\n");
                str += string.Format("개봉일 : 2025.06.25(IMAX 포함)\n");
                str += string.Format("줄거리 : 한때 최고의 레이서였던 남자가 약체 팀의 구원투수로 복귀해 젊은 드라이버와 함께 불가능에 도전하는 이야기\n");
                str += string.Format("특징 : 실제 F1 경기장에서 촬영, 리얼한 레이싱 장면\n");
                str += string.Format("현재 상영중\n");

                textBox1.Text = str;
            }
            else
            {
                MessageBox.Show("textBox1이 초기화되지 않았습니다.");
            }
        }

        private void btn_fantastic_Click(object sender, EventArgs e)
        {
            string str = "";
            if (textBox1 != null)
            {
                textBox1.Clear();
                str += string.Format("제목 : 판타스틱4: 새로운 출발\n");
                str += string.Format("장르 : 슈퍼히어로 액션, SF, 판타지\n");
                str += string.Format("감독 : 맷 샤크먼\n");
                str += string.Format("출연진 : 페드로 파스칼, 바네사 커비, 조셉 퀸, 랄프 이네슨 등\n");
                str += string.Format("개봉일 : 2025.07.24\n");
                str += string.Format("줄거리 : 판타스틱4팀이 대체 우주에서 강력한 우주적 적 갈락투스와 실버 서퍼에 맞서 지구와 가족을 지키는 이야기\n");
                str += string.Format("특징 : 기원 스토리 없이 완성된 팀으로 시작, 레트로 스타일과 판타지 결합\n");
                str += string.Format("현재 상영중\n");

                textBox1.Text = str;
            }
            else
            {
                MessageBox.Show("textBox1이 초기화되지 않았습니다.");
            }
        }

        private void btn_noise_Click(object sender, EventArgs e)
        {
            string str = "";
            if (textBox1 != null)
            {
                textBox1.Clear();
                str += string.Format("제목 : 노이즈\n");
                str += string.Format("장르 : 공포, 스릴러, 미스터리\n");
                str += string.Format("감독 : 김수진\n");
                str += string.Format("출연진 : 이선빈, 김민석, 한수아, 류경수 등\n");
                str += string.Format("개봉일 : 2025.06.25\n");
                str += string.Format("줄거리 : 층간소음으로 벌어지는 미스터리한 실종 사건을 청각장애 주인공이 파헤치는 현실 공포 스릴러 영화\n");
                str += string.Format("특징 : 청각장애를 가진 주인공의 시각적 공포 표현, 현실적 소재의 공포 접근, 심리 스릴러와 미스터리의 결합\n");
                str += string.Format("현재 상영중\n");

                textBox1.Text = str;
            }
            else
            {
                MessageBox.Show("textBox1이 초기화되지 않았습니다.");
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btn_reservation_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("예약하시겠습니까?", "예약 확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes )
            {
                Form2 form2 = new Form2();
                form2.Location = this.Location;
                form2.Show();
                this.Hide();
            }
            
        }

        private void btn_cancel_Click(object sender, EventArgs e)
        {

        }
    }
}
