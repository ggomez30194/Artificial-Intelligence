# Purpose: Find MAJOR

# Methods: 
* Backward Chaining :  To determine the "Profession"
* Forward Chaining : To recommend a specific "Area" by using "Profession" //Profession --> Area

# Knowledge base:

* Profession(10) : 

              Engineering, Science, Business, Medical, Applied Arts, Liberal Arts, Fine Arts, Communications, Health Care, Education.

* Area(...) : 

              Electrical, Mechanical, Civil, Petroleum, Chemical
              Mental Health, Oncologist, Cardiologist, General Practitioner, Orthopedic
              Nursing, Health Services Management, Healthcare Administration, Physician Assistant, Public Health
              Biology, Physics, Computer Science, Chemistry, Animal Science
              Business Management, Marketing, Advertisement, Trading, Entrepreneurship
              Photography, Design, Visual Communication, Media, Fashion
              Anthropology, Astronomy, World Literature, Literature, Theology
              Art History, Sculpting, Painting, Music, Dance
              Journalism, Linguistics, Political Science, Speech, Editing
              Early Childhood, Physical Education, Secondary Education, Special Education, Counseling
              

* Rule 01 : 
           
           1 Profession should at LEAST support 5 Areas!  //Profession(1) ---> Area(5)

      etc: Profession      --->      Area                
           Engineering     --->      Electrical, Mechanical, Civil, Petroleum, Chemical
           Medical         --->      Mental Health, Oncologist, Cardiologist, Orthopedic, General practitioner
           Health Care     --->      Nursing, Health Services Management, Healthcare Administration, Physician Assistant, Public Health
           Science         --->      Biology, Physics, Computer Science, Chemistry, Animal Science
           Business        --->      Business Management, Marketing, Advertisement, Trading, Entrepreneurship
           Applied Arts    --->      Photography, Design, Visual Communication, Media, Fashion
           Liberal Arts    --->      Anthropology, Astronomy, World Literature, Literature, Theology
           Fine Arts       --->      Art History, Sculpting, Painting, Music, Dance
           Communication   --->      Journalism, Linguistics, Political Science, Speech, Editing
           Education       --->      Early Childhood, Physical Education, Secondary Education, Special Education, Counseling
       
* Rule 02 : 
            
            FIRST....User will response to Prompts from the SYSTEM
            // Prompt ---> Response
            
            SECOND...Based on Response, System first advise the Profession, second specify Areas in the Profession 
            // Response ---> Profession ---> Area
            
* Rule 03 : 

            After collecting Knowlege, Generate 2 Decision Trees:
            Decision Tree 1 (Backward Chaining) // advice Profession
            Decision Tree 2 (Forward Chaining) // advice Area based on Profession
            
* Rule 04 :Programing details
            
            1.Should have total at least 50 rules in both forward/backward chaining
            2.Run the program with the rules for minimum of 5 students
            3.Print the intermediate results to trace your program
            4.Write his/her REPORT containing the explanation of the problem and the domain, decision tree, rules, methodologies used (Backward and Forward), the program, detailed explanations of the modifications to the program you implemented, and the analysis of the program and the analyses of results as defined in item #3 above. Also, clearly identify the contribution of each team member.
            5.To run your programs, downloads your Files with full instructions to run your programs. Warning: EACH STUDENT MUST PERFORM STEPS 1 TO 5 INDIVIDUALLY. DO NOT COPY PROGRAMS FROM ANY SOURCE EXCEPT THE PROGRAMS I HAVE PROVIDED THROUGH TRACS. ALSO, DO NOT COPY REPORT FROM YOUR PARTNER OR ANY OTHER PERSON.
            6.main function will call other two functions
            
