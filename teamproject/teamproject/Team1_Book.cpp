#include "Kiosk.h" // Kiosk 클래스 정의를 포함

// 생활용품 카테고리 상품을 추가하는 함수
void loadBook(Kiosk& kiosk) {
	// 해리포터
	Product harryPotter("해리포터와 마법사의 돌", 18000, "도서");
	harryPotter.attributes["저자"] = "J.K. 롤링";
	harryPotter.attributes["장르"] = "판타지";
	harryPotter.attributes["특징"] = "마법과 모험의 세계";
	kiosk.addProduct(harryPotter);

	// 반지의 제왕
	Product lordOfTheRings("반지의 제왕", 25000, "도서");
	lordOfTheRings.attributes["저자"] = "J.R.R. 톨킨";
	lordOfTheRings.attributes["장르"] = "판타지";
	lordOfTheRings.attributes["특징"] = "서사적 모험, 중간계 세계관, 고전 명작";
	kiosk.addProduct(lordOfTheRings);

	// 어린 왕자
	Product littlePrince("어린 왕자", 12000, "도서");
	littlePrince.attributes["저자"] = "앙투안 드 생텍쥐페리";
	littlePrince.attributes["장르"] = "동화/철학";
	littlePrince.attributes["특징"] = "순수함, 철학적 교훈, 전 세계 사랑받는 작품";
	kiosk.addProduct(littlePrince);

	// 노인과 바다
	Product oldManAndSea("노인과 바다", 15000, "도서");
	oldManAndSea.attributes["저자"] = "어니스트 헤밍웨이";
	oldManAndSea.attributes["장르"] = "소설/고전";
	oldManAndSea.attributes["특징"] = "인간과 자연, 도전과 인내, 문학적 가치";
	kiosk.addProduct(oldManAndSea);

	// 죄와 벌
	Product crimeAndPunishment("죄와 벌", 20000, "도서");
	crimeAndPunishment.attributes["저자"] = "표도르 도스토옙스키";
	crimeAndPunishment.attributes["장르"] = "소설/고전";
	crimeAndPunishment.attributes["특징"] = "심리 탐구, 도덕적 갈등, 인간 본성 연구";
	kiosk.addProduct(crimeAndPunishment);
}