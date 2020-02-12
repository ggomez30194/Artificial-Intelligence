# Purpose: Find MAJOR

# Methods: 
* Backward Chaining :  To determine the "Profession"
* Forward Chaining : To recommend a specific "Area" by using "Profession" //Profession --> Area

# Knowledge base:

* Profession(10) : Engineering, Science, Business, Medical, Applied Arts, Liberal Arts, Fine Arts, Communications, Health Care, Education.

* Area(...) : Electrical, Mechanical, Civil, Petroleum, Chemical...
              Mental health, Oncologist, Cardiologist, General practitioner...
              Nursing, Health Services Management, Healthcare Administraion, Pysician Assistant, Public Health...

* Rule 01 : 
           
           1 Profession should at LEAST support 5 Areas!  //Profession(1) ---> Area(5)

      etc: Profession      --->      Area                
           Engineering     --->      Electrical, Mechanical, Civil, Petroleum, Chemical...
           Medical         --->      Mental Health, Oncologist, Cardiologist, General practitioner...
           Health Care     --->      Nursing, Health Services Management, Healthcare Administraion, Pysician Assistant, Public Health...
       
* Rule 02 : 
            
            FIRST....User will response to Prompts from the SYSTEM
            // Prompt ---> Response
            
            SECOND...Based on Response, System first advise the Profession, second specify Areas in the Profession 
            // Response ---> Profession ---> Area
            
* Rule 03 : 

            After collecting Knowlege, Generate 2 Decision Trees:
            Decision Tree 1 (Backward Chaining) // advice Profession
            Decision Tree 2 (Forward Chaining) // advice Area based on Profession
            
* Rule 04 :
            
            Should have total at least 50 rules in both forward/backward chaining          
