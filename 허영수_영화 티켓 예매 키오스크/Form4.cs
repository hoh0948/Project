using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kiosk
{
    public partial class Form4 : Form
    {
        private List<string> selectedSeatDetails;
        public Form4(Image image, string title, string paymentMethod, int adultCount, int teenagerCount, int childCount, int totalPeople, int totalAmount, string screeningInfo, List<string> selectedSeatDetails)
        {
            InitializeComponent(); // 디자이너에서 생성된 초기화 로직 호출
            StartClock(); // 시계 업데이트 시작
            pictureBox1.Image = image; // 전달받은 영화 이미지를 pictureBox에 설정
            label15.Text = paymentMethod; // 전달받은 결제 방법을 드롭다운에 설정

            domainUpDown2.Items.Add("신용카드"); // 결제 옵션 추가
            domainUpDown2.Items.Add("현금결제"); // 결제 옵션 추가
            domainUpDown2.Items.Add("카카오페이"); // 결제 옵션 추가
            domainUpDown2.Items.Add("네이버페이"); // 결제 옵션 추가

            lbl_adult.Text = adultCount.ToString(); // 성인 인원 수 설정
            lbl_teenager.Text = teenagerCount.ToString(); // 청소년 인원 수 설정
            lbl_children.Text = childCount.ToString(); // 아동 인원 수 설정
            lb_result2.Text = $"{totalPeople}명\n{totalAmount:N0}원"; // 총 인원 수와 금액 설정
            label14.Text = screeningInfo;
        }

        private void SetMovieImage(string title) // 영화 제목에 따라 이미지를 설정하는 메서드
        {
            switch (title) // 제목에 따른 이미지 매핑
            {
                case "좀비딸":
                    pictureBox1.Image = Properties.Resources.zombie; // "좀비딸" 이미지 로드
                    break;
                case "전지적 독자 시점":
                    pictureBox1.Image = Properties.Resources.omniscient; // "전지적 독자 시점" 이미지 로드
                    break;
                case "F1 더 무비":
                    pictureBox1.Image = Properties.Resources.F1; // "F1 더 무비" 이미지 로드
                    break;
                case "판타스틱4: 새로운 출발":
                    pictureBox1.Image = Properties.Resources.fantastic; // "판타스틱4: 새로운 출발" 이미지 로드
                    break;
                case "노이즈":
                    pictureBox1.Image = Properties.Resources.noise; // "노이즈" 이미지 로드
                    break;
                default:
                    pictureBox1.Image = null; // 기본값 (이미지 없음)
                    break;
            }
        }

        private void StartClock() // 시계 업데이트 시작 메서드
        {
            UpdateClock(); // 초기 시간 설정

            timer1.Tick += timer1_Tick; // 타이머 틱 이벤트 등록
            timer1.Start(); // 타이머 시작
        }

        private void timer1_Tick(object sender, EventArgs e) // 타이머 틱 이벤트 핸들러
        {
            UpdateClock(); // 시간 업데이트
        }

        private void UpdateClock() // 시계 라벨 업데이트 메서드
        {
            lblClock.Text = DateTime.Now.ToString("yyyy.MM.dd hh:mm:ss tt", CultureInfo.CreateSpecificCulture("en-US")); // 현재 시간 표시
        }

        private void btn_back2_Click(object sender, EventArgs e) // 뒤로가기 버튼 클릭 이벤트
        {
            Form2 form2 = new Form2(); // Form2 인스턴스 생성
            form2.Show(); // Form2 표시
            this.Close(); // 현재 폼 닫기
        }

        private void btn_pay_Click(object sender, EventArgs e) // 결제 버튼 클릭 이벤트
        {
            //DialogResult result = MessageBox.Show("결제하시겠습니까?", "취소 확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question); // 결제 확인 메시지
            //if (result == DialogResult.Yes) // "예" 선택 시
            //{
            //    string paymentMethod = domainUpDown2.Text;
            //    string amount = lb_result2.Text;

            //    MessageBox.Show($"{paymentMethod}으로 {lb_result2} 결제했습니다.", "결제 완료", MessageBoxButtons.OK, MessageBoxIcon.Information);
            //    MessageBox.Show("좋은 관람 되세요~~^^.", "감사합니다", MessageBoxButtons.OK, MessageBoxIcon.Information);

            //    this.Close();
            //}

            DialogResult result = MessageBox.Show("결제하시겠습니까?", "취소 확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question); // 결제 확인 메시지
            if (result == DialogResult.Yes) // "예" 선택 시
            {
                if (domainUpDown2.SelectedItem != null)
                {
                    string selectedPaymentMethod = domainUpDown2.SelectedItem.ToString();
                    DateTime paymentTime = DateTime.Now;
                    DialogResult dialogResult = MessageBox.Show($"{selectedPaymentMethod}으로 {lb_result2.Text} 결제했습니다.", "결제 완료", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    if (dialogResult == DialogResult.OK)
                    {
                        // 상영 시간 추출 (screeningInfo에서 "8:30 - 1관" → "8:30")
                        string screeningTime = !string.IsNullOrEmpty(label14.Text) && label14.Text.Contains(" - ") ? label14.Text.Split(new[] { " - " }, StringSplitOptions.None)[0] : "정보 없음";

                        // Form6로 데이터 전달
                        Form6 form6 = new Form6(
                            pictureBox1.Image, // 이미지
                            label15.Text, // 영화 제목
                            screeningTime, // 상영 시간
                            selectedPaymentMethod, // 결제 수단
                            lbl_adult.Text, // 성인 인원 수
                            lbl_teenager.Text, // 청소년 인원 수
                            lbl_children.Text, // 아동 인원 수
                            lb_result2.Text, // 총 인원 및 금액
                            selectedSeatDetails, // 좌석 정보
                            paymentTime,// 결제 시간
                            label14.Text
                        );
                        form6.Location = this.Location;
                        form6.Show();
                        this.Close();
                    }
                }
                else
                {
                    MessageBox.Show("결제 방법을 선택해 주세요.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }

        private void Form4_Load(object sender, EventArgs e) // 폼 로드 이벤트 (현재 비어 있음)
        {
            // 여기에 폼 로드 시 초기화 로직 추가 가능
        }
    }
}