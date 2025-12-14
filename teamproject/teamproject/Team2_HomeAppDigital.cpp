#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 가전디지털 카테고리 상품을 추가하는 함수
void loadHomeAppDigital(Kiosk& kiosk) {

    // TV 상품 데이터
    Product tv("스마트 TV", 1200000, "가전디지털");
    tv.attributes["화면 크기"] = "55인치";
    tv.attributes["해상도"] = "4K UHD";
    tv.attributes["기능"] = "넷플릭스, 유튜브 지원";
    kiosk.addProduct(tv);

    // 노트북 상품 데이터
    Product laptop("노트북", 1500000, "가전디지털");
    laptop.attributes["프로세서"] = "Intel Core i7";
    laptop.attributes["RAM"] = "16GB";
    laptop.attributes["저장장치"] = "512GB SSD";
    laptop.attributes["운영체제"] = "Windows 11 Home";
    kiosk.addProduct(laptop);

    // 스마트폰 상품 데이터
    Product smartphone("스마트폰", 1000000, "가전디지털");
    smartphone.attributes["모델"] = "Galaxy S23";
    smartphone.attributes["카메라"] = "50MP 메인 카메라";
    smartphone.attributes["저장용량"] = "256GB";
    kiosk.addProduct(smartphone);

    // 무선 이어폰 상품 데이터
    Product earbuds("무선 이어폰", 250000, "가전디지털");
    earbuds.attributes["연결 방식"] = "블루투스 5.3";
    earbuds.attributes["배터리"] = "최대 30시간";
    earbuds.attributes["특징"] = "노이즈 캔슬링";
    kiosk.addProduct(earbuds);

    // 로봇청소기 상품 데이터
    Product robotVacuum("로봇청소기", 450000, "가전디지털");
    robotVacuum.attributes["기능"] = "흡입 및 물걸레";
    robotVacuum.attributes["배터리"] = "2시간 연속 사용";
    robotVacuum.attributes["특징"] = "스마트 앱 연동";
    kiosk.addProduct(robotVacuum);
}
