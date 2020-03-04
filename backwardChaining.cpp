//Author: JasonYuan
#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
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
            cout << "                    END of Backward Chaiing Process!" << endl;
            cout << endl;
            return "UND";
        }
    }

    cout << endl;
    cout << "Good News! " << conclusion << " is the Profession for you!" << endl;
    cout << "=========================================" << endl;
    cout << "    END of Backward Chaiing Process!" << endl;
    cout << endl;

    return conclusion;
}
int main()
{
    string profession;

    cout << "backwardChaining!" << endl;

    profession = backwardChaining();

    cout << "profession is :" << profession << endl;
    return 0;
}
