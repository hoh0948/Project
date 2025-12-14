#include "Kiosk.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <thread>   // std::this_thread::sleep_for 사용을 위해 포함
#include <chrono>   // std::chrono::seconds 사용을 위해 포함
void SetColor(int color, bool intense = true) {
    if (intense)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // 강조 제거 → 어두운 색
}

//===========================================================

void loadKitchenProducts(Kiosk& kiosk);
void loadDailysupplies(Kiosk& kiosk);
void loadsportsProducts(Kiosk& kiosk);
void loadHealthProducts(Kiosk& kiosk);
void loadHomeAppDigital(Kiosk& kiosk);
void loadStationeryProducts(Kiosk& kiosk);
void loadBook(Kiosk& kiosk);
void loadFoodProducts(Kiosk& kiosk);
int main() {
   // SetConsoleOutputCP(CP_UTF8); // 콘솔에서 한글이 깨지지 않도록 UTF-8로 설정

    // --- Mopang 로고 출력 시작 ---
    // 색상 코드 정의
    int DARK_BROWN = FOREGROUND_RED | FOREGROUND_GREEN; // 어두운 갈색
    int RED = FOREGROUND_RED;
    int YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;
    int GREEN = FOREGROUND_GREEN;
    int BLUE = FOREGROUND_BLUE;

    std::cout << "\n";

    // 첫 번째 줄
    SetColor(DARK_BROWN, false); std::cout << "##   ##  ";   // M
    SetColor(DARK_BROWN, false); std::cout << " ####   ";    // O
    SetColor(RED);               std::cout << "#####   ";    // P
    SetColor(YELLOW);            std::cout << "  ###   ";    // A
    SetColor(GREEN);             std::cout << "##   ## ";    // N
    SetColor(BLUE);              std::cout << " #####  \n";  // G

    // 두 번째 줄
    SetColor(DARK_BROWN, false); std::cout << "### ###  ";
    SetColor(DARK_BROWN, false); std::cout << "##  ##  ";
    SetColor(RED);               std::cout << "##  ##  ";
    SetColor(YELLOW);            std::cout << " ## ##  ";   // A 두 번째 줄 수정
    SetColor(GREEN);             std::cout << "###  ## ";
    SetColor(BLUE);              std::cout << "##      \n";

    // 세 번째 줄
    SetColor(DARK_BROWN, false); std::cout << "## # ##  ";
    SetColor(DARK_BROWN, false); std::cout << "##  ##  ";
    SetColor(RED);               std::cout << "#####   ";
    SetColor(YELLOW);            std::cout << "## # ## ";   // A 중앙은 일자로
    SetColor(GREEN);             std::cout << "## # ## ";
    SetColor(BLUE);              std::cout << "##  ### \n";

    // 네 번째 줄
    SetColor(DARK_BROWN, false); std::cout << "##   ##  ";
    SetColor(DARK_BROWN, false); std::cout << "##  ##  ";
    SetColor(RED);               std::cout << "##      ";
    SetColor(YELLOW);            std::cout << "##   ## ";   // A 기둥
    SetColor(GREEN);             std::cout << "##  ### ";
    SetColor(BLUE);              std::cout << "##   ## \n";

    // 다섯 번째 줄
    SetColor(DARK_BROWN, false); std::cout << "##   ##  ";
    SetColor(DARK_BROWN, false); std::cout << " ####   ";
    SetColor(RED);               std::cout << "##      ";
    SetColor(YELLOW);            std::cout << "##   ## ";   // A 기둥
    SetColor(GREEN);             std::cout << "##   ## ";
    SetColor(BLUE);              std::cout << " #####  \n";

    // 색상 기본값(흰색) 복구
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    std::cout << "\n로딩중 . . . ";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // --- Mopang 로고 출력 종료 ---

    // 로고 출력 후 콘솔 화면 지우기 (선택 사항)
    system("cls");
    Kiosk myKiosk;

    loadKitchenProducts(myKiosk);
    loadDailysupplies(myKiosk);
    loadsportsProducts(myKiosk);
    loadHealthProducts(myKiosk);
    loadHomeAppDigital(myKiosk);
    loadStationeryProducts(myKiosk);
    loadBook(myKiosk);
    loadFoodProducts(myKiosk);
    
    myKiosk.run();

    return 0;
}