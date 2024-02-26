#include <iostream>

void bookletPrint(int startPage, int endPage) {
    //Tjekker om input er gyldigt
    //Benytter modulus - skal være forskellig fra 1
    //endPage % 4 != 0 søger for at siden rammer det rigtige ark
    if (startPage > endPage || startPage % 4 != 1 || endPage % 4 != 0) {
        std::cout << "Ugyldig input. Angiv venligst en gyldig række af sider." << std::endl;
        return;
    }

    // Beregner det samlede antal ark
    // +1 for at medtage første side 
    // /4 for at se antal ark
    int totalArk = (endPage - startPage + 1) / 4;
    
    //Fra ark 1 gennem alle ark
    for (int arkNummer = 1; arkNummer <= totalArk; ++arkNummer) {
        // Udskriver information om arket og siderne
        std::cout << "Ark " << arkNummer << " indeholder siderne ";

        // Beregner de fire sider på arket
        for (int i = 0; i < 4; ++i) {
            int currentPage = startPage + (arkNummer - 1) * 4 + i;
            std::cout << currentPage;
            
           if (i < 3 && currentPage + 1 <= endPage) {
                std::cout << ", ";
            } else {
                std::cout << "\n";
            }
        }

    }
}