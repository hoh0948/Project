using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kiosk
{
    public partial class Form3 : Form
    {
        private List<Button> selectedSeats = new List<Button>(); // 사용자가 선택한 좌석 버튼을 저장하는 리스트
        private List<Button> reservedSeats = new List<Button>(); // 이미 예약된 좌석 버튼을 저장하는 리스트
        private Dictionary<Button, string> seatInfo = new Dictionary<Button, string>(); // 버튼과 좌석 정보(예: "A열-1번")를 매핑하는 딕셔너리
        private List<string> selectedSeatDetails = new List<string>();
        //private Form2 form2; // Form2 참조 (현재 주석 처리)
        private Image movieImage; // 전달받은 영화 이미지
        private string movieTitle; // 전달받은 영화 제목
        private string paymentMethod; // 전달받은 결제 방법
        private int adultCount; // 성인 인원 수
        private int teenagerCount; // 청소년 인원 수
        private int childCount; // 아동 인원 수
        private int totalPeople; // 총 인원 수
        private int totalAmount; // 총 금액
        private string screeningInfo; // 상영 시간 및 상영관 정보 (label12 값)

        public Form3(Image movieImage, string title, string paymentMethod, int adultCount, int teenagerCount, int childCount, int totalPeople, int totalAmount, string screeningInfo)
        {
            InitializeComponent(); // 디자이너에서 생성된 초기화 로직 호출
            StartClock(); // 시계 업데이트 시작
            panel1.Controls.Clear(); // 패널의 기존 컨트롤 제거

            int rows = 10; // 좌석 행 수 (A~J)
            int cols = 15; // 좌석 열 수 (1~15)
            int btnSize = 30; // 버튼 크기 (픽셀)
            int spacing = 10; // 버튼 간 간격 (픽셀)
            int labelOffset = 50; // 행 라벨의 왼쪽 오프셋

            int totalWidth = (btnSize + spacing) * cols; // 전체 너비 계산
            int startX = (panel1.Width - totalWidth) / 2; // 패널 중앙 정렬을 위한 시작 X 좌표
            int startY = 60; // 시작 Y 좌표 (스크린 라벨 아래)

            for (int i = 0; i < rows; i++) // 각 행에 대해 반복
            {
                // 행 표시 라벨 (A~J) 생성
                Label rowLabel = new Label();
                rowLabel.Text = ((char)('A' + i)).ToString(); // A부터 J까지 문자 생성
                rowLabel.ForeColor = Color.White; // 텍스트 색상 흰색
                rowLabel.Size = new Size(30, btnSize); // 라벨 크기 설정
                rowLabel.Location = new Point(startX - labelOffset, startY + i * (btnSize + spacing)); // 위치 설정
                panel1.Controls.Add(rowLabel); // 패널에 라벨 추가

                for (int j = 0; j < cols; j++) // 각 열에 대해 반복
                {
                    Button btn = new Button(); // 새 버튼 생성
                    btn.Size = new Size(btnSize, btnSize); // 버튼 크기 설정
                    btn.Location = new Point(startX + j * (btnSize + spacing), startY + i * (btnSize + spacing)); // 위치 계산
                    btn.Text = (j + 1).ToString(); // 버튼에 열 번호 표시 (1~15)
                    btn.Tag = $"{(char)('A' + i)}열-{j + 1}번"; // 좌석 정보 태그에 저장 (예: "A열-1번")
                    btn.BackColor = Color.LightGray; // 기본 배경색 설정

                    seatInfo[btn] = btn.Tag.ToString(); // 딕셔너리에 버튼과 좌석 정보 매핑

                    btn.Click += (s, e) => // 버튼 클릭 이벤트 핸들러
                    {
                        Button b = s as Button; // 클릭된 버튼으로 캐스팅
                        if (b != null && !reservedSeats.Contains(b)) // 버튼이 null이 아니고 예약된 좌석이 아닐 경우
                        {
                            if (b.BackColor == Color.LightGray) // 선택되지 않은 상태
                            {
                                b.BackColor = Color.Green; // 초록색으로 변경 (선택 표시)
                                if (!selectedSeats.Contains(b)) // 중복 방지
                                    selectedSeats.Add(b); // 선택된 좌석 리스트에 추가
                            }
                            else if (b.BackColor == Color.Green) // 선택된 상태
                            {
                                b.BackColor = Color.LightGray; // 회색으로 복귀 (선택 해제)
                                selectedSeats.Remove(b); // 선택된 좌석 리스트에서 제거
                            }
                        }
                    };

                    // 예약된 좌석 조건 (빨간색, 클릭 불가)
                    if (((((i == 1 && (j == 9 || j == 10 || j == 11 || j == 12)) || // 2행 9~12열
                        (i == 0 && (j == 9 || j == 10 || j == 11 || j == 12)) || // 1행 9~12열
                        (i == 4 && j == 13) || // 5행 14열
                        (i == 5 && (j == 5 || j == 6 || j ==7 || j == 8)) ||
                        (i == 7 && (j == 0 || j == 1 || j == 2 || j == 3)) ||
                        (i == 5 && (j == 13 || j == 14 )) ||
                        (i == 9) && (j == 10)))))
                    {
                        btn.BackColor = Color.Red; // 빨간색으로 표시
                        btn.Enabled = false; // 클릭 비활성화
                        reservedSeats.Add(btn); // 예약된 좌석 리스트에 추가
                    }

                    panel1.Controls.Add(btn); // 패널에 버튼 추가
                }
            }
            Label screenLabel = new Label(); // 스크린 표시 라벨 생성
            screenLabel.Text = "SCREEN"; // 텍스트 설정
            screenLabel.Font = new Font("Arial", 14, FontStyle.Bold); // 글꼴 설정
            screenLabel.ForeColor = Color.White; // 텍스트 색상
            screenLabel.BackColor = Color.DarkGray; // 배경색
            screenLabel.TextAlign = ContentAlignment.MiddleCenter; // 중앙 정렬
            screenLabel.Width = panel1.Width; // 패널 너비에 맞춤
            screenLabel.Height = 30; // 높이 설정
            screenLabel.Location = new Point(0, 0); // 상단에 위치
            panel1.Controls.Add(screenLabel); // 패널에 라벨 추가

            this.movieImage = movieImage; // 전달받은 영화 이미지 저장
            this.movieTitle = title; // 전달받은 영화 제목 저장
            this.paymentMethod = paymentMethod; // 전달받은 결제 방법 저장
            this.adultCount = adultCount; // 전달받은 성인 인원 수 저장
            this.teenagerCount = teenagerCount; // 전달받은 청소년 인원 수 저장
            this.childCount = childCount; // 전달받은 아동 인원 수 저장
            this.totalPeople = totalPeople; // 전달받은 총 인원 수 저장
            this.totalAmount = totalAmount; // 전달받은 총 금액 저장
            this.screeningInfo = screeningInfo; // 전달받은 상영 시간 및 상영관 정보 저장
        }

        public Image SelectedImage => movieImage; // 선택된 영화 이미지를 반환하는 속성
        public string SelectedTitle => movieTitle; // 선택된 영화 제목을 반환하는 속성
        public string SelectedPayment => paymentMethod; // 선택된 결제 방법을 반환하는 속성
        public int SelectedAdultCount => adultCount; // 선택된 성인 인원 수를 반환하는 속성
        public int SelectedTeenagerCount => teenagerCount; // 선택된 청소년 인원 수를 반환하는 속성
        public int SelectedChildCount => childCount; // 선택된 아동 인원 수를 반환하는 속성
        public int TotalPeople => totalPeople; // 총 인원 수를 반환하는 속성
        public int TotalAmount => totalAmount; // 총 금액을 반환하는 속성
        public string ScreeningInfo => screeningInfo; // 선택된 상영시간 및 상영관 정보 속성
        public List<string> SelectedSeatDetails => selectedSeatDetails;

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

        private void panel1_Click(object sender, EventArgs e) // 패널 클릭 이벤트 (현재 비어 있음)
        {
            // 여기에 좌석 선택 후 처리 로직 추가 가능
        }

        private void btn_reservation1_Click(object sender, EventArgs e) // 예매 버튼 클릭 이벤트
        {
            if (selectedSeats.Count == 0) // 선택된 좌석이 없는 경우
            {
                MessageBox.Show("선택된 좌석이 없습니다.", "안내", MessageBoxButtons.OK, MessageBoxIcon.Information); // 경고 메시지 표시
                return; // 메서드 종료
            }
            selectedSeatDetails.Clear();  //기존 데이터 초기화
            foreach (var seat in selectedSeats)
            {
                if (seatInfo.ContainsKey(seat))
                {
                    selectedSeatDetails.Add(seatInfo[seat]); // 각 좌석 정보를 개별적으로 추가
                }
            }

            //string seatInfoString = string.Join(", ", selectedSeats.Select(seat => seatInfo[seat])); // 선택된 좌석 정보를 쉼표로 결합
            //selectedSeatDetails.Add(seatInfoString);
            MessageBox.Show($"선택된 좌석: {string.Join(", ", selectedSeatDetails)}");
            DialogResult result = MessageBox.Show($"{string.Join(", ", selectedSeatDetails)} 좌석을 예매하시겠습니까?", "예매확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question); // 예매 확인 메시지

            if (result == DialogResult.Yes) // "예" 선택 시
            {
                Form4 form4 = new Form4(this.SelectedImage, this.SelectedTitle, this.SelectedPayment, this.SelectedAdultCount, this.SelectedTeenagerCount, this.SelectedChildCount, this.TotalPeople, this.TotalAmount, this.ScreeningInfo, this.selectedSeatDetails); // Form4 인스턴스 생성, 전달받은 데이터 사용
                form4.Location = this.Location; // Form4의 위치를 Form3와 동일하게 설정
                form4.Show(); // Form4 표시
                this.Hide(); // 현재 폼 숨김
            }
            // "아니오" 선택 시 메시지 박스가 자동으로 닫힘
        }

        private void btn_cancel_Click(object sender, EventArgs e) // 취소 버튼 클릭 이벤트
        {
            DialogResult result = MessageBox.Show("취소하시겠습니까?", "취소 확인", MessageBoxButtons.YesNo, MessageBoxIcon.Question); // 취소 확인 메시지
            if (result == DialogResult.Yes) // "예" 선택 시
            {
                Form1 form1 = new Form1(); // Form1 인스턴스 생성
                form1.Location = this.Location; // Form1의 위치를 Form3와 동일하게 설정
                form1.Show(); // Form1 표시
                this.Close(); // 현재 폼 닫기
            }
        }
    }
}