// Team3_Kitchen.cpp

#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 주방용품 카테고리 상품을 추가하는 함수
void loadKitchenProducts(Kiosk& kiosk) {

    // 프라이팬 상품 데이터
    Product fryingPan("프라이팬", 35000, "주방용품");
    fryingPan.attributes["재질"] = "스테인리스 스틸";
    fryingPan.attributes["코팅"] = "테프론 코팅";
    fryingPan.attributes["크기"] = "28cm";
    kiosk.addProduct(fryingPan);

    // 냄비 상품 데이터
    Product pot("냄비", 48000, "주방용품");
    pot.attributes["재질"] = "알루미늄";
    pot.attributes["용량"] = "5L";
    pot.attributes["손잡이"] = "베이크라이트";
    kiosk.addProduct(pot);

    // 칼세트 상품 데이터
    Product knifeSet("칼세트", 75000, "주방용품");
    knifeSet.attributes["구성"] = "식도, 과도, 가위";
    knifeSet.attributes["재질"] = "고탄소강";
    knifeSet.attributes["특징"] = "인체공학적 디자인";
    kiosk.addProduct(knifeSet);
}