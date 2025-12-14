#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 생활용품 카테고리 상품을 추가하는 함수
void loadDailysupplies(Kiosk& kiosk) {

    // 세탁세제 상품 데이터
    Product laundryDetergent("세탁세제", 8000, "생활용품");
    laundryDetergent.attributes["용량"] = "3L";
    laundryDetergent.attributes["형태"] = "액체";
    laundryDetergent.attributes["향"] = "프레시 코튼";
    kiosk.addProduct(laundryDetergent);

    // 화장지 상품 데이터
    Product toiletPaper("화장지", 15000, "생활용품");
    toiletPaper.attributes["매수"] = "30롤";
    toiletPaper.attributes["재질"] = "천연펄프";
    toiletPaper.attributes["특징"] = "3겹";
    kiosk.addProduct(toiletPaper);

    // 샴푸 상품 데이터
    Product shampoo("샴푸", 12000, "생활용품");
    shampoo.attributes["용량"] = "500ml";
    shampoo.attributes["특징"] = "탈모케어";
    shampoo.attributes["향"] = "허브향";
    kiosk.addProduct(shampoo);

    // 칫솔 상품데이터
    Product toothbrush("칫솔", 3500, "생활용품");
    toothbrush.attributes["구성"] = "4개입";
    toothbrush.attributes["특징"] = "미세모";
    toothbrush.attributes["손잡이"] = "미끄럼 방지";
    kiosk.addProduct(toothbrush);

    //치약 상품데이터
    Product toothpaste("치약", 4500, "생활용품");
    toothpaste.attributes["용량"] = "150g";
    toothpaste.attributes["효능"] = "잇몸질환 예방";
    toothpaste.attributes["향"] = "민트";
    kiosk.addProduct(toothpaste);
}
