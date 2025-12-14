// Team3_Health.cpp

#include "Kiosk.h"

// 건강식품 카테고리 상품을 추가하는 함수
void loadHealthProducts(Kiosk& kiosk) {

    // 종합 비타민
    Product vitamin("종합 비타민", 35000, "건강식품");
    vitamin.attributes["제조사"] = "헬시라이프";
    vitamin.attributes["용량"] = "120정";
    vitamin.attributes["주요 성분"] = "비타민 B, C, D";
    kiosk.addProduct(vitamin);

    // 오메가3
    Product omega3("오메가3", 45000, "건강식품");
    omega3.attributes["제조사"] = "네이처스";
    omega3.attributes["용량"] = "90캡슐";
    omega3.attributes["주요 성분"] = "EPA 및 DHA 함유 유지";
    kiosk.addProduct(omega3);

    // 유산균
    Product probiotics("유산균", 30000, "건강식품");
    probiotics.attributes["제조사"] = "바이오팜";
    probiotics.attributes["용량"] = "60포";
    probiotics.attributes["주요 성분"] = "17종 혼합 유산균";
    kiosk.addProduct(probiotics);

    // 프로폴리스
    Product propolis("프로폴리스", 28000, "건강식품");
    propolis.attributes["제조사"] = "비앤비";
    propolis.attributes["용량"] = "30ml";
    propolis.attributes["주요 성분"] = "프로폴리스 추출물";
    kiosk.addProduct(propolis);

    // 루테인
    Product lutein("루테인", 40000, "건강식품");
    lutein.attributes["제조사"] = "아이케어";
    lutein.attributes["용량"] = "60캡슐";
    lutein.attributes["주요 성분"] = "마리골드꽃 추출물";
    kiosk.addProduct(lutein);
}