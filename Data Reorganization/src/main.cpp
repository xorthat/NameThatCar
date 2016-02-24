#include <iostream>
#include <array>
#include <fstream>

enum CarMake {
    Am_General, Acura, Aston_Martin, Audi, Bentley, BMW, Bugatti, Buick, Cadillac, Chevrolet, Chrysler,
    Daewoo, Dodge, Eagle_Talon, Fiat, Ferrari, Fisker, Ford, Gmc, Geo, Honda, Hummer, Hyundai, Infiniti, Isuzu,
    Jaguar, Jeep, Lamborghini, Land_Rover, Lincoln, Mini, Maybach, Mazda, McLauren, Mercedes_Benz, Mitsubishi, Nissan,
    Plymouth, Porsche, Ram, Rolls_Royce, Scion, Smart, Spyker, Suzuki, Tesla, Toyota, Volkswagon, Volvo
};


using namespace std;

//Prototypes
void createNewFileFromOldFile(string, string);

CarMake convertToNewCategory(const int);

int main() {
    try {
        createNewFileFromOldFile("train_perfect_preds_org.txt", "train_perfect_preds_new.txt");
    }
    catch (exception e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void createNewFileFromOldFile(string oldFileName, string newFileName) {
    ifstream oldFile(oldFileName);
    ofstream newFile;
    string line;
    int oldValue, newValue;
    newFile.open(newFileName);
    while (getline(oldFile, line)) {
        oldValue = stoi(line);
        newValue = convertToNewCategory(oldValue);
        newFile << newValue << '\n';
    }
    newFile.close();
    oldFile.close();
}

CarMake convertToNewCategory(const int oldCategory) {
    if (oldCategory < 1) {
        string message = "oldCategory is too small";
        throw out_of_range(message);
    }
    else if (oldCategory == 1)
        return Am_General;
    else if (oldCategory <= 7)
        return Acura;
    else if (oldCategory <= 11)
        return Aston_Martin;
    else if (oldCategory <= 25)
        return Audi;
    else if (oldCategory <= 38)
        return BMW;
    else if (oldCategory <= 44)
        return Bentley;
    else if (oldCategory <= 46)
        return Bugatti;
    else if (oldCategory <= 50)
        return Buick;
    else if (oldCategory <= 53)
        return Cadillac;
    else if (oldCategory <= 75)
        return Chevrolet;
    else if (oldCategory <= 81)
        return Chrysler;
    else if (oldCategory <= 81)
        return Daewoo;
    else if (oldCategory <= 97)
        return Dodge;
    else if (oldCategory <= 98)
        return Eagle_Talon;
    else if (oldCategory <= 100)
        return Fiat;
    else if (oldCategory <= 104)
        return Ferrari;
    else if (oldCategory <= 105)
        return Fisker;
    else if (oldCategory <= 117)
        return Ford;
    else if (oldCategory <= 122)
        return Gmc;
    else if (oldCategory <= 123)
        return Geo;
    else if (oldCategory <= 125)
        return Hummer;
    else if (oldCategory <= 129)
        return Honda;
    else if (oldCategory <= 140)
        return Hyundai;
    else if (oldCategory <= 142)
        return Infiniti;
    else if (oldCategory <= 143)
        return Isuzu;
    else if (oldCategory <= 144)
        return Jaguar;
    else if (oldCategory <= 149)
        return Jeep;
    else if (oldCategory <= 153)
        return Lamborghini;
    else if (oldCategory <= 155)
        return Land_Rover;
    else if (oldCategory <= 156)
        return Lincoln;
    else if (oldCategory <= 157)
        return Mini;
    else if (oldCategory <= 158)
        return Maybach;
    else if (oldCategory <= 159)
        return Mazda;
    else if (oldCategory <= 160)
        return McLauren;
    else if (oldCategory <= 166)
        return Mercedes_Benz;
    else if (oldCategory <= 167)
        return Mitsubishi;
    else if (oldCategory <= 171)
        return Nissan;
    else if (oldCategory <= 172)
        return Plymouth;
    else if (oldCategory <= 173)
        return Porsche;
    else if (oldCategory <= 174)
        return Ram;
    else if (oldCategory <= 177)
        return Rolls_Royce;
    else if (oldCategory <= 178)
        return Scion;
    else if (oldCategory <= 180)
        return Spyker;
    else if (oldCategory <= 184)
        return Suzuki;
    else if (oldCategory <= 185)
        return Tesla;
    else if (oldCategory <= 189)
        return Toyota;
    else if (oldCategory <= 192)
        return Volkswagon;
    else if (oldCategory <= 195)
        return Volvo;
    else if (oldCategory == 196)
        return Smart;
    else {
        string message = "oldCategory is too large";
        throw out_of_range(message);
    }
}