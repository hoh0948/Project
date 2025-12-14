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
    public partial class Form6 : Form
    {
        private Image movieImage; // 전달받은 영화 이미지
        private string movieTitle; // 전달받은 영화 제목
        private string screeningTime; // 상영 시간
        private string paymentMethod; // 결제 수단
        private string adultCount; // 성인 인원 수
        private string teenagerCount; // 청소년 인원 수
        private string childCount; // 아동 인원 수
        private string totalInfo; // 총 인원 및 금액
        private List<string> selectedSeatDetails; // 선택된 좌석 정보
        private DateTime paymentTime;   //결제 시간
        private string screeningInfo;
        public Form6(Image image, string title, string screeningTime, string paymentMethod, string adultCount, string teenagerCount, string childCount, string totalInfo, List<string> selectedSeatDetails, DateTime paymentTime, string screeningInfo)
        {
            InitializeComponent(); // 디자이너에서 생성된 초기화 로직 호출
            this.timer1 = new System.Windows.Forms.Timer(); // 타이머 초기화
            


            this.movieImage = image;
            this.movieTitle = title ?? "제공된 제목 없음";
            this.screeningTime = screeningTime ?? "정보 없음";
            this.paymentMethod = paymentMethod ?? "결제 수단 없음";
            this.adultCount = adultCount ?? "0";
            this.teenagerCount = teenagerCount ?? "0";
            this.childCount = childCount ?? "0";
            this.totalInfo = totalInfo ?? "정보 없음";
            this.selectedSeatDetails = selectedSeatDetails ?? new List<string>();
            this.screeningInfo = screeningInfo ?? "정보 없음";

            // UI 초기화
            label6.Text = movieTitle; // 영화 제목
            label9.Text = screeningTime; // 상영 시간
            //string theaterInfo = !string.IsNullOrEmpty(totalInfo) && totalInfo.Contains(" - ") ? totalInfo.Split(new[] { " - " }, StringSplitOptions.None)[1] : "상영관 정보 없음";
            //label8.Text = $"좌석: {string.Join(", ", this.selectedSeatDetails)}, 상영관: {theaterInfo}"; // 좌석 정보
            label10.Text = $"성인: {adultCount}명, 청소년: {teenagerCount}명, 아동: {childCount}명"; // 인원 수
            label11.Text = paymentTime.ToString("yyyy.MM.dd(ddd)", CultureInfo.CreateSpecificCulture("ko-KR"));
            label15.Text = GetEnglishTitle(movieTitle);
            label16.Text = screeningInfo;

            //pictureBox1.Image = movieImage;
        }

        private string GetEnglishTitle(string koreanTitle)
        {
            // 한글 제목을 영어 제목으로 매핑하는 딕셔너리
            var titleMap = new Dictionary<string, string>
            {
                { "좀비딸", "Zombie Daughter" },
                { "전지적 독자 시점", "Omniscient Reader's Viewpoint" },
                { "F1 더 무비", "F1 The Movie" },
                { "판타스틱4: 새로운 출발", "Fantastic Four: New Beginning" },
                { "노이즈", "Noise" },
                { "제공된 제목 없음", "No Title Provided" }
            };
            return titleMap.ContainsKey(koreanTitle) ? titleMap[koreanTitle] : "Unknown Title";
        }

        private void StartClock() // 시계 업데이트 시작 메서드
        {
            
        }

        private void timer1_Tick(object sender, EventArgs e) // 타이머 틱 이벤트 핸들러
        {
            //UpdateClock(); // 시간 업데이트
        }

        private void UpdateClock() // 시계 라벨 업데이트 메서드
        {
            //label11.Text = DateTime.Now.ToString("yyyy.MM.dd hh:mm:ss tt", CultureInfo.CreateSpecificCulture("en-US")); // 현재 시간 표시
        }

        private void btnConfirm_Click(object sender, EventArgs e) // 확인 버튼 클릭 이벤트
        {
            DialogResult result = MessageBox.Show("예매를 완료하시겠습니까?", "확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                Form1 form1 = new Form1(); // Form1 인스턴스 생성
                form1.Location = this.Location; // Form1의 위치를 Form6와 동일하게 설정
                form1.Show(); // Form1 표시
                this.Close(); // 현재 폼 닫기
            }
        }

        private void Form6_Load(object sender, EventArgs e) // 폼 로드 이벤트
        {
            // 추가 초기화 로직 (필요 시)
        }
    }
}
