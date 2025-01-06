#pragma once

bool UpperOrNot(std::string Case) { 
    bool upper = false;
    std::string bagOfUpperCase[36] = {"up", "uP", "Up", "UP", "upper", "uppeR", "uppEr", "uppER", "upPer", "upPeR", "upPEr", "upPER", 
                                      "uPper", "uPpeR", "uPpEr", "uPpER", "uPPer", "uPPeR", "uPPEr", "uPPER", "Upper", "UppeR", "UppEr", "UppER", 
                                      "UpPer", "UpPeR", "UpPEr", "UpPER", "UPper", "UPpeR", "UPpEr", "UPpER", "UPPer", "UPPeR", "UPPEr", "UPPER"};                                   

    for(int i = 0; i < 36; i++) {
        if (bagOfUpperCase[i] == Case) {
            upper = true;
            return upper;
        }
    }

return upper;
}

bool LowerOrNot(std::string Case) {
    bool lower = false;
    std::string bagOfLowerCase[48] = {"down", "dowN", "doWn", "doWN", "dOwn", "dOwN", "dOWn", "dOWN", "Down", "DowN", "DoWn", "DoWN",
                                      "DOwn", "DOwN", "DOWn","DOWN", "lower", "loweR", "lowEr", "lowER", "loWer", "loWeR", "loWEr", "loWER", "lOwer", 
                                      "lOweR", "lOwEr", "lOwER", "lOWer", "lOWeR", "lOWEr", "lOWER", "Lower", "LoweR", "LowEr", "LowER",
                                      "LoWer", "LoWeR", "LoWEr", "LoWER", "LOwer", "LOweR", "LOwEr", "LOwER", "LOWer", "LOWeR", "LOWEr", "LOWER"};
    
    for(int i = 0; i < 48; i++) {
        if (bagOfLowerCase[i] == Case) {
            lower = true;
            return lower;
        }
    }

return lower;
}

std::string UpperToLower(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // 'A'(65) + 32 = 'a'(97)
        }
    }
    return str;    
}

std::string LowerToUpper(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // 'a'(97) - 32 = 'A'(65)
        }
    }
    return str;
}