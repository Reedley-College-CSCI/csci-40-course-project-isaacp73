[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ay551EX-)
# CS1 Final Project - Connect-Four, Terminal Eddition

## 1. Overview
- The following project is a solutions to a common problem: boredom. It is a simple game that can be played directly in the terminal. 
- It can be played with a friend or alone against a bot. 
- The game is based on the popular game Conect-Four. 
- It saves every players name as well as how many wins they have against the bot or another player. This data can then be viewed by a user as leader boards. 

---

## 2. Design Decisions
- In order to deal with players' data, a struct called PlayerData was used. It has two unsigned integer members and a string member. 
    - The two integers store player and bot wins respectivly and the string member stores the players name.
    - When sorting or searching the data file all the data is stored in a dynamacly allocated array of PlayerData type. Using a struct keeps each players data points together and makes that process easier.
- All player data is stored in a data text file called playerData.txt.
- The bot uses a struct called MoveSequence to keep track of move sequence data. The struct has a integer type member and a boolian array with 7 elaments.
    - The bot performs an algorithm in the compute function that finds a sequance of moves
    that lead it to a win. This move sequance is stored in a dynamacly allocated array of MoveSquence structs.
    - The boolian array in the struct is used to keep track of ilegal moves. If a move is found to be ilegal the corrisponding index in the boolian array is set to true so that the compute function knows to skip it as it comes back around.
- Binary searches are used in dealing with player data. It is used to find a player in the data file to update their win data or to retreave it.
- Less obviously, the algorithm the bot uses to find a win position works similarly to a linear search. It makes every possible move one by one until it finds a desired position.
- Selection sort is used in the sortData function in the PlayerData object to sort the data file.
- The alternative option to the bot was to simply save win positions in files and find them in the files. The program to find and save the win positions are in the directory called Create win data files and the function stub checkFiles is in the Bot object source files. 
    - The reason this approach was scrapped was due to restrictions in time. Due to the exponential nature of the game. The more turns ahead you search the more possible positions exist. To search about two thirds of the position just 10 turns in took a week+. It would be unpractical to do that all the way till 42 turns which is the max number of turns in the game possible. Instead searching in the moment based on the current position works much better.
- Before the design used now the bot had two similar design iterations that had some issues and challenges.
    - The first idea was to use the position numbering system used in the file creation. The details of that system are in the README text file in the Create win data files directory.
        - The challenge with this design was to keep track of what position number the board was at. So instead of using a universal numbering system, a relative one was the next option but that had issues too. 
    - The second idea was to use the current board position as the root position and from there the same search algorithm from the file generation could be used. This eliminated the need to keep track of the universal position number for the board, but this didn't work either because what it didn't acount for:
        - Ilegal moves. The system does not generate actual board positions but move sequances that can create a theoretical board position but ilegal moves can slip through causing logic erros.
    - So, the current win search method was created instead. The current method actually performs the move sequance on a copy of the board and keeps track of and skips ilegal moves.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

---

## 4. Technical Walkthrough
1. Prompts user for single or two player and an option to see the leader boards or close the program
2. Enters mode the user input or closes or displays the leader boards and reprompt the user.
3. The game board is printed as ascii art in both modes. It is a grid with an 'x' or 'O' representing the game pieces. 
4. At the bottom is the players name. In two player this will indicate who's turn it is.
5. Users will enter their move as an integer 1-7 to represent what coloumn they want to make their move in then hit enter.
6. In both modes the program will reprint the users name if they make an invalid input.
7. In bot mode the board will be updated with the players move and add the bots move and repromt the player for their move. In two player it will reprint the board with the players move and promt the other player for their move with their name.
8. Once the game is over and a user or the bot has won, a sill message will be printed and will start again at the top.
- Live example: https://youtu.be/IT3_PpIR1RI

---

## 5. Challenges and Lessons Learned
- Challenges:
    - The biggest challenge in this progect was having to redesign the bot multiple times. It involved the most mential work and the most mential focus.
    - Debugging was a big source of frustration. A few minor typos flew under the radar creating several bugs and logic errors that were increadanly frustrating to find. Frustratingly, a lot of time was wasted looking and redesigning perfictally functional code due to a simple typo somewhere hidden.

- Take aways:
    - Its a lot easier to rewrite sudo-code than it is actual code so write it first.
        - A lot of functions had to be refactured later in the process as the design progressed which created a lot of extra work, but if that all took place in sudo-code beforehand it would have gone a lot smoother. 
        - With the design as you go approach often times you have to work backwards and rewrite functions as you realize the needs are slightly diffrent than what was originally thought but if it was designed at the start the code is able to be optimized for exactly what is needed from the begining instead of having to either completly rewrite an entire function or figure out how to make what is there work.
    - Document more and incorporate it into to the process. Don't save it for the end.

---

## 6. Future Improvements
- In the current state the bot looses a lot. It has no sense of a move that allows the player to win on their next turn In order to avoid making moves like that finding player wins and adding logic that will avoid that position can be added.
- Exploring the first idea again might be interesting or some how combining the two ideas. The first step would be to figure out methods to optimize the searching or figure out if there is a pattern in the win positions that can be used to calculate all of them without having to search every position. 
