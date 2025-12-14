using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.Xml;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.DataFormats;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace kiosk
{
    public partial class Form2 : Form
    {
        private String[] listview_Column = { "제목", "장르", "개봉일", "이용가" }; // 리스트뷰의 열 제목 배열
        private String[] listview1_Column = { "상영 시간", "상영관" }; // 두 번째 리스트뷰의 열 제목 배열
        public string SelectedPaymentMethod => domainUpDown1.Text; // 선택된 결제 방법을 반환하는 속성
        public int SelectedPeopleCount => (int)numericUpDown1.Value; // 선택된 인원 수를 반환하는 속성


        public Form2()
        {
            InitializeComponent(); // 디자이너에서 생성된 초기화 로직 호출
            StartClock(); // 시계 업데이트 시작
            listView1.View = View.Details; // 리스트뷰 스타일 설정 (세부 정보 표시)
            listView2.View = View.Details; // 두 번째 리스트뷰 스타일 설정
            numericUpDownList.Add(numericUpDown1); // 인원 수 입력 컨트롤 추가
            numericUpDownList.Add(numericUpDown2); // 추가 인원 수 입력 컨트롤 추가
            numericUpDownList.Add(numericUpDown3); // 추가 인원 수 입력 컨트롤 추가
        }

        List<NumericUpDown> numericUpDownList = new List<NumericUpDown>(); // 인원 수 입력 컨트롤을 저장하는 리스트

        static int[] price = new int[] { 15000, 11000, 9000 }; // 각 인원 유형별 가격 배열

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

        private void Form2_Load(object sender, EventArgs e) // 폼 로드 이벤트
        {
            start_ListView(); // 리스트뷰 초기화
            add_items(); // 리스트뷰에 아이템 추가
        }

        private void start_ListView() // 리스트뷰 열 설정 메서드
        {
            int listview_width = listView1.ClientSize.Width; // 첫 번째 리스트뷰의 너비
            int listview1_width = listView2.ClientSize.Width; // 두 번째 리스트뷰의 너비
            int col_width = listview_width / 4; // 열 너비 (4등분)
            int col1_width = listview1_width / 2; // 두 번째 리스트뷰 열 너비 (2등분)

            listView1.Columns.Add(listview_Column[0], col_width, HorizontalAlignment.Center); // "제목" 열 추가
            listView1.Columns.Add(listview_Column[1], col_width, HorizontalAlignment.Center); // "장르" 열 추가
            listView1.Columns.Add(listview_Column[2], col_width, HorizontalAlignment.Center); // "개봉일" 열 추가
            listView1.Columns.Add(listview_Column[3], col_width, HorizontalAlignment.Center); // "이용가" 열 추가

            listView2.Columns.Add(listview1_Column[0], col1_width, HorizontalAlignment.Center); // "상영 시간" 열 추가
            listView2.Columns.Add(listview1_Column[1], col1_width, HorizontalAlignment.Center); // "상영관" 열 추가 (오타로 보임, "상영관"으로 수정 권장)
        }

        private void add_items() // 리스트뷰에 아이템 추가 메서드
        {
            ListViewItem newitem1 = new ListViewItem(new string[] { "좀비딸", "코미디", "07.30", "12세 이상" });
            listView1.Items.Add(newitem1); // "좀비딸" 아이템 추가
            ListViewItem newitem2 = new ListViewItem(new string[] { "전지적 독자 시점", "판타지", "07.23", "15세 이상" });
            listView1.Items.Add(newitem2); // "전지적 독자 시점" 아이템 추가
            ListViewItem newitem3 = new ListViewItem(new string[] { "F1 더 무비", "드라마", "06.25", "12세 이상" });
            listView1.Items.Add(newitem3); // "F1 더 무비" 아이템 추가
            ListViewItem newitem4 = new ListViewItem(new string[] { "판타스틱4: 새로운 출발", "액션", "07.24", "12세 이상" });
            listView1.Items.Add(newitem4); // "판타스틱4: 새로운 출발" 아이템 추가
            ListViewItem newitem5 = new ListViewItem(new string[] { "노이즈", "공포", "06.25", "15세 이상" });
            listView1.Items.Add(newitem5); // "노이즈" 아이템 추가

            ListViewItem newitem6 = new ListViewItem(new string[] { "8:30", "1관" });
            listView2.Items.Add(newitem6); // "8:30, 1관" 아이템 추가
            ListViewItem newitem7 = new ListViewItem(new string[] { "10:50", "2관" });
            listView2.Items.Add(newitem7); // "10:50, 2관" 아이템 추가
            ListViewItem newitem8 = new ListViewItem(new string[] { "15:30", "3관" });
            listView2.Items.Add(newitem8); // "15:30, 3관" 아이템 추가
            ListViewItem newitem9 = new ListViewItem(new string[] { "16:10", "4관" });
            listView2.Items.Add(newitem9); // "16:10, 4관" 아이템 추가
            ListViewItem newitem10 = new ListViewItem(new string[] { "18:25", "5관" });
            listView2.Items.Add(newitem10); // "18:25, 5관" 아이템 추가
            ListViewItem newitem11 = new ListViewItem(new string[] { "22:30", "6관" });
            listView2.Items.Add(newitem11); // "22:30, 6관" 아이템 추가
        }

        public Image SelectedMovieImage // 선택된 영화 이미지를 반환하는 속성
        {
            get { return pictureBox1.Image; }
        }

        private void listView1_Click(object sender, EventArgs e) // 리스트뷰 클릭 이벤트 (현재 비어 있음)
        {
            // 여기에 클릭 시 처리 로직 추가 가능
        }

        private void button1_Click(object sender, EventArgs e) // 버튼1 클릭 이벤트 (현재 비어 있음)
        {
            // 여기에 버튼1 처리 로직 추가 가능
        }

        private void btn_select_Click(object sender, EventArgs e) // 선택 버튼 클릭 이벤트
        {
            int sum = 0; // 총 금액 초기화
            int totalPeople = 0; // 총 인원 수 초기화

            for (int i = 0; i < numericUpDownList.Count; i++) // 각 NumericUpDown 컨트롤에 대해 반복
            {
                int count = (int)numericUpDownList[i].Value; // 현재 인원 수 가져오기
                sum += count * price[i]; // 금액 계산
                totalPeople += count; // 인원 수 누적
            }
            lb_result.Text = $"{totalPeople}명\n{sum}원"; // 결과 라벨에 표시
        }

        private void btn_seat_Click(object sender, EventArgs e) // 좌석 선택 버튼 클릭 이벤트
        {
            Image selectedImage = SelectedMovieImage; // 선택된 영화 이미지 가져오기
            string selectedTitle = domainUpDown1.Text; // 선택된 영화 제목 가져오기
            string payment = SelectedPaymentMethod; // 선택된 결제 방법 가져오기
            int adultCount = (int)numericUpDown1.Value; // 성인 인원 수
            int teenagerCount = (int)numericUpDown2.Value; // 청소년 인원 수
            int childCount = (int)numericUpDown3.Value; // 아동 인원 수

            // btn_select_Click와 동일한 계산 로직
            int totalPeople = adultCount + teenagerCount + childCount; // 총 인원 수
            int totalAmount = (adultCount * price[0]) + (teenagerCount * price[1]) + (childCount * price[2]); // 총 금액 계산
            string screeningInfo = label12.Text; // label12의 상영 시간 및 상영관 정보 가져오기

            Form3 form3 = new Form3(selectedImage, selectedTitle, payment, adultCount, teenagerCount, childCount, totalPeople, totalAmount, screeningInfo);
            form3.Location = this.Location; // Form3의 위치를 Form2와 동일하게 설정
            form3.Show(); // Form3 표시
            this.Hide(); // Form2 숨김
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e) // 리스트뷰 선택 항목 변경 이벤트
        {
            if (listView1.SelectedItems.Count > 0) // 선택된 항목이 있을 경우
            {
                string selectedMovie = listView1.SelectedItems[0].Text; // 첫 번째 선택 항목의 제목 가져오기
                domainUpDown1.Text = selectedMovie; // 드롭다운에 선택된 영화 제목 설정
                switch (selectedMovie) // 영화 제목에 따라 이미지 설정
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
        }

        private void btn_back1_Click(object sender, EventArgs e) // 뒤로가기 버튼 클릭 이벤트
        {
            Form1 form1 = new Form1(); // Form1 인스턴스 생성
            form1.Show(); // Form1 표시
            this.Close(); // Form2 닫기
        }

        private void btn_reservation1_Click(object sender, EventArgs e) // 예매 버튼 클릭 이벤트 (현재 비어 있음)
        {
            // 여기에 예매 처리 로직 추가 가능
        }

        private void btn_check_Click(object sender, EventArgs e) // 조회 버튼 클릭 이벤트
        {
        }

        private void listView1_DoubleClick(object sender, EventArgs e) // 리스트뷰 더블클릭 이벤트 (현재 비어 있음)
        {
            // 여기에 더블클릭 처리 로직 추가 가능
        }

        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listView2.SelectedItems.Count > 0) // 선택된 항목이 있을 경우
            {
                string screeningTime = listView2.SelectedItems[0].Text; // 상영 시간
                string theater = listView2.SelectedItems[0].SubItems[1].Text; // 상영관
                label12.Text = $"{screeningTime} - {theater}"; // label12에 표시
            }
            else
            {
                label12.Text = "상영 정보 없음"; // 선택되지 않은 경우 기본값
            }
        }
    }
    
}