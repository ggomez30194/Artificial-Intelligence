//Author: JasonYuan
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string backwardChaining()
{
   vector<string> variableList;
   map <string, int> conclusionList;
   map <int, string> knowledgeBase;

   /*** conclusion list ***/

   conclusionList["EGR"] = 10;      //conclusion profession = Engineering   match Rule 10
   conclusionList["SCI"] = 20;      //conclusion profession = Science       match Rule 20
   conclusionList["MED"] = 30;      //conclusion profession = Medical       match Rule 30
   conclusionList["HTC"] = 40;      //conclusion profession = Health Care   match Rule 40
   conclusionList["BUS"] = 50;      //conclusion profession = Business      match Rule 50
   conclusionList["COM"] = 60;      //conclusion profession = Communication match Rule 60
   conclusionList["LBA"] = 70;      //conclusion profession = Liberal Arts  match Rule 70
   conclusionList["APA"] = 80;      //conclusion profession = Applied Arts  match Rule 80
   conclusionList["FNA"] = 90;      //conclusion profession = Fine Arts     match Rule 90
   conclusionList["EDU"] = 100;     //conclusion profession = Education     match Rule 100

   /*** knowledge base ***/

   /** Rule 01 **/
   knowledgeBase[10] = "science = yes AND designing = yes THEN profession = EGR";
   /** Rule 02 **/
   knowledgeBase[20] = "science = yes AND experiment = yes THEN profession = SCI";
   /** Rule 03 **/
   knowledgeBase[30] = "science = yes AND experiment = no THEN profession = MED";
   /** Rule 04 **/
   knowledgeBase[40] = "science = yes AND nursing = yes THEN profession = HTC";
   /** Rule 05 **/
   knowledgeBase[50] = "science = no AND art = yes AND communicate = yes AND decisionMaking = yes THEN profession = BUS";
   /** Rule 06 **/
   knowledgeBase[60] = "science = no AND art = yes AND communicate = yes AND decisionMaking = no THEN profession = COM";
   /** Rule 07 **/
   knowledgeBase[70] = "science = no AND art = yes AND reading = yes AND writing = yes THEN profession = LBA";
   /** Rule 08 **/
   knowledgeBase[80] = "science = no AND art = yes AND reading = yes AND writing = no THEN profession = APA";
   /** Rule 09 **/
   knowledgeBase[90] = "science = no AND art = yes AND reading = no AND crafting = yes THEN profession = FNA";
   /** Rule 10 **/
   knowledgeBase[100] = "science = no AND art = yes AND grading = yes THEN profession = EDU";

   //Inference Engine
   bool checkInput = false;
    char pChoice;
    int ruleNum;
    string conclusion,
           tempstr,
           iChoice;
    vector<string> variables;

    /*** prompt interface 1 ***/
    //prompt the conclusion first
    while(!checkInput)
    {
        cout << "Please tell us which Profession you are interested in below:" << endl;
        cout << "A. Engineering   (EGR)" << endl;
        cout << "B. Science       (SCI)" << endl;
        cout << "C. Medical       (MED)" << endl;
        cout << "D. Health Care   (HTC)" << endl;
        cout << "E. Business      (BUS)"<< endl;
        cout << "F. Communication (COM)" << endl;
        cout << "G. Liberal Arts  (LBA)" << endl;
        cout << "H. Applied Arts  (APA)" << endl;
        cout << "I. Fine Arts     (FNA)" << endl;
        cout << "J. Education     (EDU)" << endl;
        cin >> pChoice;

        if(pChoice == 'a' || pChoice == 'A')
        {
            conclusion = "EGR";
            checkInput = true;
        }
        else if(pChoice == 'b' || pChoice == 'B')
        {
            conclusion = "SCI";
            checkInput = true;
        }
        else if(pChoice == 'c' || pChoice == 'C')
        {
            conclusion = "MED";
            checkInput = true;
        }
        else if(pChoice == 'd' || pChoice == 'D')
        {
            conclusion = "HTC";
            checkInput = true;
        }
        else if(pChoice == 'e' || pChoice == 'E')
        {
            conclusion = "BUS";
            checkInput = true;
        }
        else if(pChoice == 'f' || pChoice == 'F')
        {
            conclusion = "COM";
            checkInput = true;
        }
        else if(pChoice == 'g' || pChoice == 'G')
        {
            conclusion = "LBA";
            checkInput = true;
        }
        else if(pChoice == 'h' || pChoice == 'H')
        {
            conclusion = "APA";
            checkInput = true;
        }
        else if(pChoice == 'i' || pChoice == 'I')
        {
            conclusion = "FNA";
            checkInput = true;
        }
        else if(pChoice == 'j' || pChoice == 'J')
        {
            conclusion = "EDU";
            checkInput = true;
        }
        else
            cout << "ERROR! Invalid input, Please choose again!" << endl;
    }

    ruleNum = conclusionList[conclusion];
    tempstr = knowledgeBase[ruleNum];

    vector<string> conditionListV;
    vector<string> variableListV;

    size_t position = 0;
    string target;

    tempstr.erase(remove_if(tempstr.begin(), tempstr.end(), ::isspace),tempstr.end());

    while((position = tempstr.find("AND")) != tempstr.npos)
    {
       target = tempstr.substr(0, position);
       conditionListV.push_back(target);
       tempstr.erase(0, position + 3);
    }

    if((position = tempstr.find("THEN")) != tempstr.npos)
    {
       target = tempstr.substr(0, position);
       conditionListV.push_back(target);
       tempstr.erase(0, position + 4);

       conditionListV.push_back(tempstr);
    }

    for(int i = 0; i < conditionListV.size(); i++)
    {
       if((position = conditionListV[i].find("=")) != conditionListV[i].npos)
       {
           target = conditionListV[i].substr(0, position);
           variableListV.push_back(target);
           conditionListV[i].erase(0, position + 1);

           variableListV.push_back(conditionListV[i]);
       }
    }

    variables = variableListV;

    for(int i = 0; i < (variables.size() - 2) ; i += 2)
    {
        cout << "Are you interested in " << variables[i] << "? (yes/no)" << endl;
        cin >> iChoice;

        if(iChoice != variables[i + 1])
        {
            cout << endl;
            cout << conclusion << " is NOT the right Profession for you! Please choose another Profession!" << endl;
            cout << "==========================================================================" << endl;
            cout << "                    END of Backward Chaining Process!" << endl;
            cout << endl;
            return "UND";
        }
    }

    cout << endl;
    cout << "Good News! " << conclusion << " is the Profession for you!" << endl;
    cout << "=========================================" << endl;
    cout << "    END of Backward Chaining Process!" << endl;
    cout << endl;

    return conclusion;
}

string forwardChaining(string profession)
{
    string returnMessage = "";
    bool noArea = false;
    map <string, string> questionList;
    vector<string> variableList;
    vector<string> ifthenKnowledgeBase;
    vector<string> professionList;
    vector<string> areaList;
    map <string, int> conclusionList;
    map <int, string> knowledgeBase;
    map<int, string> clsVariableList;
    map<string, string> recommendation;
    queue <string> conclusionQueue;
    stack <int> conclusionStack;

    const int MAX_CLAUSE_VAR = 2;
    const int TOTAL_CLAUSE_NUM = 200;

    ifstream fin;
    ofstream fout;
    string line;
    fin.open("FC_KnowledgeBase.txt");
    fout.open("results.txt");
    while (fin >> line)
    {
        cout << line << endl;
        ifthenKnowledgeBase.push_back(line);
    }

    int knowbaseRuleNo = 10;
    for(string rule : ifthenKnowledgeBase)
    {
        knowledgeBase[knowbaseRuleNo] = rule;
        knowbaseRuleNo += 10;
    }

    for(auto const& [ruleno, rule] : knowledgeBase ) {
        cout << ruleno << " : " << rule << endl;
        int clIndex = (MAX_CLAUSE_VAR_COUNTFC * (ruleno / 10 - 1)) + 1;

        vector<string> splitted =  split(rule, " AND ", "THEN ");
        for(int i = 0; i < splitted.size(); i++) // ommit the then part.
        {
            vector<string> variables = split(splitted[i], " = "," ");
            removeWhiteSpace(variables[1]);
            removeWhiteSpace(variables[0]);
            if(i == 0)
            {
                professionList.push_back(variables[1]);
            }
            else if(i == 1)
            {
                areaList.push_back(variables[1]);
            }

             // assign variables to  clause variable list
            clsVariableList[clIndex] = variables[0];
            clIndex++;
        }
    }

    createQuestionList(questionList);
    createRecomendations(recommendation);

    fout << "Displaying Knowledgebase: " << endl << endl;

    for (auto const& [ruleno, rule] : knowledgeBase) {
        fout << ruleno << ": " << rule << endl;
    }

    fout << endl << endl;

    fout << "Displaying clause variable list: " << endl << endl;

    for (auto const& [clauseno, variable] : clsVariableList) {
        fout << clauseno, << ": " << variable << endl;
    }

    fout.close();

    cout << endl << endl;
    cout << "=============================" << endl;
    cout << "Forward Chaining process" << endl;

    cout << "You have chosen the profession of " << profession << endl;

    conclusionQueue.push("PROFESSION");

    variableList.clear();
    variableList["PROFESSION"] = profession;

    while (!conclusionQueue.empty())
    {
        string fcValue = conclusionQueue.front();
        int ruleno;
        for (auto const& [clsNumber, clsVariable] : clsVariableList)
        {
            if (clsVariable == fcValue)
            {
                ruleno = ((clcNumber / MAX_CLAUSE_VAR) + 1) * 10;

                string rule = knowledgeBase[ruleno];
                vector<string> splitted = split(rule, " AND ", "THEN ");

                vector<string> variables = split(splitted[0], " = ". " ");
                vector<string> areas = split(splitted[1], " = "," ");
                removeWhiteSpace(variables[0]);
                removeWhiteSpace(variables[1]);

                removeWhiteSpace(areas[0]);
                removeWhiteSpace(areas[1]);

                if (variables[1] == variableList[fcValue] && variables[0] == fcValue)
                {
                    vector<string> areaListTemp;
                    if (variableList[areas[0]] == "")
                    {
                        for (int i = 0; i < professionList.size(); i++)
                        {
                            if (variableList[variables[0]] == professionList[i])
                            {
                               areaListTemp.push_back(areaList[i]);
                            }
                        }

                        int i = 0;
                        bool result;
                        string areasVal;
                        do {
                            areasVal = areaListTemp[i];
                            result = askQuestion(areasVal, variableList, questionList, true);
                            i++;
                        } while ((i < areaListTemp.size()) && result);

                        if(!result)
                        {
                            variableList[areas[0]] = areasVal;
                            conclusionQueue.push(areas[0]);
                            break;
                        } else
                        {
                            returnMessage = "Sorry we cannot recommend an Area!";
                            noArea = true;
                            break;
                        }
                    }
                }
            }
            if (clsVariable == "")
            {
                break;
            }
        }
        conclusionQueue.pop();
    }

    if (!noArea)
    {
        cout << endl << endl;
        cout << "=========================================" << endl;
        cout << "\t\t\tRESULTS" << endl << endl;

        vector<string> resultFC;
        for (auto const& [var, value] : variableList)
        {
            resultFC.push_back(value);
        }
        for (auto const& [ruleno, rule] : knowledgeBase)
        {
            vector<string> splitted = split(rule, " AND ", "THEN ");

            vector<string> variablesIFF = split(splitted[0], " = "," "); // get the first part of If
            vector<string> variablesIFS = split(splitted[1], " = "," "); // get the second part after and
            vector<string> variablesRes = split(splitted[2], " = "," "); // get the then part
            removeWhiteSpace(variablesIFF[1]);  removeWhiteSpace(variablesIFF[0]);
            removeWhiteSpace(variablesIFS[1]);  removeWhiteSpace(variablesIFS[0]);
            removeWhiteSpace(variablesRes[1]);  removeWhiteSpace(variablesRes[0]);

            if (variablesIFF[1] == resultFC[0] && variablesIFS[1] == resultFC[1])
            {
                cout << recommendation[variablesRes[1]] << endl;
            }
        }
    }
    else
    {
        cout << returnMessage << endl;
        return returnMessage;
    }
}

void createQuestionList(map <string, string> &questionList)
{
        questionList["ELECTRICAL"] = "Do you like circuits and electronics?";
        questionList["MECHANICAL"] = "Do you like working with machines?";
        questionList["CIVIL"] = "Do you like construction and buildings?";
        questionList["PETROLUEM"] = "Do you like the gas and oil industry?";
        questionList["CHEMICAL"] = "Do you like working with chemicals?";
        questionList["BIOLOGY"] = "Are you interested in the study of living organisms?";
        questionList["PHYSICS"] = "Are you interested in the physical world and how it works?";
        questionList["COMPUTER"] = "Do you like computers?";
        questionList["CHEMISTRY"] = "Are you interested in the substances in which things are made?";
        questionList["ANIMAL"] = "Are you interested in livestock?";
        questionList["MENTAL"] = "Are you interested in the human mind?";
        questionList["ONCOLOGY"] = "Do you want to cure cancer cells?";
        questionList["CARDIOLOGY"] = "Are you interested in the human heart?";
        questionList["ORTHOPEDIC"] = "Are you interested in the human musculoskeletal system?";
        questionList["GENERAL"] = "Are you interested in general care and chronic illnesses?";
        questionList["NURSING"] = "Do you like caring for the sick?";
        questionList["MANAGEMENT"] = "Are you interested in managing medical services?";
        questionList["ADMIN"] = "Do you want to be in an executive medical position?";
        questionList["ASSISTANT"] = "Are you interested in examining patients and prescriptions?";
        questionList["PUBLIC"] = "Are you interested in protecting the health of the general public?";
        questionList["BIZMANAGE"] = "Would you like to run a business one day?";
        questionList["MARKET"] = "Do you like the research of how to sell products?";
        questionList["ADVERTISE"] = "Do you want to promote products?";
        questionList["TRADING"] = "Do you want to buy sell goods internationally?";
        questionList["ENTREPRENEUR"] = "Do you want to create new businesses?";
        questionList["JOURNAL"] = "Do you like researching, investigating, interviewing, reporting and writing?";
        questionList["LANGUAGE"] = "Are you interested in language?";
        questionList["POLITICS"] = "Are you interested in politics";
        questionList["SPEECH"] = "Are you interested speech?";
        questionList["EDITING"] = "Do you like editing?";
        questionList["ANTHROPOLOGY"] = "Do you like the natural sciences?";
        questionList["ASTRONOMY"] = "Do you like space?";
        questionList["WORLDLIT"] = "Do you like world literature?";
        questionList["LITERATURE"] = "Do you like English writing?";
        questionList["THEOLOGY"] = "Do you like to study about religions?";
        questionList["PHOTOGRAPHY"] = "Do you like taking pictures?";
        questionList["DESIGN"] = "Do you like creating design?";
        questionList["VISUALCOMM"] = "Do you like visuals?";
        questionList["MEDIA"] = "Do you like to work with television?";
        questionList["FASHION"] = "Do you like to be a fashion designer?";
        questionList["ARTHISTORY"] = "Do you like to study about art?";
        questionList["SCULPTING"] = "Are you interested in sculpting?";
        questionList["PAINTING"] = "Are you interested in painting?";
        questionList["MUSIC"] = "Are you interested in music?";
        questionList["DANCING"] = "Are you interested in dance?";
        questionList["CHILDHOOD"] = "Do you like to be involved in elementary school?";
        questionList["PHYSICALED"] = "Do you like to be involved in teaching gym?";
        questionList["SECONDARYED"] = "Do you like to be involved in college?";
        questionList["SPECIAL"] = "Do you like prepare students for a career?";
        questionList["COUNSELING"] = "Do you like to provide professional services to families?";
}

void createRecomendations(map <string, string> &recommendation) {
        recommendation["ELECT"] = "You should try Electrical Engineering";
        recommendation["MECH"] = "You should try Mechanical Engineering";
        recommendation["CIV"] = "You should try Civil Engineering";
        recommendation["PETRO"] = "You should try Petroleum Engineering";
        recommendation["CHEM"] = "You should try Chemical Engineering";
        recommendation["BIO"] = "You should try Biology";
        recommendation["PHY"] = "You should try Physics";
        recommendation["COMP"] = "You should try Computer Science";
        recommendation["CHEMI"] = "You should try Chemistry";
        recommendation["ANI"] = "You should try Animal Science";
        recommendation["MENT"] = "You should try Mental Health";
        recommendation["ONCO"] = "You should try Oncology";
        recommendation["CARDIO"] = "You should try Cardiology";
        recommendation["ORTHO"] = "You should try Orthopedics";
        recommendation["GEN"] = "You should try General Practition";
        recommendation["NURSE"] = "You should try Nursing";
        recommendation["HSMAN"] = "You should try Health Service Management";
        recommendation["HADM"] = "You should try Health Administration";
        recommendation["ASSIS"] = "You should try Nurse Assistant";
        recommendation["PUBH"] = "You should try Public Health";
        recommendation["BSMAN"] = "You should try Business Management";
        recommendation["MARK"] = "You should try Marketing";
        recommendation["ADV"] = "You should try Advertisement";
        recommendation["TRADE"] = "You should try Trading";
        recommendation["ENTRE"] = "You should try Entrepreneurship";
        recommendation["JOUR"] = "You should try Journalism";
        recommendation["LING"] = "You should try Linguistics";
        recommendation["POLI"] = "You should try Political Science";
        recommendation["SPCH"] = "You should try Speech";
        recommendation["EDIT"] = "You should try Editing";
        recommendation["ANTH"] = "You should try Anthropology";
        recommendation["ASTRO"] = "You should try Astronomy";
        recommendation["WLIT"] = "You should try World Literature";
        recommendation["LITER"] = "You should try Literature";
        recommendation["THEO"] = "You should try Theology";
        recommendation["PHOTO"] = "You should try Photography";
        recommendation["DESI"] = "You should try Designing";
        recommendation["VCOMM"] = "You should try Visual Communication";
        recommendation["MUS"] = "You should try Music";
        recommendation["FASH"] = "You should try Fashion";
        recommendation["ARTH"] = "You should try Art History";
        recommendation["SCULPT"] = "You should try Sculpting";
        recommendation["PAINT"] = "You should try Painting";
        recommendation["MUSIC"] = "You should try Music";
        recommendation["DANCE"] = "You should try Dancing";
        recommendation["CHILD"] = "You should try Child Development";
        recommendation["PHYS"] = "You should try Physical Education";
        recommendation["SECON"] = "You should try Secondary School"
        recommendation["SPECED"] = "You should try Special Education";
        recommendation["COUN"] = "You should try Counseling";

}

bool askQuestion(string clauseVariable, vector<string> &variableList, map <string, string> &questionList, bool FC)
{
    bool escape = false;
    string varDeclare = "";

    do {
        char answer;
         cout << questionList[clauseVariable] << " press (Y/N) and then Enter: ";
         cin >> answer;
         cout << endl;

         switch (answer)
         {
            case 'y':
            case 'Y':
                escape = true;
                varDeclare = "YES";
                break;
            case 'n':
            case 'N':
                escape = true;
                varDeclare = "NO";
                break;
            defualt:
                cout << "Error: Wrong input!" << endl;
                break;
         }
    } while (!escape);
    if (!FC) variableList[clauseVariable] = varDeclare;
    if (varDeclare == "Yes")
    {
        return true;
    } else
    {
        return false;
    }
}

vector<string> split(string s, string delimiter, string delimiter2)
{
    vector<string> splittedStringl
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        splittedString.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    if(delimiter2.length() > 0)
    {
        while ((pos = s.find(delimiter2)) != string::npos) {
            token = s.substr(0, pos);
            splittedString.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        splittedString.push_back(s);
    }

    return splittedString;
}

void removeWhiteSpace(string &str)
{
    string test = str;
    test.erase(remove(test.begin(), test.end(), ' '), test.end());
    str = test;
}

int main()
{
    string profession;
    string area;

    cout << "backwardChaining!" << endl;

    profession = backwardChaining();

    cout << "profession is :" << profession << endl;

    cout << "Now to Forward Chaining!" << endl;

    area = forwardChaining(profession);

    return 0;
}
