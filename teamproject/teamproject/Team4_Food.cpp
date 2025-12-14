#include "Kiosk.h"

void loadFoodProducts(Kiosk& kiosk)
{
    //소고기
    Product steak("한우 구이용 모듬 소고기 600g", 69000, "식품");
    steak.attributes["원산지"] = "국내산";
    steak.attributes["고기 용도"] = "구이용";
    steak.attributes["중량"] = "600g";
    kiosk.addProduct(steak);
    //돼지고기
    Product fork("한돈 삼겹살 구이용 1kg", 24900, "식품");
    fork.attributes["원산지"] = "국내산";
    fork.attributes["고기 용도"] = "구이용";
    fork.attributes["중량"] = "1kg";
    kiosk.addProduct(fork);
    //계란
    Product egg("신선한 특란 30구", 9900, "식품");
    egg.attributes["계란 중량규격"] = "특란";
    egg.attributes["계란 구수"] = "30구";
    egg.attributes["특징"] = "무항생제";
    egg.attributes["생산연도"] = "2025년";
    kiosk.addProduct(egg);
    //채소
    Product vegitable("농산물 꾸러미", 19000, "식품");
    vegitable.attributes["개당 중량"] = "2kg";
    vegitable.attributes["구성"] = "감자, 당근, 브로콜리, 새송이버섯, 표고버섯, 양배추, 무, 오이 ,가지 ,피망 파프리카";
    vegitable.attributes["보관"] = "냉장보관";
    vegitable.attributes["비건 여부"] = "비건";
    kiosk.addProduct(vegitable);
    //밀키트
    Product milkit("오리지널 부대찌개 1kg 2개", 14000, "식품");
    milkit.attributes["소비기한"] = "제조일자부터 1년";
    milkit.attributes["섭취 방법"] = "즉석반조리식품";
    milkit.attributes["보관"] = "냉동보관";
    milkit.attributes["총 수량"] = "2개";
    kiosk.addProduct(milkit);
}