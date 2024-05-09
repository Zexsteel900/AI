#include <iostream>
#include <string>
using namespace std;

enum class Symptom
{
    None,
    Headache,
    RunnyNose,
    SoreThroat,
    Fever,
    Chills,
    BodyAche,
    AbdominalPain,
    PoorAppetite,
    Rash,
    Conjunctivitis,
    Sweating,
    Nausea,
    Vomiting,
    Diarrhoea
};

bool askSymptom(Symptom symptom, const string &symptomName)
{
    char response;
    cout << "Does the patient have " << symptomName << "? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void diagnoseIllness()
{
    bool headache = askSymptom(Symptom::Headache, "headache");
    bool runnyNose = askSymptom(Symptom::RunnyNose, "runny nose");
    bool soreThroat = askSymptom(Symptom::SoreThroat, "sore throat");
    bool fever = askSymptom(Symptom::Fever, "fever");
    bool chills = askSymptom(Symptom::Chills, "chills");
    bool bodyAche = askSymptom(Symptom::BodyAche, "body ache");
    bool abdominalPain = askSymptom(Symptom::AbdominalPain, "abdominal pain");
    bool poorAppetite = askSymptom(Symptom::PoorAppetite, "poor appetite");
    bool rash = askSymptom(Symptom::Rash, "rash");
    bool conjunctivitis = askSymptom(Symptom::Conjunctivitis, "conjunctivitis");
    bool sweating = askSymptom(Symptom::Sweating, "sweating");
    bool nausea = askSymptom(Symptom::Nausea, "nausea");
    bool vomiting = askSymptom(Symptom::Vomiting, "vomiting");
    bool diarrhoea = askSymptom(Symptom::Diarrhoea, "diarrhoea");

    if (headache && runnyNose && soreThroat && fever && !chills && !bodyAche && !abdominalPain && !poorAppetite)
    {
        cout << "Diagnosis: Common Cold" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Rest" << endl;
        cout << "2: Drink fluids" << endl;
        cout << "3: Take over-the-counter medication for symptoms" << endl;
    }
    else if (soreThroat && fever && headache && chills && bodyAche && !chills && !bodyAche && !soreThroat)
    {
        cout << "Diagnosis: Influenza" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Rest" << endl;
        cout << "2: Drink fluids" << endl;
        cout << "3: Take antiviral medication (consult a doctor)" << endl;
    }
    else if (headache && abdominalPain && poorAppetite && fever && !chills && !bodyAche && !soreThroat)
    {
        cout << "Diagnosis: Typhoid" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Take antibiotics (consult a doctor)" << endl;
        cout << "2: Rest" << endl;
        cout << "3: Drink fluids" << endl;
    }
    else if (rash && bodyAche && fever && !chills && !soreThroat && !headache)
    {
        cout << "Diagnosis: Chicken Pox" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Keep the rash clean and dry" << endl;
        cout << "2: Take over-the-counter medication for itching" << endl;
        cout << "3: Rest" << endl;
    }
    else if (fever && runnyNose && rash && conjunctivitis && !soreThroat && !headache && !chills && !bodyAche)
    {
        cout << "Diagnosis: Measles" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Rest" << endl;
        cout << "2: Drink fluids" << endl;
        cout << "3: Take over-the-counter medication for fever and pain" << endl;
    }
    else if (fever && sweating && headache && nausea && vomiting && diarrhoea && !runnyNose && !soreThroat && !rash)
    {
        cout << "Diagnosis: Malaria" << endl;
        cout << "Advices and Suggestions:" << endl;
        cout << "1: Take antimalarial medication (consult a doctor)" << endl;
        cout << "2: Rest" << endl;
        cout << "3: Drink fluids" << endl;
        cout << "4: Avoid being bitten by mosquitoes" << endl;
    }
    else
    {
        cout << "No diagnosis found.You have CANCER" << endl;
    }
}

int main()
{
    diagnoseIllness();

    return 0;
}
