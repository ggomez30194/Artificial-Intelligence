#include <iostream>



using namespace std;



void forwarChaining(string profession)

{

   if(profession == "Engineering")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Electrical, Mechanical, Civil, Petroleum, and Chemical" << endl;

       cout << endl;

   }



   else if(profession == "Science")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Biology, Physics, Computer Science, Chemistry,";

       cout << " and Animal Science." << endl;

       cout << endl;

   }



   else if(profession == "Business")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Business Management, Marketing, Advertisement, Trading,";

       cout << " and Entrepreneurship" << endl;

       cout << endl;

   }



   else if(profession == "Medical")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Mental Health, Oncologist, Cardiologist, Orthopedic,";

       cout<< " and General practitioner." << endl;

       cout << endl;

   }



   else if(profession == "Applied Arts")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Photography, Design, Visual Communication, Media,";

       cout << " and Fashion." << endl;

       cout << endl;

   }



   else if(profession == "Liberal Arts")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Anthropology, Astronomy, World Literature, Literature,";

       cout << " and Theology," << endl;

       cout << endl;

   }



   else if(profession == "Fine Arts")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Art History, Sculpting, Painting, Music,";

       cout << " and Dance." << endl;

       cout << endl;

   }



   else if(profession == "Communication")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Journalism, Linguistics, Political Science, Speech,";

       cout << " and Editing." << endl;

       cout << endl;

   }



   else if(profession == "Health Care")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Nursing, Health Services Management,";

       cout << " Healthcare Administration, Physician Assistant,";

       cout << " and Public Health." << endl;

       cout << endl;

   }



   else if(profession == "Education")

   {

       cout << "Conclusion:" << endl;

       cout << "Our recommended profession for you is: " << profession << endl;

       cout << "This specific profession getting you to the area:" << endl;

       cout << "Early Childhood, Physical Education, Secondary Education,";

       cout << " Special Education, and Counseling." << endl;

       cout << endl;

   }



}



string backwarChaining()

{



/********************** Conclusion List *****************************/

   string EGR = "Engineering",    //science, designing, problemSolving,

          SCI = "Science",        //science, experiment, calculating,

          BUS = "Business",       //art, communicate, decisionMaking,

          MED = "Medical",        //science, experiment, reporting

          APA = "Applied Arts",   //art, reading, apply,

          LBA = "Liberal Arts",   //art, reading, writing,

          FNA = "Fine Arts",      //art, designing, crafting,

          COM = "Communication",  //art, communicate, speaking,

          HTC = "Health Care",    //science, preparing, nursing,

          EDU = "Education",      //art, preparing, grading,

          UND = "Undecided";      //profession cannot be decided



/*********************** Variable List ******************************/

    bool sci,  //science

         art,  //art

         dsg,  //designing

         pbs,  //problemSolving

         exp,  //experiment

         cal,  //calculating

         com,  //communicate

         des,  //decisionMaking

         rep,  //reporting

         red,  //reading

         app,  //apply

         wrt,  //writing

         dsn,  //designing

         crf,  //crafting,

         org,  //orgnizing,

         prp,  //preparing,

         nrs,  //nursing,

         tch;  //teaching,



    char pChoice;

    string decision;



/************************ prompt interface 1 **************************************/

   cout << "Please tell us which Profession you are interested in below:" << endl;

   cout << "A. " << EGR << endl;

   cout << "B. " << SCI << endl;

   cout << "C. " << BUS << endl;

   cout << "D. " << MED << endl;

   cout << "E. " << APA << endl;

   cout << "F. " << LBA << endl;

   cout << "G. " << FNA << endl;

   cout << "H. " << COM << endl;

   cout << "I. " << HTC << endl;

   cout << "J. " << EDU << endl;

   cin >> pChoice;



/********************** Inference engine **********************/



   /*** Case for Engineering profession ***/

   if(pChoice == 'A' || pChoice == 'a')

   {

       cout << endl;

       cout << "Do you like science ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose an art profession that you may be interested in:" << endl;

          cout << "Business, Applied Arts, Liberal Arts, Communication, Health Care, or Education" << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like designing?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 02 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an science profession doesn't require designing:" << endl;

              cout << "Science, or Medical" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like problem solving?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 03 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Engineering is not recommended, and we have no profession recommendation for you!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 04 **/

              else if(decision == "yes")

              {

                  cout << endl;

                  return EGR;

              }

           }

       }

    }



   /*** case for Science profession ***/

   if(pChoice == 'B' || pChoice == 'b')

   {

       cout << endl;

       cout << "Do you like science ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose an art profession that you may be interested in:" << endl;

          cout << "Business, Applied Arts, Liberal Arts, Communication, Health Care, or Education" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like to experiment?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose a science profession doesn't require experiment:" << endl;

              cout << "Engineering, or Medical" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like problem calculating?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Science is not recommended, but Medical may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return SCI;

              }

           }

       }

    }



    /*** case for Business profession ***/

   if(pChoice == 'C' || pChoice == 'c')

   {

       cout << endl;

       cout << "Do you like Art ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like to communicate?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require communicate:" << endl;

              cout << "Applied Arts, Liberal Arts, Health Care, or Education" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like decision making?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Business is not recommended, but Communication may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return BUS;

              }

           }

       }

    }



   /*** case for Medical profession ***/

   if(pChoice == 'D' || pChoice == 'd')

   {

       cout << endl;

       cout << "Do you like Science? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose an art profession that you may be interested in:" << endl;

          cout << "Business, Applied Arts, Liberal Arts, Communication, Health Care, or Education" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like communicate?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose a science profession doesn't require communicate:" << endl;

              cout << "Engineering, or Science" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like experiment?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Medical is not recommended, but Science may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return MED;

              }

           }

       }

    }



   /*** case for Applied Arts profession ***/

   if(pChoice == 'E' || pChoice == 'e')

   {

       cout << endl;

       cout << "Do you like Art ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like reading?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require reading:" << endl;

              cout << "Business, Communication, Health Care, or Education" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like applying arts to life?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Applied Arts is not recommended, but Liberal Arts may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return APA;

              }

           }

       }

    }



    /*** case for Liberal Arts profession ***/

   if(pChoice == 'F' || pChoice == 'f')

   {

       cout << endl;

       cout << "Do you like Art ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like reading?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require reading:" << endl;

              cout << "Business, Communication, Health Care, or Education" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like writing?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Liberal Arts is not recommended, but Applied Arts may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return LBA;

              }

           }

       }

    }



    /*** case for Fine Arts profession ***/

   if(pChoice == 'G' || pChoice == 'g')

   {

       cout << endl;

       cout << "Do you like Art ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like designing?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require reading:" << endl;

              cout << "Business, Communication, Health Care, or Education" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like crafting?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Fine Arts is not recommended, and we have nothing to recommend!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return FNA;

              }

           }

       }

    }



    /*** case for Communication profession ***/

   if(pChoice == 'H' || pChoice == 'h')

   {

       cout << endl;

       cout << "Do you like Art ? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like to communicate?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require communicate:" << endl;

              cout << "Applied Arts, Liberal Arts, Health Care, or Education" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like organizing?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Communication is not recommended, but Business may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return COM;

              }

           }

       }

    }



   /*** case for Health Care profession ***/

   if(pChoice == 'I' || pChoice == 'i')

   {

       cout << endl;

       cout << "Do you like Art? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like preparing?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require preparing:" << endl;

              cout << "Business, Applied Arts, Liberal Arts, Fine Arts, or Communication" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like nursing?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Health Care is not recommended, but education may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return HTC;

              }

           }

       }

    }



    /*** case for Health Care profession ***/

   if(pChoice == 'J' || pChoice == 'j')

   {

       cout << endl;

       cout << "Do you like Art? (yes/no)" << endl;

       cin >> decision;

       cout << endl;



       /** rule 01 **/

       if(decision == "no")

       {

          cout << "Conclusion:" << endl;

          cout << "Please choose a science profession that you may be interested in:" << endl;

          cout << "Engineering, Science, or Medical" << endl;

          cout << endl;

          return UND;

       }



       else if(decision == "yes")

       {

           cout << "Do you like preparing?" << endl;

           cin >> decision;

           cout << endl;



           /** rule 05 **/

           if(decision == "no")

           {

              cout << "Conclusion:" << endl;

              cout << "Please choose an art profession doesn't require preparing:" << endl;

              cout << "Business, Applied Arts, Liberal Arts, Fine Arts, or Communication" << endl;

              cout << endl;

              return UND;

           }



           else if(decision == "yes")

           {

              cout << "Do you like teaching?" << endl;

              cin >> decision;

              cout << endl;



              /** rule 06 **/

              if(decision == "no")

              {

                  cout << "Conclusion:" << endl;

                  cout << "Education is not recommended, but Health Care may be good for you! Go try it!" << endl;

                  cout << endl;

                  return UND;

              }



              /** rule 07 **/

              else if(decision == "yes")

              {

                  return EDU;

              }

           }

       }

    }

}





int main()

{

    cout << "***********************************************************************" << endl;

    cout << "               ==Welcome to the Career Advising System!==" << endl;

    cout << endl;

    cout << "Please Answer the following questions to help us determine your career." << endl;

    cout << "Please choose an option:" << endl;



    bool end = false;

    char choice;

    string profession;

    while(!end)

    {

        cout << "A. Start Career Advising." << endl;

        cout << "B. Exit the system" << endl;

        cin >> choice;

        cout << endl;



        if(choice == 'A' || choice == 'a')

        {

            profession = backwarChaining();

            forwarChaining(profession);

        }



        else if(choice == 'B' || choice == 'b')

            end = true;



        else

            cout << "ERROR! Invalid input, Please choose again!" << endl;



    }



    return 0;

}
