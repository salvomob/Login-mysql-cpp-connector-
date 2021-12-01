***Login using username and password***
>Data will be loaded from the database using mysql query:
> 
>**N.B.**
> 
>**The quaery is relative to "logins" table,created ad HOC,in which there are stored two VARCHAR(255) values : username and password**
> 
>**You are free to modify and create your own version with your own data! This are just the "bones" of a possible connection to a mysql database**
> 
>>make main -> compiles program main.cpp 
>>
>>make main1 -> compiles program main1.cpp
>>
>>make clean -> deletes binary main
>>
>>make clean1 -> deletes binary main1
>>
>>make run -> runs the program main1
>>
>>make run1 -> runs the program main1
>>
>>make mysql_install -> installs mysql client
>>
>>make install -> install all the needed libraries
> 
>WHAT MAIN DOES?
>>Main simply expcets you to write in your data (usnm,pasw) for the application.In main.cpp you MUST write in the connection details!!
>>
>>**N.B.**
>>
>>**You need to modify the source code --> Default user will be loaded otherwise!!**
> 
>WHAT MAIN1 DOES?
>>Main1 simply asks user to type interactively all data
>>
>>**N.B.**
>>
>>**You don't need to modify the source code, ready to use!**
>>
**N.B.**
**Installation is only supported for apt packages(ubuntu based)**
