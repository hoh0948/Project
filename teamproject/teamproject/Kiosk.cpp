#include "Kiosk.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <windows.h> // Windows.h 헤더: 콘솔 색상 설정 함수를 위해 필요
#include <thread>    // thread 헤더: 일정 시간 대기하는 함수를 위해 필요
#include <chrono>    // chrono 헤더: 시간 관련 함수를 위해 필요
#include <limits>
#undef max 
// Kiosk 클래스 메서드 구현

void Kiosk::addProduct(const Product& product) {

	allProducts[product.category].push_back(product);

}


void Kiosk::printHeader() const {
	system("cls");
	std::cout << "=====================================\n";
	std::cout << "            M O P A N G          \n";
	std::cout << "=====================================\n\n";
}


void Kiosk::run() {
	int choice;
	while (true) {
		printHeader();

		std::cout << "     [메인 메뉴]\n";
		std::cout << "     ----------------------\n";
		std::cout << "     1.  상품 검색\n";
		std::cout << "     2.  카테고리별 상품 보기\n";
		std::cout << "     3.  장바구니 확인\n";
		std::cout << "     4.  결제하기\n";
		std::cout << "     5.  주문내역 확인\n";
		std::cout << "     ----------------------\n";
		std::cout << "     0.  프로그램 종료\n";
		std::cout << "     ----------------------\n";
		std::cout << "     메뉴 선택: ";

		// --- 예외 처리 로직 시작 ---
		std::cin >> choice;

		if (std::cin.fail()) { // 입력이 실패하면
			std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
			std::cin.clear(); // 1. 오류 상태 해제
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 2. 입력 버퍼 비우기
		
			std::cin.get();
			// 3. 다시 입력받도록 루프를 계속
			continue;
		}
		// --- 예외 처리 로직 끝 ---
		switch (choice) {
		case 1: searchProduct(); break;
		case 2: showCategories(); break;
		case 3: viewCart(); break;
		case 4: checkout(); break;
		case 5: viewOrders(); break;
		case 0: std::cout << "\n프로그램을 종료합니다. 감사합니다!\n"; return;
		default:
			std::cout << "\n잘못 입력했습니다. 다시 시도해 주세요.\n";
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.ignore();
			std::cin.get();
			break;
		}
	}
}


void Kiosk::showCategories() {
	int choice;
	while (true) {
		printHeader(); // 여기에서 한 번만 호출하여 화면을 깨끗하게 합니다.

		std::cout << "     [카테고리 목록]\n";
		std::cout << "     ----------------------\n";

		int i = 1;
		std::vector<std::string> categoryNames;
		for (const auto& pair : allProducts) {
			std::cout << "     " << i++ << ". " << pair.first << std::endl;
			categoryNames.push_back(pair.first);
		}
		std::cout << "     ----------------------\n";
		std::cout << "     0. 뒤로가기\n";
		std::cout << "     ----------------------\n";
		std::cout << "     메뉴 선택: ";

		std::cin >> choice;

		if (std::cin.fail()) {
			std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.get();
			continue;
		}

		if (choice == 0) {
			break;
		}

		if (choice > 0 && choice < i) {
			showProductsInCategory(categoryNames[choice - 1]);
		}
		else {
			std::cout << "\n잘못된 메뉴 번호입니다. 다시 입력해주세요.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.get();
		}
	}
}


void Kiosk::showProductsInCategory(const std::string& categoryName) {
	int choice;

	auto it = allProducts.find(categoryName);

	if (it == allProducts.end() || it->second.empty()) {
		printHeader();
		std::cout << "\n[" << categoryName << "] 카테고리에 상품이 없습니다.\n";
		// 잘못된 입력 후 대기하는 로직을 추가
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\n아무 키나 눌러 뒤로가기...\n";
		std::cin.get();
		return;
	}

	const std::vector<Product>& productList = it->second;

	while (true) {
		printHeader();
		std::cout << "\n     [" << categoryName << " 카테고리]\n";
		std::cout << "     ----------------------\n";

		for (size_t i = 0; i < productList.size(); ++i) {
			std::cout << "     " << i + 1 << ". " << productList[i].name
				<< " - " << std::fixed << std::setprecision(0) << productList[i].price << "원\n";
		}

		std::cout << "     ----------------------\n";
		std::cout << "     0. 뒤로가기\n";
		std::cout << "     ----------------------\n";
		std::cout << "     메뉴 선택: ";

		std::cin >> choice;

		if (std::cin.fail()) {
			std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.get();
			continue;
		}

		if (choice == 0) {
			break;
		}

		if (choice > 0 && choice <= productList.size()) {
			const Product& selectedProduct = productList[choice - 1];

			printHeader(); // 상품 상세 정보 보기 전에 화면 지우기
			std::cout << "\n     --- 상품 상세 정보 ---\n";
			std::cout << "     상품명: " << selectedProduct.name << std::endl;
			std::cout << "     가격: " << std::fixed << std::setprecision(0) << selectedProduct.price << "원" << std::endl;
			for (const auto& attr : selectedProduct.attributes) {
				std::cout << "     " << attr.first << ": " << attr.second << std::endl;
			}
			std::cout << "     ----------------------\n";

			while (true) { // 1 또는 0을 입력할 때까지 반복
				std::cout << "\n     1. 장바구니에 추가하기\n";
				std::cout << "     0. 뒤로가기\n";
				std::cout << "     ----------------------\n";
				std::cout << "     메뉴 선택: ";
				int cartChoice;
				std::cin >> cartChoice;

				if (std::cin.fail()) {
					std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "아무 키나 눌러 계속...\n";
					std::cin.get();
					continue; // 다시 입력 받기
				}

				if (cartChoice == 1) {
					int quantity = 0;
					while (true) { // 1개 이상 수량을 입력할 때까지 반복
						std::cout << "     수량을 입력하세요: ";
						std::cin >> quantity;

						if (std::cin.fail()) {
							std::cout << "\n잘못된 수량입니다. 숫자를 입력해주세요.\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "아무 키나 눌러 계속...\n";
							std::cin.get();
							continue;
						}

						if (quantity > 0) {
							cart.addItem(selectedProduct, quantity);
							std::cout << "\n     " << selectedProduct.name << " " << quantity << "개를 장바구니에 추가했습니다.\n";
							// 잠시 대기 후 메인 메뉴로
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "     아무 키나 눌러 뒤로가기...\n";
							std::cin.get();
							break; // 수량 입력 루프 탈출
						}
						else {
							std::cout << "\n잘못된 수량입니다. 1개 이상 입력해주세요.\n";
							std::cout << "아무 키나 눌러 계속...\n";
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cin.get();
							continue;
						}
					}
					break; // 장바구니/뒤로가기 루프 탈출
				}
				else if (cartChoice == 0) {
					break; // 상품 목록으로 돌아가기 위해 내부 루프 탈출
				}
				else {
					std::cout << "\n잘못된 메뉴 번호입니다. 다시 선택해주세요.\n";
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "아무 키나 눌러 계속...\n";
					std::cin.get();
				}
			}
		}
		else {
			// 잘못된 물품 번호 입력 시
			std::cout << "\n잘못된 물품 번호입니다. 다시 입력해주세요.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.get();
		}
	}
}


void Kiosk::searchProduct() {
	int choice;
	std::string searchInput;

	while (true) {
		printHeader();
		std::cout << "\n     [검색 기능]\n";
		std::cout << "     ----------------------\n";
		std::cout << "     1. 카테고리 검색\n";
		std::cout << "     2. 물품 검색\n";
		std::cout << "     ----------------------\n";
		std::cout << "     0. 뒤로가기\n";
		std::cout << "     ----------------------\n";
		std::cout << "     메뉴 선택: ";

		std::cin >> choice;
		// --- 입력 유효성 검사 ---
		if (std::cin.fail()) {
			std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "아무 키나 눌러 계속...\n";
			std::cin.get();
			continue;
		}
		std::cin.ignore();

		if (choice == 0) {
			break;
		}

		if (choice == 1) {
			// 카테고리 검색 로직 (이전 답변에서 수정된 코드)
			std::cout << "\n     검색할 카테고리명을 입력하세요: ";
			std::getline(std::cin, searchInput);

			std::vector<std::string> foundCategories;
			for (const auto& pair : allProducts) {
				if (pair.first.find(searchInput) != std::string::npos) {
					foundCategories.push_back(pair.first);
				}
			}

			if (!foundCategories.empty()) {
				printHeader();
				std::cout << "\n     --- 검색 결과 ---" << std::endl;
				for (size_t i = 0; i < foundCategories.size(); ++i) {
					std::cout << "     " << i + 1 << ". " << foundCategories[i] << std::endl;
				}
				std::cout << "     ----------------------" << std::endl;
				std::cout << "     0. 뒤로가기" << std::endl;
				std::cout << "     ----------------------" << std::endl;

				int categoryChoice;
				std::cout << "     카테고리를 선택하세요: ";
				std::cin >> categoryChoice;

				if (std::cin.fail()) {
					std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n아무 키나 눌러 계속...\n";
					std::cin.get();
					continue;
				}
				std::cin.ignore();

				if (categoryChoice > 0 && categoryChoice <= foundCategories.size()) {
					showProductsInCategory(foundCategories[categoryChoice - 1]);
				}
				else if (categoryChoice != 0) {
					std::cout << "\n잘못된 선택입니다. 뒤로 돌아갑니다.\n";
					std::cout << "\n아무 키나 눌러 계속...\n";
					std::cin.get();
				}
			}
			else {
				std::cout << "\n     해당 카테고리를 찾을 수 없습니다.\n";
				std::cout << "     아무 키나 눌러 계속...\n";
				std::cin.get();
			}
		}
		else if (choice == 2) {
			std::cout << "\n     검색할 물품명을 입력하세요: ";
			std::getline(std::cin, searchInput);

			// --- 물품 검색 결과를 담을 벡터 ---
			std::vector<const Product*> foundProducts;
			for (const auto& categoryPair : allProducts) {
				for (const auto& product : categoryPair.second) {
					// 물품명에 입력한 문자열이 포함되어 있는지 확인
					if (product.name.find(searchInput) != std::string::npos) {
						foundProducts.push_back(&product);
					}
				}
			}

			if (!foundProducts.empty()) {
				printHeader();
				std::cout << "\n     --- 검색 결과 ---" << std::endl;
				for (size_t i = 0; i < foundProducts.size(); ++i) {
					std::cout << "     " << i + 1 << ". " << foundProducts[i]->name << " ("
						<< std::fixed << std::setprecision(0) << foundProducts[i]->price << "원)" << std::endl;
				}
				std::cout << "     ----------------------" << std::endl;
				std::cout << "     0. 뒤로가기" << std::endl;
				std::cout << "     ----------------------" << std::endl;

				int productChoice;
				std::cout << "     물품을 선택하세요: ";
				std::cin >> productChoice;

				if (std::cin.fail()) {
					std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n아무 키나 눌러 계속...\n";
					std::cin.get();
					continue;
				}
				std::cin.ignore();

				if (productChoice > 0 && productChoice <= foundProducts.size()) {
					const Product& selectedProduct = *foundProducts[productChoice - 1];

					printHeader();
					std::cout << "\n     --- 상품 상세 정보 ---\n";
					std::cout << "     상품명: " << selectedProduct.name << std::endl;
					std::cout << "     가격: " << std::fixed << std::setprecision(0) << selectedProduct.price << "원" << std::endl;
					for (const auto& attr : selectedProduct.attributes) {
						std::cout << "     " << attr.first << ": " << attr.second << std::endl;
					}

					std::cout << "\n     1. 장바구니에 추가하기\n";
					std::cout << "     0. 뒤로가기\n";
					std::cout << "     ----------------------\n";
					std::cout << "     메뉴 선택: ";
					int cartChoice;
					std::cin >> cartChoice;

					if (std::cin.fail()) {
						std::cout << "\n잘못 입력했습니다. 숫자를 입력해주세요.\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "아무 키나 눌러 계속...\n";
						std::cin.get();
						continue;
					}
					std::cin.ignore();

					if (cartChoice == 1) {
						int quantity = 0;
						while (true) {
							std::cout << "     수량을 입력하세요: ";
							std::cin >> quantity;
							if (std::cin.fail() || quantity <= 0) {
								std::cout << "\n     잘못된 수량입니다. 1개 이상 숫자로 입력해주세요.\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "     아무 키나 눌러 계속...\n";
								std::cin.get();
								continue;
							}
							break;
						}
						cart.addItem(selectedProduct, quantity);
						std::cout << "\n     " << selectedProduct.name << " " << quantity << "개를 장바구니에 추가했습니다.\n";
						std::cout << "     아무 키나 눌러 계속...\n";
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();
					}
				}
				else if (productChoice != 0) {
					std::cout << "\n잘못된 선택입니다. 뒤로 돌아갑니다.\n";
					std::cout << "\n아무 키나 눌러 계속...\n";
					std::cin.get();
				}
			}
			else {
				std::cout << "\n     해당 물품을 찾을 수 없습니다.\n";
				std::cout << "     아무 키나 눌러 계속...\n";
				std::cin.get();
			}
		}
		else {
			std::cout << "\n     잘못된 선택입니다.\n";
			std::cout << "     아무 키나 눌러 계속...\n";
			std::cin.get();
		}
	}
}

void Kiosk::viewCart() {
	int choice;

	while (true) {
		printHeader();

		if (cart.getItems().empty()) {
			std::cout << "\n     [ 장바구니 확인 ]\n";
			std::cout << "     ----------------------\n";
			std::cout << "     장바구니가 비어 있습니다.\n";
			std::cout << "     ----------------------\n";
			std::cout << "\n     아무 키나 눌러 돌아가기...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}

		std::cout << "\n     [ 장바구니 확인 ]\n";
		std::cout << "     ----------------------\n";
		for (size_t i = 0; i < cart.getItems().size(); ++i) {
			const auto& item = cart.getItems()[i];
			std::cout << "     " << i + 1 << ". " << item.product.name << " ("
				<< std::fixed << std::setprecision(0) << item.product.price
				<< "원) x " << item.quantity << "개 = "
				<< std::fixed << std::setprecision(0) << item.product.price * item.quantity << "원\n";
		}
		std::cout << "     ----------------------\n";
		std::cout << "     총 금액: " << std::fixed << std::setprecision(0) << cart.calculateTotal() << "원\n";
		std::cout << "     ----------------------\n";

		std::cout << "\n     1. 수량/삭제 수정\n";
		std::cout << "     0. 뒤로가기\n";
		std::cout << "     ----------------------\n";
		std::cout << "     메뉴 선택: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cout << "\n     잘못된 입력입니다. 숫자를 입력해주세요.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n     계속하려면 아무 키나 누르세요...\n";
			std::cin.get();
			continue;
		}

		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			int itemChoice;
			int newQuantity;
			std::cout << "\n     수정할 물품 번호를 선택하세요: ";
			std::cin >> itemChoice;

			if (std::cin.fail()) {
				std::cout << "\n     잘못된 입력입니다. 숫자를 입력해주세요.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n     계속하려면 아무 키나 누르세요...\n";
				std::cin.get();
				continue;
			}

			if (itemChoice > 0 && itemChoice <= cart.getItems().size()) {
				const auto& selectedItem = cart.getItems()[itemChoice - 1];

				std::cout << "\n     선택한 물품: " << selectedItem.product.name << std::endl;
				std::cout << "     새로운 수량을 입력하세요 (0 입력 시 삭제): ";
				std::cin >> newQuantity;

				if (std::cin.fail()) {
					std::cout << "\n     잘못된 수량입니다. 숫자를 입력해주세요.\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n     계속하려면 아무 키나 누르세요...\n";
					std::cin.get();
					continue;
				}

				if (newQuantity < 0) {
					std::cout << "     잘못된 수량입니다. 1개 이상 입력해주세요.\n";
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "     \n계속하려면 아무 키나 누르세요...\n";
					std::cin.get();
				}
				else if (newQuantity == 0) {
					cart.removeItem(selectedItem.product.name);
					std::cout << "\n     " << selectedItem.product.name << "을(를) 장바구니에서 삭제했습니다.\n";
				}
				else {
					cart.updateItemQuantity(selectedItem.product.name, newQuantity);
					std::cout << "\n     " << selectedItem.product.name << "의 수량을 " << newQuantity << "개로 변경했습니다.\n";
				}
			}
			else {
				std::cout << "     잘못된 물품 번호입니다.\n";
			}
			std::cout << "\n     계속하려면 아무 키나 누르세요...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		else {
			std::cout << "\n     잘못된 입력입니다.\n";
			std::cout << "\n     계속하려면 아무 키나 누르세요...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
	}
}


// 결제 기능 구현
void Kiosk::checkout() {
	printHeader();

	if (cart.getItems().empty()) {
		std::cout << "\n     장바구니가 비어 있어 결제를 진행할 수 없습니다.\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\n     아무 키나 눌러 돌아가기...\n";
		std::cin.get();
		return;
	}

	std::cout << "\n     [결제 진행]\n";
	std::cout << "     ----------------------\n";
	for (const auto& item : cart.getItems()) {
		std::cout << "     - " << item.product.name << " x " << item.quantity << "개 = "
			<< std::fixed << std::setprecision(0) << item.product.price * item.quantity << "원\n";
	}
	std::cout << "     ----------------------\n";
	double total = cart.calculateTotal();
	std::cout << "     최종 결제 금액: " << std::fixed << std::setprecision(0) << total << "원\n";
	std::cout << "     ----------------------\n";

	std::string paymentMethod;
	int paymentChoice;
	std::cout << "\n     [결제 방법 선택]\n";
	std::cout << "     1. 카드 결제\n";
	std::cout << "     2. 간편결제\n";
	std::cout << "     ----------------------\n";
	std::cout << "     0. 결제 취소\n";
	std::cout << "     ----------------------\n";
	std::cout << "     메뉴 선택: ";
	std::cin >> paymentChoice;

	// --- 입력 유효성 검사 추가 ---
	if (std::cin.fail()) {
		std::cout << "\n     잘못 입력했습니다. 숫자를 입력해주세요.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\n     아무 키나 눌러 돌아가기...\n";
		std::cin.get();
		return;
	}
	// -------------------------

	if (paymentChoice == 0) {
		std::cout << "\n     결제가 취소되었습니다.\n";
	}
	else if (paymentChoice == 1) {
		paymentMethod = "카드";
		std::cout << "\n     결제가 완료되었습니다! 감사합니다.\n";
		std::cout << "     결제 방법: " << paymentMethod << std::endl;

		Order newOrder;
		newOrder.items = cart.getItems();
		newOrder.totalAmount = total;
		newOrder.paymentMethod = paymentMethod;
		newOrder.orderTime = std::chrono::system_clock::now();
		orderHistory.push_back(newOrder);
		cart.clearCart();
	}
	else if (paymentChoice == 2) {
		paymentMethod = "간편결제";
		std::cout << "\n     결제가 완료되었습니다! 감사합니다.\n";
		std::cout << "     결제 방법: " << paymentMethod << std::endl;

		Order newOrder;
		newOrder.items = cart.getItems();
		newOrder.totalAmount = total;
		newOrder.paymentMethod = paymentMethod;
		newOrder.orderTime = std::chrono::system_clock::now();
		orderHistory.push_back(newOrder);
		cart.clearCart();
	}
	else {
		std::cout << "\n     잘못된 선택입니다. 결제를 취소합니다.\n";
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n     아무 키나 눌러 돌아가기...\n";
	std::cin.get();
}

std::string Kiosk::getDeliveryStatus(const Order& order) {

	auto now = std::chrono::system_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - order.orderTime).count();



	if (elapsed < 10) {

		return "결제 완료: 상품 준비 중";

	}

	else if (elapsed < 20) {

		return "배송 시작";

	}

	else if (elapsed < 30) {

		return "배송 중";

	}

	else {

		return "배송 완료";

	}

}



// 주문내역 확인 기능 구현

// Kiosk::viewOrders() 함수 구현

void Kiosk::viewOrders() {
	printHeader();
	std::cout << "\n     [주문내역 확인]\n";
	std::cout << "     ----------------------\n";

	if (orderHistory.empty()) {
		std::cout << "     주문내역이 없습니다.\n";
		std::cout << "     ----------------------\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\n     아무 키나 눌러 돌아가기...\n";
		std::cin.get();
		return;
	}

	int orderCount = 1;
	for (const auto& order : orderHistory) {
		std::cout << "     --- 주문 번호 " << orderCount++ << " ---\n";
		std::cout << "     결제 방법: " << order.paymentMethod << std::endl;
		std::cout << "     배송 상태: " << getDeliveryStatus(order) << std::endl;
		for (const auto& item : order.items) {
			std::cout << "     - " << item.product.name << " x " << item.quantity << "개\n";
		}
		std::cout << "     총 결제 금액: " << std::fixed << std::setprecision(0) << order.totalAmount << "원\n";
		std::cout << "     ----------------------\n";
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n     아무 키나 눌러 돌아가기...\n";
	std::cin.get();
}

// ShoppingCart 클래스 메서드 구현

void ShoppingCart::addItem(const Product& product, int quantity) {

	for (auto& item : items) {

		if (item.product.name == product.name) {

			item.quantity += quantity;

			return;

		}

	}

	items.push_back({ product, quantity });

}



void ShoppingCart::updateItemQuantity(const std::string& productName, int newQuantity) {

	for (auto& item : items) {

		if (item.product.name == productName) {

			item.quantity = newQuantity;

			return;

		}

	}

}



void ShoppingCart::removeItem(const std::string& productName) {

	items.erase(std::remove_if(items.begin(), items.end(),

		[&](const CartItem& item) { return item.product.name == productName; }),

		items.end());

}



double ShoppingCart::calculateTotal() const {

	double total = 0.0;

	for (const auto& item : items) {

		total += item.product.price * item.quantity;

	}

	return total;

}