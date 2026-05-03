Game Position:
    The current games position will be stored in a 2D array of integers.
        0 - no piece there
        1 - bot piece there (i.e an "X")
        2 - user piece is there (i.e. an "O")

    Storing and linking game positions:
        Every single game position can be represented by 2 integers.
            T = the current turn
            P = a position number assigned to every position possible with T number of turns
        P must be assigned  with the move fartheset to the left with one then second farthest with two and so on. 
            For example:
                if T1P1 looks like this: 
                1000000 
                then T2P1 would look like this:
                2000000 
                1000000
                and T2P2 would look like this: 
                1200000
                and T2P3 would look like this:
                1020000
        The positional path or the positions that lead up to a current position can be determined with the following algorithm:
            P = Pₙ/7
            if (P%7 != 0)
                P(ₙ - 1) = P + 1
            else
                P(ₙ - 1) = P
            where n is what turn you're on and P = position.
        To know what move was made in a given position the following equation can be used:
            M = P - 7 * (P/7)
            if (P/7 == 0) M = 7
            where M = move and P = Position
        Knowing the P and T of a position, the range of P for all the possible positions for the subsiquent turn can be calculated.
            L = the range of P that are all the possible next turns position
            P * 7 = the upper bound
            p * 7 - 6 = the lower bound