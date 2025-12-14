// Team3_Kitchen.cpp

#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 스포츠용품 카테고리 상품을 추가하는 함수
void loadsportsProducts(Kiosk& kiosk) {

    //요가매트
    Product yogaMat("요가 매트", 25000, "스포츠용품");
    yogaMat.attributes["재질"] = "TPE";
    yogaMat.attributes["두께"] = "6mm";
    yogaMat.attributes["특징"] = "미끄럼 방지";
    kiosk.addProduct(yogaMat);

    // 폼롤러
    Product foamRoller("폼롤러", 18000, "스포츠용품");
    foamRoller.attributes["재질"] = "EVA 폼";
    foamRoller.attributes["크기"] = "33cm";
    foamRoller.attributes["용도"] = "근육 이완";
    kiosk.addProduct(foamRoller);

    // 푸쉬업 바
    Product pushupBar("푸쉬업 바", 21000, "스포츠용품");
    pushupBar.attributes["재질"] = "스틸, EVA";
    pushupBar.attributes["용도"] = "가슴, 삼두 근육";
    pushupBar.attributes["특징"] = "안정적인 그립";
    kiosk.addProduct(pushupBar);

    // 아령
    Product dumbbell("아령", 45000, "스포츠용품");
    dumbbell.attributes["재질"] = "고무 코팅";
    dumbbell.attributes["무게"] = "5kg";
    dumbbell.attributes["색상"] = "블랙";
    kiosk.addProduct(dumbbell);

    // 축구공
    Product soccerBall("축구공", 25000, "스포츠용품");
    soccerBall.attributes["재질"] = "PU";
    soccerBall.attributes["사이즈"] = "5호";
    soccerBall.attributes["특징"] = "공인구";
    kiosk.addProduct(soccerBall);

    // 농구공
    Product basketball("농구공", 30000, "스포츠용품");
    basketball.attributes["재질"] = "고무";
    basketball.attributes["사이즈"] = "7호";
    basketball.attributes["특징"] = "실외용";
    kiosk.addProduct(basketball);

    // 스포츠 가방
    Product sportsBag("스포츠 가방", 55000, "스포츠용품");
    sportsBag.attributes["재질"] = "방수 나일론";
    sportsBag.attributes["수납"] = "신발 수납 공간";
    sportsBag.attributes["색상"] = "블랙";
    kiosk.addProduct(sportsBag);
}