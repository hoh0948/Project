#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 생활용품 카테고리 상품을 추가하는 함수
void loadStationeryProducts(Kiosk& kiosk) {

    // 볼펜 상품 데이터
    Product pen("볼펜", 1000, "문구/오피스");
    pen.attributes["잉크색상"] = "검은색";
    pen.attributes["펜촉굵기"] = "0.5mm";
    pen.attributes["재질"] = "플라스틱";
    kiosk.addProduct(pen);

    // 연필 상품 데이터
    Product pencil("연필", 700, "문구/오피스");
    pencil.attributes["심굵기"] = "HB";
    pencil.attributes["재질"] = "나무";
    pencil.attributes["길이"] = "17cm";
    kiosk.addProduct(pencil);

    // 지우개 상품 데이터
    Product eraser("지우개", 500, "문구/오피스");
    eraser.attributes["재질"] = "고무";
    eraser.attributes["용도"] = "미술용";
    eraser.attributes["특징"] = "가루 적음";
    kiosk.addProduct(eraser);

    // 샤프 상품 데이터
    Product sharp("샤프", 2000, "문구/오피스");
    sharp.attributes["심굵기"] = "0.5mm";
    sharp.attributes["재질"] = "플라스틱";
    sharp.attributes["특징"] = "샤프심이 덜 부러짐";
    kiosk.addProduct(sharp);

    // 색연필 상품 데이터
    Product coloredPencil("색연필", 5000, "문구/오피스");
    coloredPencil.attributes["색상"] = "12색";
    coloredPencil.attributes["특징"] = "손에 묻지 않음";
    coloredPencil.attributes["안전성"] = "무독성";
    kiosk.addProduct(coloredPencil);
}
